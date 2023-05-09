#pragma once
#include <iostream>
using namespace std;
#include "Functions_bib.h"

class Student
{
    string LastName, FirstName, SurName; 
    Date BirthDate; 
    int EnrollmentYear; 
    string Institute, Department, Group, RecordBook; 
    string Sex; 
    int numberofSessions, numberofSubjects, maxnumberofSubjects = -10;
    bool has_three_mark = false;

public:
    Student() 
    {
        LastName = "undefined"; FirstName = "undefined"; SurName = "undefined";
        BirthDate.SetDate(0, 0, 0); EnrollmentYear = 0;
        Institute = "undefined"; Department = "undefined"; Group = "undefined"; RecordBook = "undefined";
        Sex = 'u';
    }
    Student(string _LastName, string _FirstName, string _SurName, Date _BirthDate, int _EnrollmentYear,
        string _Institute, string _Department, string _Group, string _RecordBook, string _Sex)
    {
        LastName = _LastName; FirstName = _FirstName; SurName = _SurName;
        BirthDate.SetDate(_BirthDate); EnrollmentYear = _EnrollmentYear;
        Institute = _Institute; Department = _Department; Group = _Group; RecordBook = _RecordBook;
        Sex = _Sex;
    }
    friend ostream& operator<<(ostream& os, Student& st)
    {
        os << st.LastName << " " << st.FirstName << " " << st.SurName;
        if (st.Sex == "�" || st.Sex == "�")
        {
            if (st.Sex == "�") os << ", �������";
            if (st.Sex == "�") os << ", �������";
        }
        else os << ", ��� �� ���������";
        os << " | ";
        os << "���� ��������: "; st.BirthDate.PrintDate(); os << endl;
        os << "��� �����������: " << st.EnrollmentYear << " | �������� " << st.Institute << " | ������� " << st.Department << endl;
        os << "������ " << st.Group << " | ���� " << st.RecordBook << " " << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Student& st)
    {
        is >> st.LastName >> st.FirstName >> st.SurName >> st.BirthDate >> st.EnrollmentYear >> st.Institute >> st.Department >> st.Group >> st.RecordBook >> st.Sex >> st.numberofSessions >> st.maxnumberofSubjects;
        return is;
    }
    void Set_three_mark(bool is_mark) { has_three_mark = is_mark; }
    void SetStudent(string _LastName, string _FirstName, string _SurName, Date _BirthDate, int _EnrollmentYear,
        string _Institute, string _Department, string _Group, string _RecordBook, string _Sex)
    {
        LastName = _LastName; FirstName = _FirstName; SurName = _SurName;
        BirthDate.SetDate(_BirthDate); EnrollmentYear = _EnrollmentYear;
        Institute = _Institute; Department = _Department; Group = _Group; RecordBook = _RecordBook;
        Sex = _Sex;
    }

    void SetStudent() 
    {
        ifstream file;
        string line, searchline;
        bool RecordBook_search = true, count = true;
        cout << "�������: "; cin >> LastName;
        while (cin.fail() || !(Check(LastName))) { Clear(); cout << "������ �����. ������� �� ������ ��������� ����. \n>"; cin >> LastName; }
        Clear(); 
        cout << "���: "; cin >> FirstName;
        while (cin.fail() || !(Check(FirstName))) { Clear(); cout << "������ �����. ��� �� ������ ��������� ����. \n>"; cin >> FirstName; }
        Clear(); 
        cout << "��������: "; cin >> SurName;
        while (cin.fail() || !(Check(SurName))) { Clear(); cout << "������ �����. �������� �� ������ ��������� ����. \n>"; cin >> SurName; }
        Clear(); 
        cout << "���� ��������: "; BirthDate.SetDate();
        cout << "��� �����������: "; cin >> EnrollmentYear;
        while (cin.fail() || EnrollmentYear < 1900) { cout << "������ �����. ��� ����������� [>=1900]: "; Clear(); cin >> EnrollmentYear; }
        Clear();
        cout << "��������: "; cin >> Institute; Clear();
        cout << "�������: "; cin >> Department; Clear();
        cout << "������: "; cin >> Group; Clear();
        cout << "����� �������� ������: "; cin >> RecordBook; Clear();

        while (RecordBook_search)
        {
            file.open("DB.txt", ios::out);
            count = false;
            while (getline(file, line))
            {
                while (line.find(RecordBook) != string::npos)
                {
                    cout << "����� �������� ������ ��� ������������. ������� ������." << endl;
                    cout << "����� �������� ������: "; cin >> RecordBook; Clear();
                    count = true;
                }
            }
            file.close();
            if (count == false) RecordBook_search = false;
        }

        cout << "��� (�-�������, �-�������): "; cin >> Sex;
        while (cin.fail() || ((Sex != "�") && (Sex != "�"))) { Clear(); cout << "������ �����. ��� [�/�]: "; cin >> Sex; }
        Clear();
    }

    void InputInFile()
    {

        ofstream file;
        file.open("DB.txt", ios::app);
        file << LastName << " " << FirstName << " " << SurName << " " << BirthDate.GetInfo("Day") << " "
            << BirthDate.GetInfo("Month") << " " << BirthDate.GetInfo("Year") << " " << EnrollmentYear << " "
            << Institute << " " << Department << " " << Group << " " << RecordBook << " " << Sex << endl;
        file.close();
    }

    void InputInFile(const char _filename[])
    {
        cout << "���-�� ������ [1-9]: "; cin >> numberofSessions;
        while (cin.fail() || numberofSessions < 1 || numberofSessions > 9) { cout << "������ �����. ���-�� ������ [1-9]: "; Clear(); cin >> numberofSessions; }
        Clear();
        Session** Sessions = new Session * [numberofSessions];

        for (int i = 0; i < numberofSessions; i++)
        {
            cout << "���-�� ��������� ��� ������ �" << i + 1 << " [1-10]: "; cin >> numberofSubjects;
            while (cin.fail() || numberofSubjects < 1 || numberofSubjects > 10) { cout << "������ �����. ���-�� ��������� [1-10]: "; Clear(); cin >> numberofSubjects; }
            Clear();
            if (numberofSubjects > maxnumberofSubjects) maxnumberofSubjects = numberofSubjects;
            Sessions[i] = new Session[10]();
            for (int j = 0; j < numberofSubjects; j++)
            {
                cout << "������� �" << j + 1 << ": "; cin >> Sessions[i][j].subject; Clear();
                cout << "������ �" << j + 1 << " [1-5, � - �����, � - �������]: "; cin >> Sessions[i][j].mark;
                while (cin.fail() || (Sessions[i][j].mark != "�" && Sessions[i][j].mark != "�" &&
                    Sessions[i][j].mark != "5" && Sessions[i][j].mark != "4" && Sessions[i][j].mark != "3" && Sessions[i][j].mark != "2" && Sessions[i][j].mark != "1"))
                {
                    cout << "������ �����. ������: [1-5, � - �����, � - �������]: "; Clear(); cin >> Sessions[i][j].mark;
                }
                Clear();
            }
        }
        string choice = "z";
        while (cin.fail() || (choice != "1" && choice != "0"))
        {
            system("cls");
            cout << "��������� ������: "; PrintStudent();
            for (int i = 0; i < numberofSessions; i++)
            {
                cout << "----------������ �" << i + 1 << "----------" << endl;
                for (int j = 0; j < maxnumberofSubjects; j++)
                {
                    if (Sessions[i][j].mark == "#") break;
                    cout << Sessions[i][j].subject << ": ";
                    if (Sessions[i][j].mark == "�" || Sessions[i][j].mark == "�")
                    {
                        if (Sessions[i][j].mark == "�") cout << "����� | ";
                        if (Sessions[i][j].mark == "�") cout << "������� | ";
                    }
                    else  if (stoi(Sessions[i][j].mark) > 0 && stoi(Sessions[i][j].mark) < 6) cout << Sessions[i][j].mark << " | ";
                    if (j == 3 || j == 7) cout << endl;
                }
                cout << endl;
            }

            cout << "������ �������� ������ � ����?\n 1 - ��.\n 0 - ���.\n> ";
            cin >> choice;
            if (choice == "1")
            {
                ofstream file;
                file.open(_filename, ios::app);
                file << LastName << " " << FirstName << " " << SurName << " " << BirthDate.GetInfo("Day") << " "
                    << BirthDate.GetInfo("Month") << " " << BirthDate.GetInfo("Year") << " " << EnrollmentYear << " "
                    << Institute << " " << Department << " " << Group << " " << RecordBook << " " << Sex << " " <<
                    numberofSessions << " " << maxnumberofSubjects << " ";
                for (int i = 0; i < numberofSessions; i++)
                {
                    for (int j = 0; j < maxnumberofSubjects; j++)
                    {
                        if (Sessions[i][j].mark == "#") break;
                        file << Sessions[i][j].subject << " " << Sessions[i][j].mark << " ";
                    }
                    file << "| ";
                }
                file << endl;
                file.close();
            }
            if (choice == "0") { cout << "������ �� ��������. " << endl; }
            if (choice != "1" && choice != "0") { Clear(); system("cls"); cout << "������ �����. " << endl; }
        }
        for (int i = 0; i < numberofSessions; i++)
        {
            delete[] Sessions[i];
        }
        delete[] Sessions;
        Clear();
    }

    void OutputFromFile(const char _filename[])
    {
        ifstream file;
        string searchline, buffer;

        cout << "������� ����� �������� ������ ��������: "; cin >> searchline;
        file.open(_filename, ios::in);
        while (file >> LastName >> FirstName >> SurName >> BirthDate.Day >> BirthDate.Month >> BirthDate.Year >>
            EnrollmentYear >> Institute >> Department >> Group >> RecordBook >> Sex >> numberofSessions >> maxnumberofSubjects)
        {
            Session** Sessions = new Session * [numberofSessions];
            for (int i = 0; i < numberofSessions; i++)
            {
                Sessions[i] = new Session[maxnumberofSubjects];
            }
            for (int i = 0; i < numberofSessions; i++)
            {
                for (int j = 0; j < maxnumberofSubjects + 1; j++)
                {
                    file >> buffer;
                    if (buffer == "|") break;
                    Sessions[i][j].subject = buffer;
                    file >> Sessions[i][j].mark;
                }
            }
            if (RecordBook.find(searchline) != string::npos)
            {

                PrintStudent();
                for (int i = 0; i < numberofSessions; i++)
                {
                    cout << "----------������ �" << i + 1 << "----------" << endl;
                    for (int j = 0; j < maxnumberofSubjects; j++)
                    {
                        if (Sessions[i][j].mark == "#") break;
                        cout << Sessions[i][j].subject << ": ";
                        if (Sessions[i][j].mark == "�" || Sessions[i][j].mark == "�")
                        {
                            if (Sessions[i][j].mark == "�") cout << "����� | ";
                            if (Sessions[i][j].mark == "�") cout << "������� | ";
                        }
                        else cout << Sessions[i][j].mark << " | ";
                        if (j == 3 || j == 7) cout << endl;
                    }
                    cout << endl;
                }

            }
            for (int i = 0; i < numberofSessions; i++)
            {
                delete[] Sessions[i];
            }
            delete[] Sessions;
        }
        file.close();
    }
    void OutputFromFile(const char _filename[], int o)
    {
        ifstream file;
        string line, searchline, buffer;
        cout << "������� ����� �������� ������ ��������: "; cin >> searchline;
        file.open(_filename, ios::in);
        while (getline(file, line))
        {
            stringstream ss(line);
            ss >> LastName >> FirstName >> SurName >> BirthDate.Day >> BirthDate.Month >> BirthDate.Year >>
                EnrollmentYear >> Institute >> Department >> Group >> RecordBook >> Sex >> numberofSessions >> maxnumberofSubjects;

            Session** Sessions = new Session * [numberofSessions];
            for (int i = 0; i < numberofSessions; i++)
            {
                Sessions[i] = new Session[maxnumberofSubjects];
            }
            for (int i = 0; i < numberofSessions; i++)
            {
                for (int j = 0; j < maxnumberofSubjects + 1; j++)
                {
                    ss >> buffer;
                    if (buffer == "|") break;
                    Sessions[i][j].subject = buffer;
                    ss >> Sessions[i][j].mark;
                }
            }
            if (RecordBook.find(searchline) != string::npos)
            {

                PrintStudent();
                for (int i = 0; i < numberofSessions; i++)
                {

                    cout << "----------������ �" << i + 1 << "----------" << endl;
                    for (int j = 0; j < maxnumberofSubjects; j++)
                    {
                        if (Sessions[i][j].mark == "#") break;
                        cout << Sessions[i][j].subject << ": ";
                        if (Sessions[i][j].mark == "�" || Sessions[i][j].mark == "�")
                        {
                            if (Sessions[i][j].mark == "�") cout << "����� ";
                            if (Sessions[i][j].mark == "�") cout << "������� ";
                        }
                        else cout << Sessions[i][j].mark << " ";
                    }
                    cout << endl;
                }
            }
            for (int i = 0; i < numberofSessions; i++)
            {
                delete[] Sessions[i];
            }
            delete[] Sessions;
        }
        file.close();
    }
    void DeleteInfo(const char _filename[])
    {
        ifstream file;
        string bufer, line, searchline;
        int deleting_choice = 0;
        remove("DBtemp.txt");
        cout << "������� ����� �������� ������ ��������: "; cin >> searchline;
        file.open(_filename, ios::in);
        while (file >> LastName >> FirstName >> SurName >> BirthDate.Day >> BirthDate.Month >> BirthDate.Year >>
            EnrollmentYear >> Institute >> Department >> Group >> RecordBook >> Sex >> numberofSessions >> maxnumberofSubjects)
        {
            Session** Sessions = new Session * [numberofSessions];
            for (int i = 0; i < numberofSessions; i++)
            {
                Sessions[i] = new Session[maxnumberofSubjects];
            }
            for (int i = 0; i < numberofSessions; i++)
            {
                for (int j = 0; j < maxnumberofSubjects + 1; j++)
                {
                    file >> bufer;
                    if (bufer == "|") break;
                    Sessions[i][j].subject = bufer;
                    file >> Sessions[i][j].mark;
                }
            }
            if (RecordBook.find(searchline) != string::npos)
            {
                cout << "��������� ��� �������� ������: " << endl; PrintStudent();
                for (int i = 0; i < numberofSessions; i++)
                {
                    cout << "----------������ �" << i + 1 << "----------" << endl;
                    for (int j = 0; j < maxnumberofSubjects; j++)
                    {
                        if (Sessions[i][j].mark == "#") break;
                        cout << Sessions[i][j].subject << ": ";
                        if (Sessions[i][j].mark == "�" || Sessions[i][j].mark == "�")
                        {
                            if (Sessions[i][j].mark == "�") cout << "����� | ";
                            if (Sessions[i][j].mark == "�") cout << "������� | ";
                        }
                        else cout << Sessions[i][j].mark << " | ";
                        if (j == 3 || j == 7) cout << endl;
                    }
                    cout << endl;
                }
                cout << "�� �������, ��� ������ ������� ������?\n 1. �������.\n 0. ������.\n> ";
                cin >> deleting_choice;
                while (cin.fail() || (deleting_choice != 0 && deleting_choice != 1))
                {
                    Clear(); system("cls");
                    cout << "������ �����.\n�� �������, ��� ������ ������� ������?\n 1. �������.\n 0. ������.\n> "; cin >> deleting_choice;
                }
                Clear();
            }
            for (int i = 0; i < numberofSessions; i++)
            {
                delete[] Sessions[i];
            }
            delete[] Sessions;
        }
        switch (deleting_choice)
        {

        case 0:
            file.close();
            cout << "������ �� �������." << endl;
            break;
        case 1:
            file.close();
            file.open(_filename, ios::in);
            while (file >> LastName >> FirstName >> SurName >> BirthDate.Day >> BirthDate.Month >> BirthDate.Year >>
                EnrollmentYear >> Institute >> Department >> Group >> RecordBook >> Sex >> numberofSessions >> maxnumberofSubjects)
            {
                Session** Sessions = new Session * [numberofSessions];
                for (int i = 0; i < numberofSessions; i++)
                {
                    Sessions[i] = new Session[maxnumberofSubjects];
                }
                for (int i = 0; i < numberofSessions; i++)
                {
                    for (int j = 0; j < maxnumberofSubjects + 1; j++)
                    {
                        file >> bufer;
                        if (bufer == "|") break;
                        Sessions[i][j].subject = bufer;
                        file >> Sessions[i][j].mark;
                    }
                }
                if (!(RecordBook.find(searchline) != string::npos))
                {
                    ofstream file_out;
                    file_out.open("DBtemp.txt", ios::app);
                    file_out << LastName << " " << FirstName << " " << SurName << " " << BirthDate.GetInfo("Day") << " "
                        << BirthDate.GetInfo("Month") << " " << BirthDate.GetInfo("Year") << " " << EnrollmentYear << " "
                        << Institute << " " << Department << " " << Group << " " << RecordBook << " " << Sex << " " << numberofSessions << " "
                        << maxnumberofSubjects << " ";
                    for (int i = 0; i < numberofSessions; i++)
                    {
                        for (int j = 0; j < maxnumberofSubjects; j++)
                        {
                            if (Sessions[i][j].mark == "#") break;
                            file_out << Sessions[i][j].subject << " " << Sessions[i][j].mark << " ";
                        }
                        file_out << "| ";
                    }
                    file_out << endl;
                    file_out.close();
                }
                for (int i = 0; i < numberofSessions; i++)
                {
                    delete[] Sessions[i];
                }
                delete[] Sessions;
            }
            file.close();
            remove(_filename);
            rename("DBtemp.txt", _filename);
            cout << "������ �������." << endl;
            break;
        }
    }
    void ChangeInfo(const char _filename[])
    {
        ifstream file;
        string searchline, buffer, line;
        int choice = 20, session_num = 0, subject_num = 0;
        bool menu_is_true = true, RecordBook_search = true, is_RecordBook_changed = false, RecordBook_changed = false, first_change_sessions = true;
        remove("DBtemp.txt");
        cout << "������� ����� �������� ������ ��������: "; cin >> searchline;
        file.open(_filename, ios::in);
        while (file >> LastName >> FirstName >> SurName >> BirthDate.Day >> BirthDate.Month >> BirthDate.Year >>
            EnrollmentYear >> Institute >> Department >> Group >> RecordBook >> Sex >> numberofSessions >> maxnumberofSubjects)
        {
            Session** Sessions = new Session * [numberofSessions];
            for (int i = 0; i < numberofSessions; i++)
            {
                Sessions[i] = new Session[maxnumberofSubjects]();
            }
            for (int i = 0; i < numberofSessions; i++)
            {
                for (int j = 0; j < maxnumberofSubjects + 1; j++)
                {
                    file >> buffer;
                    if (buffer == "|") break;
                    Sessions[i][j].subject = buffer;
                    file >> Sessions[i][j].mark;
                }
            }

            if (RecordBook.find(searchline) != string::npos)
            {
                while (menu_is_true)
                {
                    while (cin.fail() || choice < 0 || choice > 12)
                    {
                        Clear(); system("cls");
                        cout << "��������� �������: " << endl; PrintStudent();
                        for (int i = 0; i < numberofSessions; i++)
                        {
                            cout << "----------������ �" << i + 1 << "----------" << endl;
                            for (int j = 0; j < maxnumberofSubjects; j++)
                            {
                                if (Sessions[i][j].mark == "#") break;
                                cout << Sessions[i][j].subject << ": ";
                                if (Sessions[i][j].mark == "�" || Sessions[i][j].mark == "�")
                                {
                                    if (Sessions[i][j].mark == "�") cout << "����� | ";
                                    if (Sessions[i][j].mark == "�") cout << "������� | ";
                                }
                                else cout << Sessions[i][j].mark << " | ";
                                if (j == 3 || j == 7) cout << endl;
                            }
                            cout << endl;
                        }
                        cout << "����� ������ ����� ��������?\n1.  �������\n2.  ���\n3.  ��������\n4.  ���� ��������\n5.  ��� �����������\n6.  ��������\n7.  �������\n8.  ������\n9.  ";
                        cout << "����� �������� ������\n10. ���\n11. ��������� ������\n12. �������� ������\n0.  �����������\n>>> ";
                        cin >> choice;
                    }
                    Clear();
                    switch (choice)
                    {
                        system("cls");
                    case 0: menu_is_true = false; break;
                    case 1:
                        cout << "�������: "; cin >> LastName;
                        while (cin.fail() || !(Check(LastName))) { Clear(); cout << "������ �����. ������� �� ������ ��������� ����. \n>"; cin >> LastName; }
                        choice = 20; break;
                    case 2:
                        cout << "���: "; cin >> FirstName;
                        while (cin.fail() || !(Check(FirstName))) { Clear(); cout << "������ �����. ��� �� ������ ��������� ����. \n>"; cin >> FirstName; }
                        choice = 20; break;
                    case 3:
                        cout << "��������: "; cin >> SurName;
                        while (cin.fail() || !(Check(SurName))) { Clear(); cout << "������ �����. �������� �� ������ ��������� ����. \n>"; cin >> SurName; }
                        choice = 20; break;
                    case 4:
                        cout << "���� ��������: "; BirthDate.SetDate();
                        choice = 20; break;
                    case 5:
                        cout << "��� �����������: "; cin >> EnrollmentYear;
                        while (cin.fail() || EnrollmentYear < 1900) { cout << "������ �����. ��� ����������� [>=1900]: "; Clear(); cin >> EnrollmentYear; }
                        choice = 20; break;
                    case 6:
                        cout << "��������: "; cin >> Institute; cin.clear();
                        choice = 20; break;
                    case 7:
                        cout << "�������: "; cin >> Department; cin.clear();
                        choice = 20; break;
                    case 8:
                        cout << "������: "; cin >> Group; cin.clear();
                        choice = 20; break;
                    case 9:
                        cout << "����� �������� ������: "; cin >> RecordBook; Clear();
                        while (RecordBook_search)
                        {
                            ifstream filecheck;
                            filecheck.open("DB.txt", ios::out);
                            is_RecordBook_changed = false;
                            while (getline(filecheck, line))
                            {
                                while (line.find(RecordBook) != string::npos)
                                {
                                    cout << "����� �������� ������ ��� ������������. ������� ������." << endl;
                                    cout << "����� �������� ������: "; cin >> RecordBook; Clear();
                                    is_RecordBook_changed = true;
                                }
                            }
                            filecheck.close();
                            if (is_RecordBook_changed == false) RecordBook_search = false;
                        }
                        choice = 20; RecordBook_changed = true; menu_is_true = false; break;
                    case 10:
                        cout << "��� (�-�������, �-�������): "; cin >> Sex;
                        while (cin.fail() || ((Sex != "�") && (Sex != "�"))) { Clear(); cout << "������ �����. ��� [�/�]: "; cin >> Sex; }
                        choice = 20; break;
                    case 11:
                        session_num = 0; subject_num = 0;
                        while (cin.fail() || session_num < 1 || session_num > numberofSessions)
                        {
                            if (!first_change_sessions) Clear();
                            cout << "��������, ����� ������ �������� [1-" << numberofSessions << "]: "; cin >> session_num; first_change_sessions = false;
                        }
                        session_num--;
                        while (cin.fail() || subject_num < 1 || subject_num > maxnumberofSubjects)
                        {
                            Clear();
                            cout << "�������� ������� ��������, ������� ���� �������� [1-" << maxnumberofSubjects << "]: "; cin >> subject_num;
                        }
                        subject_num--;
                        cout << "�������:\n" << Sessions[session_num][subject_num].subject << ": " << Sessions[session_num][subject_num].mark << endl;
                        if (Sessions[session_num][subject_num].mark == "#" && Sessions[session_num][subject_num - 1].mark == "#") { cout << "������/������� ��� ���������" << endl; system("pause"); }
                        else
                        {
                            cout << "������� �������: "; cin >> Sessions[session_num][subject_num].subject; Clear();
                            cout << "������� ������ [1-5, � - �����, � - �������]: "; cin >> Sessions[session_num][subject_num].mark;
                            while (Sessions[session_num][subject_num].mark != "5" && Sessions[session_num][subject_num].mark != "4" &&
                                Sessions[session_num][subject_num].mark != "3" && Sessions[session_num][subject_num].mark != "2" &&
                                Sessions[session_num][subject_num].mark != "1" && Sessions[session_num][subject_num].mark != "�" &&
                                Sessions[session_num][subject_num].mark != "�")
                            {
                                Clear(); cout << "������� ������ [1-5, � - �����, � - �������]: "; cin >> Sessions[session_num][subject_num].mark;
                            }
                        }
                        choice = 20; break;
                    case 12: numberofSessions++;
                        cout << "���-�� ��������� ��� ������ �" << numberofSessions << " [1-10]: "; cin >> numberofSubjects;
                        while (cin.fail() || numberofSubjects < 1 || numberofSubjects > 10) { cout << "������ �����. ���-�� ��������� [1-10]: "; Clear(); cin >> numberofSubjects; }
                        Clear();
                        if (numberofSubjects > maxnumberofSubjects) maxnumberofSubjects = numberofSubjects;
                        Sessions[numberofSessions - 1] = new Session[numberofSubjects + 1]();
                        for (int j = 0; j < numberofSubjects; j++)
                        {
                            cout << "������� �" << j + 1 << ": "; cin >> Sessions[numberofSessions - 1][j].subject; Clear();
                            cout << "������ �" << j + 1 << " [1-5, � - �����, � - �������]: "; cin >> Sessions[numberofSessions - 1][j].mark;
                            while (cin.fail() || (Sessions[numberofSessions - 1][j].mark != "�" && Sessions[numberofSessions - 1][j].mark != "�" &&
                                Sessions[numberofSessions - 1][j].mark != "5" && Sessions[numberofSessions - 1][j].mark != "4" &&
                                Sessions[numberofSessions - 1][j].mark != "3" && Sessions[numberofSessions - 1][j].mark != "2" && Sessions[numberofSessions - 1][j].mark != "1"))
                            {
                                cout << "������ �����. ������: [1-5, � - �����, � - �������]: "; Clear(); cin >> Sessions[numberofSessions - 1][j].mark;
                            }
                            Clear();
                        }
                        choice = 0;
                        break;
                    }
                }
                system("cls");
                cout << "���������� ������:\n";
                PrintStudent();
                for (int i = 0; i < numberofSessions; i++)
                {
                    cout << "----------������ �" << i + 1 << "----------" << endl;
                    for (int j = 0; j < maxnumberofSubjects; j++)
                    {
                        if (Sessions[i][j].mark == "#") break;
                        cout << Sessions[i][j].subject << ": ";
                        if (Sessions[i][j].mark == "�" || Sessions[i][j].mark == "�")
                        {
                            if (Sessions[i][j].mark == "�") cout << "����� | ";
                            if (Sessions[i][j].mark == "�") cout << "������� | ";
                        }
                        else cout << Sessions[i][j].mark << " | ";
                        if (j == 3 || j == 7) cout << endl;
                    }
                    cout << endl;
                }
                if (!RecordBook_changed)
                {
                    ofstream file_out;
                    file_out.open("DBtemp.txt", ios::app);
                    file_out << LastName << " " << FirstName << " " << SurName << " " << BirthDate.GetInfo("Day") << " "
                        << BirthDate.GetInfo("Month") << " " << BirthDate.GetInfo("Year") << " " << EnrollmentYear << " "
                        << Institute << " " << Department << " " << Group << " " << RecordBook << " " << Sex << " " <<
                        numberofSessions << " " << maxnumberofSubjects << " ";
                    for (int i = 0; i < numberofSessions; i++)
                    {
                        for (int j = 0; j < maxnumberofSubjects; j++)
                        {
                            if (Sessions[i][j].mark == "#") break;
                            file_out << Sessions[i][j].subject << " " << Sessions[i][j].mark << " ";
                        }
                        file_out << "| ";
                    }
                    file_out << endl;
                    file_out.close();
                }
                //if (choice == 0) cout << "��������� �� ���������" << endl;
                /*for (int i = 0; i < numberofSessions; i++) //������
                {
                    delete[] Sessions[i];
                }
                delete[] Sessions;*/
            }
            if (!(RecordBook.find(searchline) != string::npos))
            {
                ofstream file_out_other_students;
                file_out_other_students.open("DBtemp.txt", ios::app);
                file_out_other_students << LastName << " " << FirstName << " " << SurName << " " << BirthDate.GetInfo("Day") << " "
                    << BirthDate.GetInfo("Month") << " " << BirthDate.GetInfo("Year") << " " << EnrollmentYear << " "
                    << Institute << " " << Department << " " << Group << " " << RecordBook << " " << Sex << " " << numberofSessions << " "
                    << maxnumberofSubjects << " ";
                for (int i = 0; i < numberofSessions; i++)
                {
                    for (int j = 0; j < maxnumberofSubjects; j++)
                    {
                        if (Sessions[i][j].mark == "#") break;
                        file_out_other_students << Sessions[i][j].subject << " " << Sessions[i][j].mark << " ";
                    }
                    file_out_other_students << "| ";
                }
                file_out_other_students << endl;
                file_out_other_students.close();
                for (int i = 0; i < numberofSessions; i++)
                {
                    delete[] Sessions[i];
                }
                delete[] Sessions;
            }
            /*for (int i = 0; i < numberofSessions; i++)
            {
                delete[] Sessions[i];
            }
            delete[] Sessions;*/
        }
        file.close();
        remove(_filename);
        rename("DBtemp.txt", _filename);
    }
    void PrintStudent()
    {
        cout << LastName << " " << FirstName << " " << SurName;
        if (Sex == "�" || Sex == "�")
        {
            if (Sex == "�") cout << ", �������";
            if (Sex == "�") cout << ", �������";
        }
        else cout << ", ��� �� ���������";
        cout << " | ";
        cout << "���� ��������: "; BirthDate.PrintDate(); cout << endl;
        cout << "��� �����������: " << EnrollmentYear << " | �������� " << Institute << " | ������� " << Department << endl;
        cout << "������ " << Group << " | ���� " << RecordBook << " " << endl;

    }
    string GetSex() { return Sex; }
    bool Get_three_mark() { return has_three_mark; }
    int GetNumberofSessions() { return numberofSessions; }
    int GetMaxNumberofSubjects() { return maxnumberofSubjects; }
    ~Student() { ; } 
};
