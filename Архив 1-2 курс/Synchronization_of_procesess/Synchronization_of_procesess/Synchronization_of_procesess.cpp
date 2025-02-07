#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "windows.h"

using namespace std;

mutex mtx;
condition_variable cv;
int semaphore = 0;

void Worker(const string& num) {
    unique_lock<mutex> lock(mtx);
    cout << "Поток " << num << " начался и ожидает семафор." << endl;
    cv.wait(lock, [] { return semaphore > 0; });
    semaphore--;
    lock.unlock();

    // Работа потока

    lock.lock();
    cout << "Поток " << num << " выходит из семафора." << endl;
    lock.unlock();
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    thread a(Worker, "'A'");
    this_thread::sleep_for(chrono::milliseconds(500));
    semaphore++;
    cv.notify_one();
    this_thread::sleep_for(chrono::milliseconds(3000));
    a.join();

    // Остальные потоки и семафоры

    return 0;
}