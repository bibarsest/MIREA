#pragma once
//#include "clSession_bib.h"
#include <iostream>
#include "clDate_bib.h"
using namespace std;

template <class infoT>
class clList
{
    struct Node
    {
        infoT info;
        Node* next;
    };
    Node* head;
public:
    clList();
    ~clList();
    void addNode(infoT _newinfo);
    void printList();
    void operator[](int _i);
    //typedef infoT& reference;
    //friend istream& operator[](istream& is, clList<infoT>& obj);
    //void addNode(infoT& info);
    //friend istream& operator>>(istream& is, clList<Semester>& obj);
    //friend istream& operator>>(istream& is, clList<infoT>& obj);
};
template <class infoT> inline clList<infoT>::clList()
{
    head = nullptr;
};
template <class infoT> inline clList<infoT>::~clList()
{
    //for (Node* current = head; head != nullptr; current = head, head = head->next) delete current; //������� ������ ���������, ��-�� ���� ��������� �������� � ������ ��������� ��������
    cout << "������ ����������." << endl;
};
template <class infoT> inline void clList<infoT>::addNode(infoT _newinfo)
{
    Node* newNode = new Node{ _newinfo, nullptr };
    /* //� ������ ������
    if (newNode != nullptr)
    {
        newNode->next = head;
        head = newNode;
        newNode->info = _newinfo;
    }
    */
    if (head == nullptr) { head = newNode; }
    else
    {
        Node* current = head;
        while (current->next != nullptr) { current = current->next; }
        current->next = newNode;
    }
};
template <class infoT> inline void clList<infoT>::printList()
{
    for (Node* current = head; current != nullptr; current = current->next)
    {
        current->info.print(); //cout << endl;
    }
}

template <class infoT> inline void clList<infoT>::operator[](int _i)
{
    Node* current = head; int i = 0;
    /*for (int i = 0; i < _i, current != nullptr; i++, current = current->next)
    {
        
    }*/
    while ((i < _i) && (current != nullptr)) { i++, current = current->next; }
    if (i == _i) current->info.print();
    //if (i == _i) current->info;
    else cout << "��� ���������.\n";
}


//template <class infoT> inline istream& operator[](istream& is, clList<infoT>& obj);

//template <class infoT> inline void clList<infoT>::addNode(infoT& _newinfo)
//{
//    Node* newNode = new Node{ &_newinfo, nullptr };
//    if (newNode != nullptr)
//    {
//        newNode->next = head;
//        head = newNode;
//        newNode->info = &_newinfo;
//    }
//};

//template <typename infoT> inline istream& operator>>(istream& is, clList<infoT>& obj)
//{
//    int n;
//    cout << "������� ���������� ��������� ������: ";
//    is >> n;
//    for (int i = 0; i < n; i++)
//    {
//        clSession session;
//        cout << "������� ������ ��� �������� " << i + 1 << endl;
//        cout << "������� ������������ ����������: ";
//        is >> session.Name;
//        cout << "������� ���� �����: ";
//        is >> session.Date;
//        cout << "������� ������: ";
//        is >> session.Mark;
//        cout << "������� ��� �������������: ";
//        is >> session.Teacher;
//        obj.addNode(session);
//    }
//    return is;
//};

//
//template <typename infoT> inline istream& operator>>(istream& is, clList<Semester>& obj)
//{
//    int n;
//    cout << "������� ���������� ��������� ������: ";
//    is >> n;
//    for (int i = 0; i < n; i++)
//    {
//        Semester semester;
//        cout << "������� ������ ��� �������� " << i + 1 << endl;
//        cout << "������� ����� ��������: ";
//        is >> semester.number;
//        cout << "������� ���������� ������: ";
//        int m;
//        is >> m;
//        for (int j = 0; j < m; j++)
//        {
//            clSession session;
//            cout << "������� ������ ��� ������ " << j + 1 << endl;
//            cout << "������� ������������ ����������: ";
//            is >> session.Name;
//            cout << "������� ���� �����: ";
//            is >> session.Date;
//            cout << "������� ������: ";
//            is >> session.Mark;
//            cout << "������� ��� �������������: ";
//            is >> session.Teacher;
//            semester.Session.addNode(session);
//        }
//        obj.addNode(semester);
//    }
//    return is;
//};
