#include <iostream>
using namespace std;
#include <windows.h>

struct Session
{
    string subject;
    int mark;
};
void Clear()
{
    cin.clear(); cin.ignore(INT_MAX, '\n');
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int numberofSessions = 10;       // количество строк
    int numberofSubjects;    // количество столбцов
    int maxnumberofSubjects = -10;
    Session** Sessions = new Session * [numberofSessions];
    cout << "Кол-во сессий [1-10]: "; cin >> numberofSessions;
    while (cin.fail() || numberofSessions < 1 || numberofSessions > 10) { cout << "Ошибка ввода. Кол-во сессий [1-10]: "; Clear(); cin >> numberofSessions; }
    Clear();
    for (int i = 0; i < numberofSessions; i++)
    {
        cout << "Кол-во предметов для сессии №" << i+1 << " [1-10]: "; cin >> numberofSubjects;
        while (cin.fail() || numberofSubjects < 1 || numberofSubjects > 10) { cout << "Ошибка ввода. Кол-во предметов [1-10]: "; Clear(); cin >> numberofSubjects; }
        Clear();
        if (numberofSubjects > maxnumberofSubjects) maxnumberofSubjects = numberofSubjects;
        Sessions[i] = new Session[numberofSubjects];
        for (int j = 0; j < numberofSubjects; j++)
        {
            cout << "Предмет №" << j + 1 << ": "; cin >> Sessions[i][j].subject; Clear();
            cout << "Оценка №" << j + 1 << ": "; cin >> Sessions[i][j].mark;
            while (cin.fail() || Sessions[i][j].mark < 1 || Sessions[i][j].mark > 5) { cout << "Ошибка ввода. Оценка: [1-5]: "; Clear(); cin >> Sessions[i][j].mark; }
            Clear();
        }
    }
    //cout << "Кол-во предметов в каждой сессии [1-10]: "; cin >> numberofSubjects;
    //Session** Sessions{ new Session * [numberofSessions] {} };  // выделяем память под двухмерный массив
    //for (unsigned i{}; i < numberofSessions; i++)
    //{
    //    Sessions[i] = new Session[numberofSubjects] {};
    //}

    // вводим данные для таблицы rows x columns
    // 
    //for (unsigned i{}; i < numberofSessions; i++)
    //{
    //    cout << "Данные для " << (i + 1) << " сессии" << endl;
    //    // вводим данные для столбцов i-й строки
    //    for (unsigned j{}; j < numberofSubjects; j++)
    //    {
    //        cout << (j + 1) << " Предмет/Оценка: ";
    //        cin >> Sessions[i][j].subject >> Sessions[i][j].mark;
    //    }
    //}
    // 
    // вывод данных
    for (int i=0; i < numberofSessions; i++)
    {
        // выводим данные столбцов i-й строки
        for (int j=0; (j < maxnumberofSubjects) && (Sessions[i][j].mark < 6) && (Sessions[i][j].mark > 0); j++)
        {
            cout << Sessions[i][j].subject << ": " << Sessions[i][j].mark << "\t";
        }
        cout << endl;
    }

    for (unsigned i{}; i < numberofSessions; i++)
    {
        delete[] Sessions[i];
    }
    delete[] Sessions;
}