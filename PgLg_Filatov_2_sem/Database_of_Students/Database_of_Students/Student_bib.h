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
        if (st.Sex == "м" || st.Sex == "ж")
        {
            if (st.Sex == "м") os << ", мужчина";
            if (st.Sex == "ж") os << ", женщина";
        }
        else os << ", пол не определен";
        os << " | ";
        os << "Дата рождения: "; st.BirthDate.PrintDate(); os << endl;
        os << "Год поступления: " << st.EnrollmentYear << " | Институт " << st.Institute << " | Кафедра " << st.Department << endl;
        os << "Группа " << st.Group << " | Шифр " << st.RecordBook << " " << endl;
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
        cout << "Фамилия: "; cin >> LastName;
        while (cin.fail() || !(Check(LastName))) { Clear(); cout << "Ошибка ввода. Фамилия не должна содержать цифр. \n>"; cin >> LastName; }
        Clear(); 
        cout << "Имя: "; cin >> FirstName;
        while (cin.fail() || !(Check(FirstName))) { Clear(); cout << "Ошибка ввода. Имя не должно содержать цифр. \n>"; cin >> FirstName; }
        Clear(); 
        cout << "Отчество: "; cin >> SurName;
        while (cin.fail() || !(Check(SurName))) { Clear(); cout << "Ошибка ввода. Отчество не должно содержать цифр. \n>"; cin >> SurName; }
        Clear(); 
        cout << "Дата рождения: "; BirthDate.SetDate();
        cout << "Год поступления: "; cin >> EnrollmentYear;
        while (cin.fail() || EnrollmentYear < 1900) { cout << "Ошибка ввода. Год поступления [>=1900]: "; Clear(); cin >> EnrollmentYear; }
        Clear();
        cout << "Институт: "; cin >> Institute; Clear();
        cout << "Кафедра: "; cin >> Department; Clear();
        cout << "Группа: "; cin >> Group; Clear();
        cout << "Номер зачетной книжки: "; cin >> RecordBook; Clear();

        while (RecordBook_search)
        {
            file.open("DB.txt", ios::out);
            count = false;
            while (getline(file, line))
            {
                while (line.find(RecordBook) != string::npos)
                {
                    cout << "Номер зачетной книжки уже используется. Введите другой." << endl;
                    cout << "Номер зачетной книжки: "; cin >> RecordBook; Clear();
                    count = true;
                }
            }
            file.close();
            if (count == false) RecordBook_search = false;
        }

        cout << "Пол (м-мужчина, ж-женщина): "; cin >> Sex;
        while (cin.fail() || ((Sex != "м") && (Sex != "ж"))) { Clear(); cout << "Ошибка ввода. Пол [м/ж]: "; cin >> Sex; }
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
        cout << "Кол-во сессий [1-9]: "; cin >> numberofSessions;
        while (cin.fail() || numberofSessions < 1 || numberofSessions > 9) { cout << "Ошибка ввода. Кол-во сессий [1-9]: "; Clear(); cin >> numberofSessions; }
        Clear();
        Session** Sessions = new Session * [numberofSessions];

        for (int i = 0; i < numberofSessions; i++)
        {
            cout << "Кол-во предметов для сессии №" << i + 1 << " [1-10]: "; cin >> numberofSubjects;
            while (cin.fail() || numberofSubjects < 1 || numberofSubjects > 10) { cout << "Ошибка ввода. Кол-во предметов [1-10]: "; Clear(); cin >> numberofSubjects; }
            Clear();
            if (numberofSubjects > maxnumberofSubjects) maxnumberofSubjects = numberofSubjects;
            Sessions[i] = new Session[10]();
            for (int j = 0; j < numberofSubjects; j++)
            {
                cout << "Предмет №" << j + 1 << ": "; cin >> Sessions[i][j].subject; Clear();
                cout << "Оценка №" << j + 1 << " [1-5, з - зачет, н - незачет]: "; cin >> Sessions[i][j].mark;
                while (cin.fail() || (Sessions[i][j].mark != "з" && Sessions[i][j].mark != "н" &&
                    Sessions[i][j].mark != "5" && Sessions[i][j].mark != "4" && Sessions[i][j].mark != "3" && Sessions[i][j].mark != "2" && Sessions[i][j].mark != "1"))
                {
                    cout << "Ошибка ввода. Оценка: [1-5, з - зачет, н - незачет]: "; Clear(); cin >> Sessions[i][j].mark;
                }
                Clear();
            }
        }
        string choice = "z";
        while (cin.fail() || (choice != "1" && choice != "0"))
        {
            system("cls");
            cout << "Введенные данные: "; PrintStudent();
            for (int i = 0; i < numberofSessions; i++)
            {
                cout << "----------СЕССИЯ №" << i + 1 << "----------" << endl;
                for (int j = 0; j < maxnumberofSubjects; j++)
                {
                    if (Sessions[i][j].mark == "#") break;
                    cout << Sessions[i][j].subject << ": ";
                    if (Sessions[i][j].mark == "з" || Sessions[i][j].mark == "н")
                    {
                        if (Sessions[i][j].mark == "з") cout << "зачёт | ";
                        if (Sessions[i][j].mark == "н") cout << "незачёт | ";
                    }
                    else  if (stoi(Sessions[i][j].mark) > 0 && stoi(Sessions[i][j].mark) < 6) cout << Sessions[i][j].mark << " | ";
                    if (j == 3 || j == 7) cout << endl;
                }
                cout << endl;
            }

            cout << "Хотите записать данные в файл?\n 1 - Да.\n 0 - Нет.\n> ";
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
            if (choice == "0") { cout << "Данные не записаны. " << endl; }
            if (choice != "1" && choice != "0") { Clear(); system("cls"); cout << "Ошибка ввода. " << endl; }
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

        cout << "Введите номер зачетной книжки студента: "; cin >> searchline;
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
                    cout << "----------СЕССИЯ №" << i + 1 << "----------" << endl;
                    for (int j = 0; j < maxnumberofSubjects; j++)
                    {
                        if (Sessions[i][j].mark == "#") break;
                        cout << Sessions[i][j].subject << ": ";
                        if (Sessions[i][j].mark == "з" || Sessions[i][j].mark == "н")
                        {
                            if (Sessions[i][j].mark == "з") cout << "зачёт | ";
                            if (Sessions[i][j].mark == "н") cout << "незачёт | ";
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
        cout << "Введите номер зачетной книжки студента: "; cin >> searchline;
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

                    cout << "----------СЕССИЯ №" << i + 1 << "----------" << endl;
                    for (int j = 0; j < maxnumberofSubjects; j++)
                    {
                        if (Sessions[i][j].mark == "#") break;
                        cout << Sessions[i][j].subject << ": ";
                        if (Sessions[i][j].mark == "з" || Sessions[i][j].mark == "н")
                        {
                            if (Sessions[i][j].mark == "з") cout << "зачёт ";
                            if (Sessions[i][j].mark == "н") cout << "незачёт ";
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
        cout << "Введите номер зачетной книжки студента: "; cin >> searchline;
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
                cout << "Выбранные для удаления данные: " << endl; PrintStudent();
                for (int i = 0; i < numberofSessions; i++)
                {
                    cout << "----------СЕССИЯ №" << i + 1 << "----------" << endl;
                    for (int j = 0; j < maxnumberofSubjects; j++)
                    {
                        if (Sessions[i][j].mark == "#") break;
                        cout << Sessions[i][j].subject << ": ";
                        if (Sessions[i][j].mark == "з" || Sessions[i][j].mark == "н")
                        {
                            if (Sessions[i][j].mark == "з") cout << "зачёт | ";
                            if (Sessions[i][j].mark == "н") cout << "незачёт | ";
                        }
                        else cout << Sessions[i][j].mark << " | ";
                        if (j == 3 || j == 7) cout << endl;
                    }
                    cout << endl;
                }
                cout << "Вы уверены, что хотите удалить данные?\n 1. Удалить.\n 0. Отмена.\n> ";
                cin >> deleting_choice;
                while (cin.fail() || (deleting_choice != 0 && deleting_choice != 1))
                {
                    Clear(); system("cls");
                    cout << "Ошибка ввода.\nВы уверены, что хотите удалить данные?\n 1. Удалить.\n 0. Отмена.\n> "; cin >> deleting_choice;
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
            cout << "Данные не удалены." << endl;
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
            cout << "Данные удалены." << endl;
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
        cout << "Введите номер зачетной книжки студента: "; cin >> searchline;
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
                        cout << "Выбранный студент: " << endl; PrintStudent();
                        for (int i = 0; i < numberofSessions; i++)
                        {
                            cout << "----------СЕССИЯ №" << i + 1 << "----------" << endl;
                            for (int j = 0; j < maxnumberofSubjects; j++)
                            {
                                if (Sessions[i][j].mark == "#") break;
                                cout << Sessions[i][j].subject << ": ";
                                if (Sessions[i][j].mark == "з" || Sessions[i][j].mark == "н")
                                {
                                    if (Sessions[i][j].mark == "з") cout << "зачёт | ";
                                    if (Sessions[i][j].mark == "н") cout << "незачёт | ";
                                }
                                else cout << Sessions[i][j].mark << " | ";
                                if (j == 3 || j == 7) cout << endl;
                            }
                            cout << endl;
                        }
                        cout << "Какие данные нужно изменить?\n1.  Фамилию\n2.  Имя\n3.  Отчество\n4.  Дату рождения\n5.  Год поступления\n6.  Институт\n7.  Кафедру\n8.  Группу\n9.  ";
                        cout << "Номер зачетной книжки\n10. Пол\n11. Имеющиеся сессии\n12. Добавить сессию\n0.  Подтвердить\n>>> ";
                        cin >> choice;
                    }
                    Clear();
                    switch (choice)
                    {
                        system("cls");
                    case 0: menu_is_true = false; break;
                    case 1:
                        cout << "Фамилия: "; cin >> LastName;
                        while (cin.fail() || !(Check(LastName))) { Clear(); cout << "Ошибка ввода. Фамилия не должна содержать цифр. \n>"; cin >> LastName; }
                        choice = 20; break;
                    case 2:
                        cout << "Имя: "; cin >> FirstName;
                        while (cin.fail() || !(Check(FirstName))) { Clear(); cout << "Ошибка ввода. Имя не должно содержать цифр. \n>"; cin >> FirstName; }
                        choice = 20; break;
                    case 3:
                        cout << "Отчество: "; cin >> SurName;
                        while (cin.fail() || !(Check(SurName))) { Clear(); cout << "Ошибка ввода. Отчество не должно содержать цифр. \n>"; cin >> SurName; }
                        choice = 20; break;
                    case 4:
                        cout << "Дата рождения: "; BirthDate.SetDate();
                        choice = 20; break;
                    case 5:
                        cout << "Год поступления: "; cin >> EnrollmentYear;
                        while (cin.fail() || EnrollmentYear < 1900) { cout << "Ошибка ввода. Год поступления [>=1900]: "; Clear(); cin >> EnrollmentYear; }
                        choice = 20; break;
                    case 6:
                        cout << "Институт: "; cin >> Institute; cin.clear();
                        choice = 20; break;
                    case 7:
                        cout << "Кафедра: "; cin >> Department; cin.clear();
                        choice = 20; break;
                    case 8:
                        cout << "Группа: "; cin >> Group; cin.clear();
                        choice = 20; break;
                    case 9:
                        cout << "Номер зачетной книжки: "; cin >> RecordBook; Clear();
                        while (RecordBook_search)
                        {
                            ifstream filecheck;
                            filecheck.open("DB.txt", ios::out);
                            is_RecordBook_changed = false;
                            while (getline(filecheck, line))
                            {
                                while (line.find(RecordBook) != string::npos)
                                {
                                    cout << "Номер зачетной книжки уже используется. Введите другой." << endl;
                                    cout << "Номер зачетной книжки: "; cin >> RecordBook; Clear();
                                    is_RecordBook_changed = true;
                                }
                            }
                            filecheck.close();
                            if (is_RecordBook_changed == false) RecordBook_search = false;
                        }
                        choice = 20; RecordBook_changed = true; menu_is_true = false; break;
                    case 10:
                        cout << "Пол (м-мужчина, ж-женщина): "; cin >> Sex;
                        while (cin.fail() || ((Sex != "м") && (Sex != "ж"))) { Clear(); cout << "Ошибка ввода. Пол [м/ж]: "; cin >> Sex; }
                        choice = 20; break;
                    case 11:
                        session_num = 0; subject_num = 0;
                        while (cin.fail() || session_num < 1 || session_num > numberofSessions)
                        {
                            if (!first_change_sessions) Clear();
                            cout << "Выберите, какую сессию изменить [1-" << numberofSessions << "]: "; cin >> session_num; first_change_sessions = false;
                        }
                        session_num--;
                        while (cin.fail() || subject_num < 1 || subject_num > maxnumberofSubjects)
                        {
                            Clear();
                            cout << "Выберите позицию предмета, который надо изменить [1-" << maxnumberofSubjects << "]: "; cin >> subject_num;
                        }
                        subject_num--;
                        cout << "Выбрано:\n" << Sessions[session_num][subject_num].subject << ": " << Sessions[session_num][subject_num].mark << endl;
                        if (Sessions[session_num][subject_num].mark == "#" && Sessions[session_num][subject_num - 1].mark == "#") { cout << "Сессия/предмет вне диапазона" << endl; system("pause"); }
                        else
                        {
                            cout << "Введите предмет: "; cin >> Sessions[session_num][subject_num].subject; Clear();
                            cout << "Введите оценку [1-5, з - зачет, н - незачет]: "; cin >> Sessions[session_num][subject_num].mark;
                            while (Sessions[session_num][subject_num].mark != "5" && Sessions[session_num][subject_num].mark != "4" &&
                                Sessions[session_num][subject_num].mark != "3" && Sessions[session_num][subject_num].mark != "2" &&
                                Sessions[session_num][subject_num].mark != "1" && Sessions[session_num][subject_num].mark != "з" &&
                                Sessions[session_num][subject_num].mark != "н")
                            {
                                Clear(); cout << "Введите оценку [1-5, з - зачет, н - незачет]: "; cin >> Sessions[session_num][subject_num].mark;
                            }
                        }
                        choice = 20; break;
                    case 12: numberofSessions++;
                        cout << "Кол-во предметов для сессии №" << numberofSessions << " [1-10]: "; cin >> numberofSubjects;
                        while (cin.fail() || numberofSubjects < 1 || numberofSubjects > 10) { cout << "Ошибка ввода. Кол-во предметов [1-10]: "; Clear(); cin >> numberofSubjects; }
                        Clear();
                        if (numberofSubjects > maxnumberofSubjects) maxnumberofSubjects = numberofSubjects;
                        Sessions[numberofSessions - 1] = new Session[numberofSubjects + 1]();
                        for (int j = 0; j < numberofSubjects; j++)
                        {
                            cout << "Предмет №" << j + 1 << ": "; cin >> Sessions[numberofSessions - 1][j].subject; Clear();
                            cout << "Оценка №" << j + 1 << " [1-5, з - зачет, н - незачет]: "; cin >> Sessions[numberofSessions - 1][j].mark;
                            while (cin.fail() || (Sessions[numberofSessions - 1][j].mark != "з" && Sessions[numberofSessions - 1][j].mark != "н" &&
                                Sessions[numberofSessions - 1][j].mark != "5" && Sessions[numberofSessions - 1][j].mark != "4" &&
                                Sessions[numberofSessions - 1][j].mark != "3" && Sessions[numberofSessions - 1][j].mark != "2" && Sessions[numberofSessions - 1][j].mark != "1"))
                            {
                                cout << "Ошибка ввода. Оценка: [1-5, з - зачет, н - незачет]: "; Clear(); cin >> Sessions[numberofSessions - 1][j].mark;
                            }
                            Clear();
                        }
                        choice = 0;
                        break;
                    }
                }
                system("cls");
                cout << "Измененные данные:\n";
                PrintStudent();
                for (int i = 0; i < numberofSessions; i++)
                {
                    cout << "----------СЕССИЯ №" << i + 1 << "----------" << endl;
                    for (int j = 0; j < maxnumberofSubjects; j++)
                    {
                        if (Sessions[i][j].mark == "#") break;
                        cout << Sessions[i][j].subject << ": ";
                        if (Sessions[i][j].mark == "з" || Sessions[i][j].mark == "н")
                        {
                            if (Sessions[i][j].mark == "з") cout << "зачёт | ";
                            if (Sessions[i][j].mark == "н") cout << "незачёт | ";
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
                //if (choice == 0) cout << "Изменения не сохранены" << endl;
                /*for (int i = 0; i < numberofSessions; i++) //ОШИБКА
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
        if (Sex == "м" || Sex == "ж")
        {
            if (Sex == "м") cout << ", мужчина";
            if (Sex == "ж") cout << ", женщина";
        }
        else cout << ", пол не определен";
        cout << " | ";
        cout << "Дата рождения: "; BirthDate.PrintDate(); cout << endl;
        cout << "Год поступления: " << EnrollmentYear << " | Институт " << Institute << " | Кафедра " << Department << endl;
        cout << "Группа " << Group << " | Шифр " << RecordBook << " " << endl;

    }
    string GetSex() { return Sex; }
    bool Get_three_mark() { return has_three_mark; }
    int GetNumberofSessions() { return numberofSessions; }
    int GetMaxNumberofSubjects() { return maxnumberofSubjects; }
    ~Student() { ; } 
};
