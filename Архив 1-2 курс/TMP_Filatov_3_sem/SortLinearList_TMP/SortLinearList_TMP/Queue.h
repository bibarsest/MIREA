#pragma once

#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;

long long nop = 0;

class Queue
{
private:
	struct queue
	{
		int info;
		queue* next;
	};
	queue* head;
	queue* tail;
public:
	Queue()
	{
		head = NULL;
		tail = NULL;
		nop += 3;
	}

	void Add(int v)
	{
		queue* tmp = new(queue); nop += 2;
		nop++;
		if (tmp == NULL) { nop += 3; cout << "Очередь пуста" << endl; return; }
		tmp->next = NULL; nop += 2;
		tmp->info = v; nop += 2;
		nop++;
		if (head == NULL)
		{
			head = tmp; nop++;
			tail = tmp; nop++;
		}
		else 
		{
			nop++;
			if (tail == NULL) 
			{
				tail = tmp; nop++;
			}
			else 
			{
				tail->next = tmp; nop += 2;
				tail = tmp; nop++;
			}
		}
	}

	int Del()
	{
		nop++;
		if (Empty()) 
		{
			nop += 3; cout << "Очередь пуста" << endl;
			nop++; return -1;
		}
		queue* tmp = head; nop++;
		head = head->next; nop++;
		int ret = tmp->info; nop += 2;
		delete tmp; nop++;
		return ret; nop++;
	}

	void value()
	{
		nop++;
		if (Empty()) 
		{
			nop += 2; cout << "Очередь пуста" << endl; return;
		}
		queue* tmp = head; nop++;
		int c = 0; nop++;
		while (tmp) 
		{
			nop++;
			nop += 7; cout << "A[" << c << "]: info = " << tmp->info << " address = " << tmp << " next = " << tmp->next << endl;
			tmp = tmp->next; nop++;
			c++; nop++;
		}
		nop++; cout << endl;
	}

	void setinfo(queue* b, int a)
	{
		nop += 2;
		b->info = a;
	}

	int getinfo(queue* b)
	{
		nop+=2;
		return b->info; 
	}

	int ShowHead()
	{
		nop += 2;
		return head->info;
	}

	int ShowTail()
	{
		nop += 2;
		return tail->info;
	}

	bool Empty()
	{
		return head == NULL ? true : false;
	}

	queue* operator [](int i)
	{
		nop++;
		queue* tmp = head; nop++;
		int c = 0; nop++;
		while (c != i) 
		{
			nop++;
			tmp = tmp->next; nop += 2;
			c++; nop++;
		}
		nop++;
		return tmp;
	}
};


void Sort(Queue numbers, int left, int right)
{
	int pivot; nop += 1; 
	int l_hold = left; nop += 1; 
	int r_hold = right; nop += 1; 
	pivot = numbers[left]->info; nop += 2;
	while (left < right) 
	{
		nop += 1;
		while ((numbers.getinfo(numbers[right]) >= pivot) && (left < right))
		{
			nop += 3;
			right--; nop += 1; 
		}

		if (left != right) 
		{
			nop += 1;
			numbers.setinfo(numbers[left], numbers[right]->info); nop += 5;
			left++; nop += 1; 
		}
		while ((numbers.getinfo(numbers[left]) <= pivot) && (left < right))
		{
			nop += 3;
			left++; nop += 1; 
		}

		if (left != right)
		{
			nop += 1;
			numbers.setinfo(numbers[right], numbers[left]->info); nop += 5; 
			right--; nop += 1; 
		}
	}
	numbers.setinfo(numbers[left], pivot); nop += 3; 
	pivot = left; nop += 1;
	left = l_hold; nop += 1;
	right = r_hold; nop += 1;
	if (left < pivot) 
	{
		nop += 1;
		Sort(numbers, left, pivot - 1); nop += 4;
	}
	if (right > pivot)
	{
		Sort(numbers, pivot + 1, right); nop += 4;
		nop += 1;
	}
}

