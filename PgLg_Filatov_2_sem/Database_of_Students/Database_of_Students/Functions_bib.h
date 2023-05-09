#pragma once
#include <iostream>
using namespace std;


bool Check(string _word)
{
    string int_alphabet = "0123456789";
    for (int i = 0; i < _word.length(); i++)
    {
        for (int j = 0; j < int_alphabet.length(); j++)
            if (_word[i] == int_alphabet[j]) { return false; }
    }
    return true;
}

void Clear()
{
    cin.clear(); cin.ignore(INT_MAX, '\n');
}

int HowMuchLinesInFile(const char _filename[])
{
    ifstream count_file; int count = 0; string line;
    count_file.open(_filename, ios::in);
    while (!count_file.eof()) { getline(count_file, line); count++; }
    count_file.close();
    return count;
}

#include "Session.h"
#include "Date_bib.h"
#include "Student_bib.h"
#include "StudentList_bib.h"
#include "Crypt_bib.h"

int menu()
{
    Decrypt();
    int choice = 10;
    Student OperatingStudent;
    StudentList studentList;
    bool firstcall = true;
    while (true)
    {
        while (cin.fail() || choice < 0 || choice > 6)
        {
            system("cls");
            if (!firstcall) Clear();
            cout << "�������� �������� �� �����������������. \n 1. �������� ������ ������ � �������� � ����.\n 2. ���������� ��� ������ � ��������� ��������.\n 3. �������� ������ ��������.\n";
            cout << " 4. ������� ������ ��������.\n 5. ����������� ���� ���������, � ������� �� ��� ����� �������� ��� �� ����� ������ � ������� ����� ��� ������������� ���� (������� 34).";
            cout << "\n 6. ����������� ���� ���������.\n 0. ����� �� ���������." << endl;
            cout << "�������� �������� [0-6]: ";  cin >> choice;
            firstcall = false;
        }
        Clear();
        switch (choice)
        {
        case 1:
            system("cls"); //Decrypt();
            cout << "�������� ������ � ��������: " << endl;
            OperatingStudent.SetStudent(); OperatingStudent.InputInFile("DB.txt");
            system("pause");
            firstcall = true; choice = 10; //Crypt();
            break;
        case 2:
            system("cls"); //Decrypt();
            OperatingStudent.OutputFromFile("DB.txt");
            system("pause");
            firstcall = true; choice = 10; //Crypt();
            break;
        case 3:
            system("cls"); //Decrypt();
            OperatingStudent.ChangeInfo("DB.txt");
            system("pause");
            firstcall = true; choice = 10; //Crypt();
            break;
        case 4:
            system("cls"); //Decrypt();
            OperatingStudent.DeleteInfo("DB.txt");
            system("pause");
            firstcall = true; choice = 10; //Crypt();
            break;
        case 5:
            system("cls"); //Decrypt();
            studentList.AddStudentsFromFile("DB.txt");
            studentList.PrintStudentList("test");
            studentList.FreeList();
            system("pause");
            firstcall = true; choice = 10; //Crypt();
            break;
        case 6:
            system("cls"); //Decrypt();
            studentList.AddStudentsFromFile("DB.txt");
            studentList.PrintStudentList();
            studentList.FreeList();
            system("pause");
            firstcall = true; choice = 10; 
            break;
        case 0:
            Crypt();
            return 0;
        }
    }
}
