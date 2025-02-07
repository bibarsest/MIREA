#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <ctime>

long long nop = 0;
class QueuePtr
{
    int csize;
    struct list
    {
        int data;
        struct list* next;
    };
    list* head, * rear;
public:
    QueuePtr() {
        csize = 0;
        head = nullptr;
        rear = nullptr;
    }
    void push(int element) {
        list* l = new list();
        if (csize == 0) {
            l->next = nullptr;
            l->data = element;
            head = l;
            rear = l;
        }
        else
        {
            l->next = head;
            l->data = element;
            head = l;
            /*rear->next = l;
            rear->data = element;
            rear = l;*/
        }
        csize++;
    }
    int front() {
        return rear->data;
    }
    int size() {
        return csize;
    }
    void pop() { // удалить первый элемент (голова)
        if (csize == 1) {
            delete(head);
            csize = 0;
            head = nullptr;
            rear = nullptr;
        }
        else
        {
            list* l = head;
            list* prev = nullptr;
            while (l->next != nullptr) {
                prev = l;
                l = l->next;
            }
            csize--;
            delete(l);
            prev->next = nullptr;
            rear = prev;
        }
    }
    void Display() {
        QueuePtr* queTmp1 = new QueuePtr();
        int c_size = size();
        for (int i = 0; i < c_size; i++) {
            queTmp1->push(front());
            cout << " " << front();
            pop();
        }
        for (int i = 0; i < c_size; i++) {
            push(queTmp1->front());
            queTmp1->pop();
        }
    }
};

//unsigned int nop = 0;
//class QueuePtr
//{
//	int csize;
//	struct list
//	{
//		int data;
//		struct list* next; 
//	};
//	list* head, * rear;
//public:
//	QueuePtr() {
//		csize = 0;
//		head = nullptr;
//		rear = nullptr;
//	}
//	void push(int element) {
//		list* l = new list();
//		if (csize == 0) {
//			l->next = nullptr;
//			l->data = element;
//			head = l;
//			rear = l;
//		}
//		else
//		{
//			l->next = head;
//			l->data = element;
//			head = l;
//		}
//		csize++;
//	}
//	int front() {
//		return rear->data;
//	}
//	int size() {
//		return csize;
//	}
//	void pop() {
//		if (csize == 1) {
//			delete(head);
//			csize = 0;
//			head = nullptr;
//			rear = nullptr;
//		}
//		else
//		{
//			list* l = head;
//			list* prev = nullptr;
//			while (l->next != nullptr) {
//				prev = l;
//				l = l->next;
//			}
//			csize--;
//			delete(l);
//			prev->next = nullptr;
//			rear = prev;
//		}
//	}
//	void Display() {
//		QueuePtr* queTmp1 = new QueuePtr();
//		int c_size = size();
//		for (int i = 0; i < c_size; i++) {
//			queTmp1->push(front());
//			cout << " " << front();
//			pop();
//		}
//		for (int i = 0; i < c_size; i++) {
//			push(queTmp1->front());
//			queTmp1->pop();
//		}
//	}
//};

class adapter4QueuePtr
{
	QueuePtr* qu;
public:
	adapter4QueuePtr() {
		//cout << "\nÎáû÷íûé êîíñòðóêòîð\n";
		qu = new QueuePtr();
	}
	//adapter4QueuePtr(const adapter4QueuePtr& obj)
	//{
	//	cout << "\nÊîíñòðóêòîð êîïèðîâàíèÿ\n";
	//}
	void Display() {
		qu->Display();
	}
	void push(int num) {
		qu->push(num);
	}
	void pop() {
		qu->pop();
	}
	int size() {
		return qu->size();
	}
	int front() {
		return qu->front();
	}
	/// <summary>
	/// Ôóíêöèÿ äëÿ ïîëó÷åíèÿ ýëåìåíòà ïî èíäåêñó
	/// </summary>
	/// <param name="ind">èäåêñ ýëåìåíàòà</param>
	/// <returns>ýëåìåíò</returns>
	int getElement(int ind) {
		int size = qu->size();
		int element = -1;
		if ((ind >= 0) and (ind < size)) {
			QueuePtr* queTmp1 = new QueuePtr();
			for (int i = 0; i <= ind; i++) {
				queTmp1->push(front());
				element = front();
				pop();
			}
			for (int i = ind + 1; i < size; i++) {
				queTmp1->push(front());
				pop();
			}
			for (int i = 0; i < size; i++) {
				push(queTmp1->front());
				queTmp1->pop();
			}
		}
		return element;
	}
	void  setElement(int ind, int element) {
		int size = qu->size();
		if ((ind >= 0) and (ind < size)) {
			QueuePtr* queTmp1 = new QueuePtr();
			for (int i = 0; i < ind; i++) {
				queTmp1->push(front());
				pop();
			}
			queTmp1->push(element);
			pop();
			for (int i = ind + 1; i < size; i++) {
				queTmp1->push(front());
				pop();
			}
			for (int i = 0; i < size; i++) {
				push(queTmp1->front());
				queTmp1->pop();
			}
		}
	}
	adapter4QueuePtr* copy() {
		adapter4QueuePtr* queTmp1 = new adapter4QueuePtr();
		int size = qu->size();
		for (int i = 0; i < size; i++) {
			queTmp1->push(front());
			pop();
		}
		return queTmp1;
	}

};

// var 34
void example_work_queuePtr() {
    QueuePtr* q1 = new QueuePtr();
    q1->push(1000);
    q1->push(2000);
    q1->push(3000);
    q1->push(4000);
    q1->push(5000);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl << "Queue: "; q1->Display();
    cout << endl << "Front: " << q1->front();
    q1->pop();
    q1->pop();

    q1->push(20000);
    cout << endl << "Queue: "; q1->Display();
    cout << endl << "front: " << q1->front();
}
void example_work_adapter4queuePtr() {
    adapter4QueuePtr* q1 = new adapter4QueuePtr();
    q1->push(1);
    q1->push(2);
    q1->push(3);
    q1->push(4);
    q1->push(5);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->Display();
    q1->setElement(2, 1000);
    int element = q1->getElement(2);
    cout << endl << element;
    cout << endl; q1->Display();
    element = q1->getElement(2);
    cout << endl << element;
    element = q1->getElement(2);
    cout << endl << element;
    cout << endl; q1->Display();
}
// Функция быстрой сортировки
void quickSortQueuePtr(adapter4QueuePtr* array, int low, int high)
{
    //adapter4QueuePtr* array = arrayq->copy();
    //cout << endl << " low: " << low << " high: " << high << " QueuePtr "; array->Display();
    nop++; nop++;
    int i = low;
    int j = high;
    //int pivot = array[(i + j) / 2];
    nop+=4;
    int pivot = array->getElement((i + j) / 2);
    int temp;
    nop++;
    while (i <= j)
    {
        nop++; nop++;
        while (array->getElement(i) < pivot)
        {
            //while (array[i] < pivot)
            i++;
            nop++; nop++; nop++;
        }
        nop++; nop++;
        while (array->getElement(j) > pivot)
        {
            j--;
            nop++; nop++; nop++;
        }
        nop++;
        if (i <= j)
        {
            //temp = array->getElement(i);
            //array->setElement(i, array->getElement(j));
            //array->setElement(i, temp);
            nop++; nop++;
            temp = array->getElement(i);
            nop++; nop++;
            array->setElement(i, array->getElement(j));
            nop++;
            array->setElement(j, temp);
            nop++; nop++;
            i++;
            j--;
        }
    }
    nop++;
    if (j > low)
    {
        quickSortQueuePtr(array, low, j);
    }
    nop++;
    if (i < high)
    {
        quickSortQueuePtr(array, i, high);
    }
    //cout << "\nnop = " << nop << "\n";
}
void example_work_quickSortQueuePtr() {
    adapter4QueuePtr* q1 = new adapter4QueuePtr();
    q1->push(5);
    q1->push(200);
    q1->push(1);
    q1->push(3);
    q1->push(4);
    q1->push(10);
    q1->push(5);
    int size = q1->size();
    cout << "Size of queue: " << size << endl;
    cout << endl; q1->Display();
    quickSortQueuePtr(q1, 0, size - 1);
    cout << endl; q1->Display();
    cout << endl; q1->Display();
}
