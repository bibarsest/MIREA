#pragma once
#include <iostream>
using namespace std;
#include "Functions_bib.h"

class StudentList
{
    struct Node
    {
        Student* student;
        Node* next;
    };
    Node* head;
public:
    StudentList() { head = nullptr; }
    ~StudentList()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void AddStudent(Student& student)
    {
        Node* newNode = new Node{ &student, nullptr };
        if (head == nullptr) { head = newNode; }
        else
        {
            Node* current = head;
            while (current->next != nullptr) { current = current->next; }
            current->next = newNode;
        }
    }

    void AddStudent(Student* student)
    {
        Node* newNode = new Node{ student, nullptr };
        if (head == nullptr) { head = newNode; }
        else
        {
            Node* current = head;
            while (current->next != nullptr) { current = current->next; }
            current->next = newNode;
        }
    }

    void AddStudentsFromFile(const char _filename[])
    {
        ifstream infile;
        infile.open(_filename);
        string buffer;
        int totallines = HowMuchLinesInFile(_filename), countdown = 0;
        Student* student = new Student[totallines - 1];
        while (!infile.eof() && (countdown < totallines - 1))
        {

            for (int k = 0; k < totallines - 1; k++, countdown++)
            {
                infile >> student[k];
                Session** Sessions = new Session * [student[k].GetNumberofSessions()];
                for (int i = 0; i < student[k].GetNumberofSessions(); i++)
                {
                    Sessions[i] = new Session[student[k].GetMaxNumberofSubjects()];
                    for (int j = 0; j < student[k].GetMaxNumberofSubjects() + 1; j++)
                    {
                        infile >> buffer;
                        if (buffer == "|") break;
                        Sessions[i][j].subject = buffer;
                        infile >> Sessions[i][j].mark;
                        if (Sessions[i][j].mark == "3") student[k].Set_three_mark(true);
                    }
                }
                for (int i = 0; i < student[k].GetNumberofSessions(); i++)
                {
                    delete[] Sessions[i];
                }
                delete[] Sessions;

                AddStudent(student[k]);
            }
        }
        infile.close();
    }

    void PrintStudentList()
    {
        for (Node* current = head; current != nullptr; current = current->next)
        {
            current->student->PrintStudent(); cout << endl;
        }
    }
    void PrintStudentList(string _sex)
    {
        while (_sex != "м" && _sex != "ж")
        {
            cout << "¬ывести всех студентов без троек, пол которых [м/ж]: "; cin >> _sex; Clear();
        }
        cin.clear();
        for (Node* current = head; current != nullptr; current = current->next)
        {
            if (current->student->GetSex() == _sex && !current->student->Get_three_mark()) { current->student->PrintStudent(); cout << endl; }
        }
    }
    void FreeList()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};