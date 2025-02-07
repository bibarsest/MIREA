#include <iostream>
#include "Queue.h"
using namespace std;
#include <windows.h>
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    int t_s, t_e = 0;
//    int i = 0;
//    adapter4QueuePtr* test = new adapter4QueuePtr();
//    for (int n = 300; n < 3000; n += 300) {
//        for (i = 0; i < n; i++) {
//            test->push(rand());
//        }
//        //test->push(rand()); test->push(rand()); test->push(rand()); test->push(rand());
//
//        //test->Display();
//
//        t_s = GetTickCount();
//        quickSortQueuePtr(test, 0, n - 1);
//        t_e = GetTickCount();
//        cout << "\nn = " << n << "\nnop = " << nop << "\nTime = " << t_e - t_s << "\n";
//        nop = 0;
//        //cout << "Очередь после сортировки "; test->Display(); cout << "\n";
//        for (i = 0; i < 100; i++) {
//            test->pop();
//        }
//    }
//    //cout << "Очередь пустая "; test->Display(); cout << "\n";
//    
//    // var 34 
//    cout << endl << nop<<endl;
//    //example_work_queuePtr();
//    //std::cout << "Hello World!\n";
//    ////example_work_adapter4queuePtr();
//    //std::cout << "Hello World!\n";
//    //example_work_quickSortQueuePtr();
//}
//

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Queue qu; nop++;
	int time_start, time_end = 0;
	nop += 2;
	for (int n = 300; n <= 3000; n += 300)
	{
		for (int i = 0; i <= n; i++)
		{
			qu.Add(rand()); nop += 3;
		}
		time_start = GetTickCount(); nop += 2;
		Sort(qu, 0, n); nop += 4;
		time_end = GetTickCount(); nop += 2;
		cout << "n = " << n << endl;
		cout << "Время: = " << time_end - time_start << endl;
		cout << "N_op: = " << nop << endl << endl;
		nop = 0;
		for (int i = 0; i <= n; i++)
		{
			qu.Del();
		}
	}
	cout << endl;
	system("pause");
	return 0;
}