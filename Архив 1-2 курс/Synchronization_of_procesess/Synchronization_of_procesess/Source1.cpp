#include "windows.h"
#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>


using namespace std;

semaphore semaphore1;
int padding = 0;
int semaphoreI = 0;

void Worker(const string& num) {
    cout << "Поток " << num << " начался и ожидает семафор." << endl;
    semaphore1.acquire();
    int localPadding = padding += 100;
    cout << "Поток " << num << " захватывает семафор." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000 + localPadding));
    cout << "Поток " << num << " в семафоре." << endl;
    cout << "Переменная семафора равна: " << semaphoreI << ". Поток " << num << " выходит из семафора." << endl;
    semaphore1.release();
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    thread a(Worker, "'A'");
    semaphore1.acquire();
    a.detach();
    this_thread::sleep_for(chrono::milliseconds(500));
    semaphore1.release();
    this_thread::sleep_for(chrono::milliseconds(3000));
    semaphore1.acquire();
    a.~thread();
    cout << endl;
    semaphoreI = 0;
    thread b(Worker, "'B'");
    thread c(Worker, "'C'");
    thread i(Worker, "'I'");
    thread j(Worker, "'J'");
    semaphore1.acquire();
    b.detach();
    c.detach();
    i.detach();
    j.detach();
    this_thread::sleep_for(chrono::milliseconds(500));
    j.~thread();
    semaphore1.release();
    this_thread::sleep_for(chrono::milliseconds(3000));
    semaphore1.acquire();
    b.~thread();
    c.~thread();
    i.~thread();
    cout << endl;
    semaphoreI = 0;
    thread d(Worker, "'D'");
    thread e(Worker, "'E'");
    thread f(Worker, "'F'");
    semaphore1.acquire();
    d.detach();
    e.detach();
    f.detach();
    this_thread::sleep_for(chrono::milliseconds(500));
    j.~thread();
    semaphore1.release();
    this_thread::sleep_for(chrono::milliseconds(3000));
    d.~thread();
    e.~thread();
    f.~thread();
    j.~thread();
    cout << endl;
    semaphoreI = 0;
    thread g(Worker, "'G'");
    thread h(Worker, "'H'");
    semaphore1.acquire();
    g.detach();
    h.detach();
    this_thread::sleep_for(chrono::milliseconds(500));
    semaphore1.release();
    this_thread::sleep_for(chrono::milliseconds(3000));
    g.~thread();
    h.~thread();
    cout << endl;
    semaphoreI = 0;
    thread k(Worker, "'K'");
    cout << "Поток 'K' начался." << endl;
    k.~thread();
    cout << "\nThe End" << endl;
    cin.get();
    return 0;
}


//
//std::counting_semaphore<1> semaphore2, semaphore3, semaphore4;
//
//void ProcessA() {
//    std::this_thread::sleep_for(std::chrono::seconds(1)); // Задержка для наглядности
//    std::cout << "Процесс A запускает процессы B, C, I, J" << std::endl;
//    semaphore2.release(); // Разблокировать процессы B, C, I, J
//}
//
//void ProcessB() {
//    semaphore2.acquire(); // Блокировать процесс B
//    std::this_thread::sleep_for(std::chrono::seconds(1)); // Задержка для наглядности
//    std::cout << "Процесс B запускает процессы D, E, F" << std::endl;
//    semaphore3.release(); // Разблокировать процессы D, E, F
//}
//
//void ProcessC() {
//    semaphore2.acquire(); // Блокировать процесс C
//    std::this_thread::sleep_for(std::chrono::seconds(1)); // Задержка для наглядности
//    std::cout << "Процесс C запускает процессы D, E, F" << std::endl;
//    semaphore3.release(); // Разблокировать процессы D, E, F
//}
//
//void ProcessI() {
//    semaphore2.acquire(); // Блокировать процесс I
//    std::this_thread::sleep_for(std::chrono::seconds(1)); // Задержка для наглядности
//    std::cout << "Процесс I запускает процессы D, E, F" << std::endl;
//    semaphore3.release(); // Разблокировать процессы D, E, F
//}
//
//void ProcessJ() {
//    semaphore2.acquire(); // Блокировать процесс J
//    std::this_thread::sleep_for(std::chrono::seconds(1)); // Задержка для наглядности
//    std::cout << "Процесс J конкурирует в запуске процессов G, H" << std::endl;
//    semaphore4.release(); // Разблокировать процессы G, H
//}
//
//void ProcessD() {
//    semaphore3.acquire(); // Блокировать процесс D
//    std::this_thread::sleep_for(std::chrono::seconds(1)); // Задержка для наглядности
//    std::cout << "Процесс D завершен" << std::endl;
//    semaphore4.release(); // Разблокировать процессы G, H
//}
//
//void ProcessE() {
//    semaphore3.acquire(); // Блокировать процесс E
//    std::this_thread::sleep_for(std::chrono::seconds(1)); // Задержка для наглядности
//    std::cout << "Процесс E завершен" << std::endl;
//    semaphore4.release(); // Разблокировать процессы G, H
//}
//
//void ProcessF() {
//    semaphore3.acquire(); // Блокировать процесс F
//    std::this_thread::sleep_for(std::chrono::seconds(1)); // Задержка для наглядности
//    std::cout << "Процесс F завершен" << std::endl;
//    semaphore4.release(); // Разблокировать процессы G, H
//}
//
//void ProcessG() {
//    semaphore4.acquire(); // Блокировать процесс G
//    std::this_thread::sleep_for(std::chrono::seconds(1)); // Задержка для наглядности
//    std::cout << "Процесс G завершен" << std::endl;
//}
//
//void ProcessH() {
//
//}
//
//void ProcessK() {
//    semaphore4.acquire(); // Блокировать процесс K
//    std::this_thread::sleep_for(std::chrono::seconds(1)); // Задержка для наглядности
//    std::cout << "Процесс K завершает программу" << std::endl;
//}
//
//int main() {
//    SetConsoleOutputCP(1251);
//    SetConsoleCP(1251);
//    std::thread a(ProcessA);
//    std::thread b(ProcessB);
//    std::thread c(ProcessC);
//    std::thread i(ProcessI);
//    std::thread j(ProcessJ);
//    std::thread d(ProcessD);
//    std::thread e(ProcessE);
//    std::thread f(ProcessF);
//    std::thread g(ProcessG);
//    std::thread h(ProcessH);
//    std::thread k(ProcessK);
//
//    a.join();
//    b.join();
//    c.join();
//    i.join();
//    j.join();
//    d.join();
//    e.join();
//    f.join();
//    g.join();
//    h.join();
//    k.join();
//
//    return 0;
//}