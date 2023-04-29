// Кузнецов Алексей, БАСО-04-22. Курсовая работа. Вариант 34.
// 11.04.2023 22:40
// 15.04.2023 18:45
// 23.04.2023

#include <iostream>
using namespace std;
#include <windows.h>
//#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include "Session.h"


bool Check(string _word) // проверка, есть ли в слове цифры
{
    string int_alphabet = "0123456789";
    for (int i = 0; i < _word.length(); i++)
    {
        for (int j = 0; j < int_alphabet.length(); j++)
            if (_word[i] == int_alphabet[j]) { return false; }
    }
    return true;
}
void Clear() // очистка буфера
{
    cin.clear(); cin.ignore(INT_MAX, '\n'); 
}
class Date
{
    //int Day, Month, Year;
public:
    int Day, Month, Year;
    Date() // конструктор по умолчанию
    {
        Day = 0; Month = 0; Year = 0;
    }
    Date(int _Day, int _Month, int _Year)
    {
        Day = _Day; Month = _Month; Year = _Year;
    }
    void SetDate(int _Day, int _Month, int _Year) // ввод
    {
        Day = _Day; Month = _Month; Year = _Year;
    }
    void SetDate(Date Date) // ввод
    {
        SetDate(Date.Day, Date.Month, Date.Year);
    }
    void SetDate() // ввод с клавиатуры
    {
        cout << "День: "; cin >> Day;
        while (cin.fail() || Day > 31 || Day < 1)
        {
            cout << "Ошибка ввода. День [1-31]: "; Clear(); cin >> Day; // очистка буфера в случае неправильного ввода
        }
        Clear(); // очистка буфера
        cout << "Месяц: "; cin >> Month;
        while (cin.fail() || Month > 12 || Month < 1)
        {
            cout << "Ошибка ввода. Месяц [1-12]: "; Clear(); cin >> Month; // очистка буфера в случае неправильного ввода
        }
        Clear(); // очистка буфера
        cout << "Год: "; cin >> Year;
        while (cin.fail() || Year < 1900 || Year > 2023)
        {
            cout << "Ошибка ввода. Год [1900-2023]: "; Clear(); cin >> Year; // очистка буфера в случае неправильного ввода
        }
        Clear(); // очистка буфера
    }
    void SetDateFromFile()
    {
        ifstream file;
        file.open("DB.txt", ios::out);
        file >> Day >> Month >> Year; 
        file.close();
    }
    int GetDay() { return Day; }
    int GetMonth() { return Month; }
    int GetYear() { return Year; }
    int GetInfo(string _info) 
    {
        if (_info == "Day") return Day;
        if (_info == "Month") return Month;
        if (_info == "Year") return Year;
    }
    
    void InputInFile(const char _filename[])
    {
        FILE* file;
        fopen_s(&file, _filename, "a");
        fprintf(file, "%d %d %d ", Day, Month, Year);
        fclose(file);
    }
    void InputInFile()
    {
        FILE* file;
        fopen_s(&file, "DB.txt", "a");
        fprintf(file, "%d %d %d ", Day, Month, Year);
        fclose(file);
    }
    //int GetDate()
    //{
    //    //Date GD; GD.Day = Day; GD.Month = Month; GD.Year = Year;
    //    return Day, Month, Year;
    //}
    void PrintDate() // вывод значений
    {
        cout << Day << " " << Month << " " << Year;
    }
    ~Date() { ; } // деструктор
}; 

class Student
{
    string LastName, FirstName, SurName; // ФИО
    Date BirthDate; // Дата рождения
    int EnrollmentYear; // Год поступления
    string Institute, Department, Group, RecordBook; // Институт, кафедра, группа, номер зачетной книжки (шифр)
    string Sex; // Пол. м = мужчина, ж = женщина
    int numberofSessions, numberofSubjects, maxnumberofSubjects = -10;
    //Session **Sessions = new Session*[numberofSessions];
    //for (int i = 0; i < numberofSessions; i++) { Sessions[i] = new Session[numberofSubjects] };
    
public:
    Student() // конструктор по умолчанию
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
    void SetStudent(string _LastName, string _FirstName, string _SurName, Date _BirthDate, int _EnrollmentYear,
        string _Institute, string _Department, string _Group, string _RecordBook, string _Sex)
    {
        LastName = _LastName; FirstName = _FirstName; SurName = _SurName;
        BirthDate.SetDate(_BirthDate); EnrollmentYear = _EnrollmentYear;
        Institute = _Institute; Department = _Department; Group = _Group; RecordBook = _RecordBook; 
        Sex = _Sex;
    }

    void SetStudent() // ввод с клавиатуры
    {
        cout << "Фамилия: "; cin >> LastName;
        while (cin.fail() || !(Check(LastName))) { Clear(); cout << "Ошибка ввода. Фамилия не должна содержать цифр. \n>"; cin >> LastName; }
        Clear(); // очистка буфера
        cout << "Имя: "; cin >> FirstName;
        while (cin.fail() || !(Check(FirstName))) { Clear(); cout << "Ошибка ввода. Имя не должно содержать цифр. \n>"; cin >> FirstName; }
        Clear(); // очистка буфера
        cout << "Отчество: "; cin >> SurName;
        while (cin.fail() || !(Check(SurName))) { Clear(); cout << "Ошибка ввода. Отчество не должно содержать цифр. \n>"; cin >> SurName; }
        Clear(); // очистка буфера
        cout << "Дата рождения: "; BirthDate.SetDate();
        cout << "Год поступления: "; cin >> EnrollmentYear;
        while (cin.fail() || EnrollmentYear < 1900) { cout << "Ошибка ввода. Год поступления [>=1900]: "; Clear(); cin >> EnrollmentYear; }
        Clear();
        cout << "Институт: "; cin >> Institute; Clear();
        cout << "Кафедра: "; cin >> Department; Clear();
        cout << "Группа: "; cin >> Group; Clear();
        cout << "Номер зачетной книжки: "; cin >> RecordBook; Clear();
        cout << "Пол (м-мужчина, ж-женщина): "; cin >> Sex;
        while (cin.fail() || ((Sex != "м") && (Sex != "ж"))) { Clear(); cout << "Ошибка ввода. Пол [м/ж]: "; cin >> Sex; }
        Clear();
        //cout << "Кол-во сессий [1-10]: "; cin >> numberofSessions;
        //while (cin.fail() || numberofSessions < 1 || numberofSessions > 10) { cout << "Ошибка ввода. Кол-во сессий [1-10]: "; Clear(); cin >> numberofSessions; }
        //Clear();
        //Session** Sessions = new Session * [numberofSessions];
        ////for (int i = 0; i < numberofSessions; i++) { Sessions[i] = new Session[numberofSubjects]; }

        //for (int i = 0; i < numberofSessions; i++)
        //{
        //    cout << "Кол-во предметов для сессии №" << i + 1 << " [1-10]: "; cin >> numberofSubjects;
        //    while (cin.fail() || numberofSubjects < 1 || numberofSubjects > 10) { cout << "Ошибка ввода. Кол-во предметов [1-10]: "; Clear(); cin >> numberofSubjects; }
        //    Clear();
        //    if (numberofSubjects > maxnumberofSubjects) maxnumberofSubjects = numberofSubjects;
        //    Sessions[i] = new Session[numberofSubjects];
        //    for (int j = 0; j < numberofSubjects; j++)
        //    {
        //        cout << "Предмет №" << j + 1 << ": "; cin >> Sessions[i][j].subject; Clear();
        //        cout << "Оценка №" << j + 1 << ": "; cin >> Sessions[i][j].mark;
        //        while (cin.fail() || Sessions[i][j].mark < 1 || Sessions[i][j].mark > 5) { cout << "Ошибка ввода. Оценка: [1-5]: "; Clear(); cin >> Sessions[i][j].mark; }
        //        Clear();
        //    }
        //}
    }

    //void InputInFile()
    //{

    //    FILE* file;
    //    //ofstream wf("DB.txt", ios::out | ios::app);
    //    /*wf.write((char*)&LastName(sizeof(Student));
    //    wf.close();*/
    //    //"DB.txt" << LastName;
    //    fopen_s(&file, "DB.txt", "a");
    //    fprintf_s(file, "%s %s %s ", LastName, FirstName, SurName);
    //    //BirthDate.InputInFile();
    //    fprintf(file, "%d %s %s %s %s %s \n", EnrollmentYear, Institute, Department, Group, RecordBook, Sex);
    //    fclose(file);
    //}

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
        cout << "Кол-во сессий [1-10]: "; cin >> numberofSessions;
        while (cin.fail() || numberofSessions < 1 || numberofSessions > 10) { cout << "Ошибка ввода. Кол-во сессий [1-10]: "; Clear(); cin >> numberofSessions; }
        Clear();
        Session** Sessions = new Session * [numberofSessions];
        //for (int i = 0; i < numberofSessions; i++) { Sessions[i] = new Session[numberofSubjects]; }

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
                while (cin.fail() /*|| stoi(Sessions[i][j].mark) < 1 || stoi(Sessions[i][j].mark) > 5*/ || (Sessions[i][j].mark != "з" && Sessions[i][j].mark != "н" &&
                    Sessions[i][j].mark != "5" && Sessions[i][j].mark != "4" && Sessions[i][j].mark != "3" && Sessions[i][j].mark != "2" && Sessions[i][j].mark != "1"))
                { cout << "Ошибка ввода. Оценка: [1-5, з - зачет, н - незачет]: "; Clear(); cin >> Sessions[i][j].mark; }
                Clear();
            }
        }
        string choice = "z";
        while (cin.fail() || (choice != "1" && choice != "0"))
        {
            cout << "Введенные данные: " << LastName << " " << FirstName << " " << SurName << " " << BirthDate.GetInfo("Day") << " "
                << BirthDate.GetInfo("Month") << " " << BirthDate.GetInfo("Year") << " " << EnrollmentYear << " "
                << Institute << " " << Department << " " << Group << " " << RecordBook << " " << Sex << endl;
            //Session** Sessions = new Session * [numberofSessions];
            for (int i = 0; i < numberofSessions; i++)
            {
                cout << "----------СЕССИЯ №" << i+1 << "----------" << endl;
                //Sessions[i] = new Session[numberofSubjects];
                for (int j = 0; j < maxnumberofSubjects; j++)
                {
                    if (Sessions[i][j].mark == "#") break;
                    cout << Sessions[i][j].subject << ": "; 
                    if (Sessions[i][j].mark == "з" || Sessions[i][j].mark == "н")
                    {
                        if (Sessions[i][j].mark == "з") cout << "зачёт ";
                        if (Sessions[i][j].mark == "н") cout << "незачёт ";
                    }
                    else  if (stoi(Sessions[i][j].mark)>0 && stoi(Sessions[i][j].mark)<6) cout << Sessions[i][j].mark << " ";
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
                    //cout << endl;
                }
                file << endl;
                file.close();
            }
            if (choice == "0") { cout << "Данные не записаны. " << endl; }
            if (choice != "1" && choice != "0") { Clear(); system("cls"); cout << "Ошибка ввода. " << endl; }
        }
        Clear();
    }
    /*void OutputFromFile(const char _filename[])
    {
        ifstream file;
        string line, searchline;
        cout << "Введите номер зачетной книжки студента: "; cin >> searchline; 
        file.open(_filename, ios::out);
        while (getline(file, line)) 
        {
            if (line.find(searchline) != string::npos)
            {
                cout << line << endl;
            }
        }
        file.close();
    }*/
    void OutputFromFile(const char _filename[])
    {
        ifstream file;
        string searchline, bufer;
        
        cout << "Введите номер зачетной книжки студента: "; cin >> searchline;
        file.open(_filename, ios::in);
        while (file >> LastName >> FirstName >> SurName >> BirthDate.Day >> BirthDate.Month >> BirthDate.Year >>
            EnrollmentYear >> Institute >> Department >> Group >> RecordBook >> Sex >> numberofSessions >> maxnumberofSubjects)
        {
            Session** Sessions = new Session * [numberofSessions];
            for (int i=0; i<numberofSessions; i++)
            {
                Sessions[i] = new Session[maxnumberofSubjects];
            }
            for (int i = 0; i < numberofSessions; i++)
            {
                for (int j = 0; j < maxnumberofSubjects+1; j++)
                {
                    file >> bufer;
                    if (bufer == "|") break;
                    Sessions[i][j].subject = bufer;
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
                            if (Sessions[i][j].mark == "з") cout << "зачёт ";
                            if (Sessions[i][j].mark == "н") cout << "незачёт ";
                        }
                        else cout << Sessions[i][j].mark << " ";
                    }
                    cout << endl;
                }

            }
            
        }
        file.close();
    }
    void OutputFromFile(const char _filename[], int o)
    {
        ifstream file;
        string line, searchline, bufer;
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
                for (int j = 0; j < maxnumberofSubjects+1; j++)
                {
                    ss >> bufer;
                    if (bufer == "|") break;
                    //if (bufer == "|") continue;
                    //if (bufer == "|" && numberofSessions == maxnumberofSubjects) ss >> bufer;
                    //if (bufer == "|" && numberofSessions != maxnumberofSubjects) break;
                    //if (bufer == "|" && j == maxnumberofSubjects-1) ss >> bufer;
                    //if (bufer == "|" && j != maxnumberofSubjects-1) continue;
                    Sessions[i][j].subject = bufer;
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
        }
        file.close();
    }
    void DeleteInfo(const char _filename[])
    {
        ifstream file;
        string bufer, line, searchline;
        int deleting_choice = 0;
        cout << "Введите номер зачетной книжки студента: "; cin >> searchline;
        file.open(_filename, ios::in);
        while (file >> LastName >> FirstName >> SurName >> BirthDate.Day >> BirthDate.Month >> BirthDate.Year >>
            EnrollmentYear >> Institute >> Department >> Group >> RecordBook >> Sex >> numberofSessions >> maxnumberofSubjects )
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
                            if (Sessions[i][j].mark == "з") cout << "зачёт ";
                            if (Sessions[i][j].mark == "н") cout << "незачёт ";
                        }
                        else cout << Sessions[i][j].mark << " ";
                    }
                    cout << endl;
                }
            DELETING_CHOICE_INPUT:cout << "Вы уверены, что хотите удалить данные?\n 1. Удалить.\n 0. Отмена." << endl;
                cin >> deleting_choice;
                if (!(deleting_choice >= 0 && deleting_choice <= 1))
                {
                    cout << "Ошибка ввода.\n"; Clear(); goto DELETING_CHOICE_INPUT;
                }
            }
        }
        switch(deleting_choice)
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
                        //cout << endl;
                    }
                    file_out << endl;
                    file_out.close();
                }
            }
            file.close();
            remove(_filename);
            rename("DBtemp.txt", _filename);
            cout << "Данные удалены." << endl;
        }
        
        
    }
    void ChangeInfo()
    {
        //
    }
    void PrintStudent() // вывод значений
    {
        cout << LastName << " " << FirstName << " " << SurName << " "; 
        BirthDate.PrintDate(); cout << " " << EnrollmentYear << " " << Institute << " " << Department << " " << Group << " " << RecordBook << " " << Sex << endl;
        //Session** Sessions = new Session * [numberofSessions];
        //for (int i = 0; i < numberofSessions; i++)
        //{
        //    cout << "----------СЕССИЯ №" << i+1 << "----------" << endl;
        //    //Sessions[i] = new Session[numberofSubjects];
        //    for (int j = 0; (j < maxnumberofSubjects) && (Sessions[i][j].mark < 6) && (Sessions[i][j].mark > 0); j++)
        //    {
        //        cout << Sessions[i][j].subject << ": " << Sessions[i][j].mark << "\t";
        //    }
        //    cout << endl;
        //}
    }
    ~Student() { ; } // деструктор
};

int main()
{
    SetConsoleCP(1251); //rus
    SetConsoleOutputCP(1251); //rus
    //FILE* file;
    /*fopen_s(&file, "DB.txt", "w");
    fclose(file);*/
    int choice;
start:cout << "Выберите операцию из нижеперечисленных. \n 1. Добавить запись о студенте в файл.\n 2. Отобразить данные о выбранном студенте.\n 3. Изменить данные студента.\n";
    cout << " 4. Удалить данные студента.\n 5. Выполнить ...задание...\n 0. Выход из программы" << endl;
    cout << "Выберите операцию: ";
    cin >> choice;
    while (cin.fail() || choice < 0 || choice > 5) // проверка на допустимость значения
    {
        cout << "Ошибка ввода. Выберите операцию [0-5]: "; Clear(); cin >> choice; // очистка буфера в случае неправильного ввода и возврат к началу ввода
    }
    Clear();
    //cout << endl << choice;
    Student A1; A1.SetStudent("zhemerikin", "max", "alexeevich", { 25,10,2004 }, 2022, "Кибербезопасности", "КБ-1", "БАСО-04-22", "22Б034", "м");
    //A1.PrintStudent();
    //A1.InputInFile("DB.txt");
    //fopen_s(&file, "DB.txt", "a");
    //fprintf(file, "%d ", 1478);
    //Date SALAM(25, 10, 2004);
    //SALAM.InputInFile("АРТЕМ ЭМ АЛЕКСАНДРОВИЧ.txt");
    //A1.InputInFile(); 
    //fclose(file);
    
    //Date B; B.SetDate(); B.PrintDate();
    //int C;
    //Student A2; A2.SetStudent(); A2.PrintStudent();
    //cout << "get date B: "; C = B.GetInfo("Day"); cout << C; C = B.GetInfo("Month"); cout << C;
    Student InputStudent;
    Student OutputStudent;
    switch (choice) 
    {
    case 1:
        system("cls");
        cout << "Добавить запись о студенте: " << endl;
        InputStudent.SetStudent(); InputStudent.InputInFile("DB.txt");
        system("pause");
        system("cls");
        goto start;
        break;
    case 2:
        system("cls");
        OutputStudent.OutputFromFile("DB.txt");
        system("pause");
        system("cls");
        goto start;
        break;
    case 3:
        system("cls");

        system("pause");
        system("cls");
        goto start;
        break;
    case 4:
        system("cls");
        OutputStudent.DeleteInfo("DB.txt");
        system("pause");
        system("cls");
        goto start;
        break;
    case 5:
        system("cls");

        system("pause");
        system("cls");
        goto start;
        break;
    case 0:
        //goto start;
        return 0;
        break;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
