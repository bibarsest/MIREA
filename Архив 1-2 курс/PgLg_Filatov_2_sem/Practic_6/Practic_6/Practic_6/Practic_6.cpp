﻿// Разработать программу, которая вводит фактические данные из таблицы,
//представленной в Вашем варианте индивидуального задания и выводит на экран таблицу,
//подобную той, которая находится в индивидуальном задании(включая заголовок и
//примечания)
// Поменять местами записи (элементы массива структур), содержащие
//минимальный и максимальный номер месяца даты
// Вариант 4 для 0-ой практики
// Вариант 3 для 1-ой практики
// Студент Кузнецов Алексей Александрович
// Группа БАСО-04-22

#include <iostream>
using namespace std;
//#include <locale.h> //русский
#include <windows.h> //русский
#include <stdio.h>
#include <fstream>
#include <string>

int n = 98; //max ширина таблицы
const int name = 17, company = 18, parts = 30, price = 15, date = 18; //длины полей таблицы
int num; //switch для 0 практики
void DrawLine() //функция для строки, состоящей из тире
{
    //for (int i=0; i < n; i++)
    //{
    //    if (i == 0) { cout << "|"; i++; } //первый элемент
    //    if (i == n-1) { cout << "|"; } //последний элемент
    //    else cout << "-"; //между первым и последним
    //}
    //cout << endl; //переход на след. строчку
    cout.width(n); cout.fill('-'); cout << left << "|"; cout << "|" << endl; cout.fill(' ');
}
void DrawLineWithSections()
{
    cout.fill('-'); cout.width(name); cout << left << "|"; cout.width(company); cout << left << "|"; cout.width(parts); cout << left << "|"; cout.width(price); cout << left << "|"; cout.width(date); cout << left << "|"; cout << "|" << endl;
}
void Preset() //шапка программы
{
    cout.width(n); cout << left << "| Офисные пакеты"; cout << "|" << endl;
    DrawLine();
    cout.width(name); cout << left << "| Наименование";
    cout.width(company); cout << left << "| Производитель";
    cout.width(parts); cout << left << "| Количество сост. частей";
    cout.width(price); cout << left << "| Цена ($)";
    cout.width(date); cout << left << "| Дата релиза"; cout << "|" << endl;
}

struct Date
{
    int Day;
    int Month;
    int Year;
};

struct Record
{
    char Name[name];
    char Company[company];
    int Parts;
    float Price;
    struct Date RDate;
};

//struct Lines line;
void Clear()
{
    cin.clear(); cin.ignore(INT_MAX, '\n');
}
char lines1[name], lines2[company]; int lines3, lines4;
char lines5[name], lines6[company]; int lines7, lines8;
char lines9[name], lines10[company]; int lines11, lines12;
char lines[12][20];
void Input() //ввод для 0 практики
{
    //1 строка
    cout << "Наименование: ";
    cin.getline(lines1, name);
    cout << "Производитель: ";
    cin.getline(lines2, company);
    cout << "Количество сост. частей: ";
    cin >> lines3;
    cout << "Цена ($): ";
    cin >> lines4;
    //2 строка
    cout << "Наименование: ";
    cin.get(); //пропускаю /n в стеке
    cin.getline(lines5, name);
    cout << "Производитель: ";
    cin.getline(lines6, company);
    cout << "Количество сост. частей: ";
    cin >> lines7;
    cout << "Цена ($): ";
    cin >> lines8;
    //3 строка
    cout << "Наименование: ";
    cin.get(); //пропускаю /n в стеке
    cin.getline(lines9, name);
    cout << "Производитель: ";
    cin.getline(lines10, company);
    cout << "Количество сост. частей: ";
    cin >> lines11;
    cout << "Цена ($): ";
    cin >> lines12;
    cout << endl;
}
void Output(int num) //вывод для 0 практики
{
    switch (num)
    {
    case 1:
        cout.fill(' ');
        /*cout.width(name - size(line.Name)); cout << left << "|" << left << line.Name;
        cout.width(company - size(line.Company)); cout << left << "|" << left << line.Company;
        cout.width(parts - size(line.Parts)); cout << left << "|" << left << line.Parts;
        cout.width(price - size(line.Price)); cout << left << "|" << left << line.Price; cout << "|" << endl;*/
        cout << left << "| "; cout.width(name - 2); cout << left << lines1;
        cout << left << "| "; cout.width(company - 2); cout << left << lines2;
        cout << left << "| "; cout.width(parts - 2); cout << left << lines3;
        cout << left << "| "; cout.width(price - 2); cout << left << lines4; cout << "|" << endl;
        break;
    case 2:
        cout.fill(' ');
        cout << left << "| "; cout.width(name - 2); cout << left << lines5;
        cout << left << "| "; cout.width(company - 2); cout << left << lines6;
        cout << left << "| "; cout.width(parts - 2); cout << left << lines7;
        cout << left << "| "; cout.width(price - 2); cout << left << lines8; cout << "|" << endl;
        break;
    case 3:
        cout.fill(' ');
        cout << left << "| "; cout.width(name - 2); cout << left << lines9;
        cout << left << "| "; cout.width(company - 2); cout << left << lines10;
        cout << left << "| "; cout.width(parts - 2); cout << left << lines11;
        cout << left << "| "; cout.width(price - 2); cout << left << lines12; cout << "|" << endl;
        break;
    }

}

void prac_0()
{
    //setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251); //rus
    SetConsoleOutputCP(1251); //rus
    //cin >> line.Name >> line.Company >> line.Parts >> line.Price;
    Input();
    DrawLine();
    Preset();
    DrawLineWithSections();
    Output(1);
    DrawLineWithSections();
    Output(2);
    DrawLineWithSections();
    Output(3);
    DrawLine();
    cout.width(n); cout << left << "| Примечание: возможно бесплатно получить продукт StarOffice через Internet "; cout << "|" << endl;
    DrawLine();
}
int IntLength(int number) //возвращает длину числа
{
    int count = 0;
    while (number > 0)
    {
        number = number / 10;
        count++;
    }
    return count;
}
void prac_1()
{
    SetConsoleCP(1251); //rus
    SetConsoleOutputCP(1251); //rus
    int lines_table;
    cout << "Введите количество строк таблицы: ";
    cin >> lines_table;
    while (cin.fail() || lines_table < 1) { Clear(); cout << "Ошибка ввода. Введите количество строк таблицы: "; cin >> lines_table; }
    Clear();
    int flag[10][1];
    int minmonth = 30, maxmonth = 0, i_min, i_max; char uslovie_1;
    cout << "Выполнить код согласно условию 1-ой практики, вариант 3? (y/n) \nУсловие: Поменять местами записи (элементы массива структур), содержащие минимальный и максимальный номер месяца даты\n> ";
    cin >> uslovie_1;
    while (uslovie_1 != 'y' && uslovie_1 != 'n') { Clear(); cout << "Ошибка ввода. Выполнить согласно условию практики? [y/n]: "; cin >> uslovie_1; }
    Clear();
    struct Record Table[10];
    for (int i = 0; i < lines_table; i++) // ввод
    {
        int count = 0;
        cout << "Наименование: ";
        cin >> Table[i].Name; Clear();
        cout << "Компания: ";
        cin >> Table[i].Company; Clear();
        cout << "Кол-во составляющих: ";
        cin >> Table[i].Parts;
        while (cin.fail() || Table[i].Parts < 1) { Clear(); cout << "Ошибка ввода. Количество сост. частей [>0]: "; cin >> Table[i].Parts; }
        Clear();
        cout << "Цена: ";
        cin >> Table[i].Price; 
        while (cin.fail() || Table[i].Price < 0) { Clear(); cout << "Ошибка ввода. Цена ($) [>=0]: "; cin >> Table[i].Price; }
        Clear();
        cout << "День: ";
        cin >> Table[i].RDate.Day;
        while (cin.fail() || !(Table[i].RDate.Day > 0 && Table[i].RDate.Day < 32)) { Clear(); cout << "Ошибка ввода. День [1-31]: "; cin >> Table[i].RDate.Day; }
        count = IntLength(Table[i].RDate.Day);
        if (count == 1) { flag[i][0] = 1; }
        //if (count != 2 and count != 1 ) { count = 0; goto d1; }
        cout << "Месяц: ";
        cin >> Table[i].RDate.Month;
        while (cin.fail() || !(Table[i].RDate.Month > 0 && Table[i].RDate.Month < 13)) { Clear(); cout << "Ошибка ввода. Месяц [1-12]: "; cin >> Table[i].RDate.Month; }
        Clear();
        count = IntLength(Table[i].RDate.Month);
        //if (Table[i].RDate.Month < 1 or Table[i].RDate.Month > 12) { goto d2; }
        if (count == 1) { flag[i][1] = 1; }
        //if (count != 2 and count != 1) { count = 0; goto d2; }
        if (Table[i].RDate.Month < minmonth) { minmonth = Table[i].RDate.Month; i_min = i; }
        if (Table[i].RDate.Month > maxmonth) { maxmonth = Table[i].RDate.Month; i_max = i; }
        cout << "Год: ";
        cin >> Table[i].RDate.Year;
        while (cin.fail() || !(Table[i].RDate.Year > 1900)) { Clear(); cout << "Ошибка ввода. Год [>1900]: "; cin >> Table[i].RDate.Year; }
        Clear();
        //count = IntLength(Table[i].RDate.Year);
        //if (count != 4) { count = 0; goto d3; }
    }
    system("cls");
    DrawLine();
    Preset();
    DrawLineWithSections();
    switch (uslovie_1)
    {
    case('n'):
    {
        for (int i = 0; i < lines_table; i++) // вывод без условия задачи
        {
            cout.fill(' ');
            cout << left << "| "; cout.width(name - 2); cout << left << Table[i].Name;
            cout << left << "| "; cout.width(company - 2); cout << left << Table[i].Company;
            cout << left << "| "; cout.width(parts - 2); cout << left << Table[i].Parts;
            cout << left << "| "; cout.width(price - 2); cout << left << Table[i].Price;
            cout << left << "| "; if (flag[i][0] == 1) { cout << "0"; } cout << left << Table[i].RDate.Day << "."; if (flag[i][1] == 1) { cout << "0"; } cout << Table[i].RDate.Month << "."; cout.width(date - 8); cout << Table[i].RDate.Year; cout << "|" << endl;
            if (i != lines_table - 1) DrawLineWithSections(); //не печатать для последней строчки
        }
        break;
    }
    case('y'):
    {
        for (int i = 0; i < lines_table; i++) // вывод с условием задачи
        {
            if (Table[i].RDate.Month == minmonth and Table[i].RDate.Month != maxmonth) //вывод max
            {
                cout.fill(' ');
                cout << left << "| "; cout.width(name - 2); cout << left << Table[i_max].Name;
                cout << left << "| "; cout.width(company - 2); cout << left << Table[i_max].Company;
                cout << left << "| "; cout.width(parts - 2); cout << left << Table[i_max].Parts;
                cout << left << "| "; cout.width(price - 2); cout << left << Table[i_max].Price;
                cout << left << "| "; if (flag[i_max][0] == 1) { cout << "0"; } cout << left << Table[i_max].RDate.Day << "."; if (flag[i_max][1] == 1) { cout << "0"; } cout << Table[i_max].RDate.Month << "."; cout.width(date - 8); cout << Table[i_max].RDate.Year; cout << "|" << endl;
                if (i != lines_table - 1) DrawLineWithSections(); //не печатать для последней строчки
            }
            if (Table[i].RDate.Month == maxmonth and Table[i].RDate.Month != minmonth) //вывод min
            {
                cout.fill(' ');
                cout << left << "| "; cout.width(name - 2); cout << left << Table[i_min].Name;
                cout << left << "| "; cout.width(company - 2); cout << left << Table[i_min].Company;
                cout << left << "| "; cout.width(parts - 2); cout << left << Table[i_min].Parts;
                cout << left << "| "; cout.width(price - 2); cout << left << Table[i_min].Price;
                cout << left << "| "; if (flag[i_min][0] == 1) { cout << "0"; } cout << left << Table[i_min].RDate.Day << "."; if (flag[i_min][1] == 1) { cout << "0"; } cout << Table[i_min].RDate.Month << "."; cout.width(date - 8); cout << Table[i_min].RDate.Year; cout << "|" << endl;
                if (i != lines_table - 1) DrawLineWithSections(); //не печатать для последней строчки
            }
            if ((Table[i].RDate.Month != maxmonth and Table[i].RDate.Month != minmonth) or (Table[i].RDate.Month == maxmonth and Table[i].RDate.Month == minmonth))
            {
                cout.fill(' ');
                cout << left << "| "; cout.width(name - 2); cout << left << Table[i].Name;
                cout << left << "| "; cout.width(company - 2); cout << left << Table[i].Company;
                cout << left << "| "; cout.width(parts - 2); cout << left << Table[i].Parts;
                cout << left << "| "; cout.width(price - 2); cout << left << Table[i].Price;
                cout << left << "| "; if (flag[i][0] == 1) { cout << "0"; } cout << left << Table[i].RDate.Day << "."; if (flag[i][1] == 1) { cout << "0"; } cout << Table[i].RDate.Month << "."; cout.width(date - 8); cout << Table[i].RDate.Year; cout << "|" << endl;
                if (i != lines_table - 1) DrawLineWithSections(); //не печатать для последней строчки
            }
        }
        break;
    }
    }
    DrawLine();
    cout.width(n); cout << left << "| Примечание: возможно бесплатно получить продукт StarOffice через Internet "; cout << "|" << endl;
    DrawLine();
    //prac_0();
}

void prac_1(Record T[])
{
    SetConsoleCP(1251); //rus
    SetConsoleOutputCP(1251); //rus
    int lines_table = 10;
//vvod:cout << "Введите количество строк таблицы [1-10]: ";
    //cin >> lines_table; if (lines_table > 10 or lines_table < 1)
    //{
    //    cout << "Ошибка ввода.\n"; Clear(); goto vvod; // очистка буфера в случае неправильного ввода
    //}
    //Clear(); // очистка буфера
    /*int flag[10][1];
    int minmonth = 30, maxmonth = 0, i_min = 300, i_max = 0; char uslovie_1;*/
    //usl1:cout << "Выполнить код согласно условию 1-ой практики, вариант 3? (y/n) \n Условие: Поменять местами записи (элементы массива структур), содержащие минимальный и максимальный номер месяца даты" << endl;
    //    cin >> uslovie_1;
    //    if (uslovie_1 != 'y' and uslovie_1 != 'n') { goto usl1; }
    struct Record Table[10] =
    {
        {"Office", "Microsoft", 4, 870.99, {11,01,2011}},
        {"SmartSute", "Lotus", 5, 1020.99, {21,12,2012}},
        {"StarOffice", "Sun", 4, 9.99, {21,10,2020}},
        {"Office1","Company1",4,10,{20,02,2010}},
        {"Office2","Company2",6,10,{21,02,2011}},
        {"Office3","Company3",5,11,{22,03,2010}},
        {"Office4","Company4",7,12,{23,02,2010}},
        {"Office5","Company5",8,10,{24,05,2010}},
        {"Office6","Company6",9,10,{25,02,2010}},
        {"Office7","Company7",10,10,{2,06,2010}}
    };
    //DrawLine();
    //Preset();
    //DrawLineWithSections();
    //for (int i = 0; i < lines_table; i++) // флаги для добавления нулей при выводе, если число однозначное
    //{
    //    if (IntLength(Table[i].RDate.Day) == 1) flag[i][0] = 1;
    //    if (IntLength(Table[i].RDate.Month) == 1) flag[i][1] = 1;
    //}
    //switch (uslovie_1)
    //{
    //case('n'):
    //{
    //    for (int i = 0; i < lines_table; i++) // вывод без условия задачи
    //    {
    //        cout.fill(' ');
    //        cout << left << "| "; cout.width(name - 2); cout << left << Table[i].Name;
    //        cout << left << "| "; cout.width(company - 2); cout << left << Table[i].Company;
    //        cout << left << "| "; cout.width(parts - 2); cout << left << Table[i].Parts;
    //        cout << left << "| "; cout.width(price - 2); cout << left << Table[i].Price;
    //        cout << left << "| "; if (flag[i][0] == 1) { cout << "0"; } cout << left << Table[i].RDate.Day << "."; if (flag[i][1] == 1) { cout << "0"; } cout << Table[i].RDate.Month << "."; cout.width(date - 8); cout << Table[i].RDate.Year; cout << "|" << endl;
    //        if (i != lines_table - 1) DrawLineWithSections(); //не печатать для последней строчки
    //    }
    //    break;
    //}
    //case('y'):
    //{
    //    for (int j = 0; j < lines_table; j++)
    //    {
    //        if (Table[j].RDate.Month < minmonth) { minmonth = Table[j].RDate.Month; i_min = j; }
    //        if (Table[j].RDate.Month > maxmonth) { maxmonth = Table[j].RDate.Month; i_max = j; }
    //    }
    //    for (int i = 0; i < lines_table; i++) // вывод с условием задачи
    //    {
    //        if (Table[i].RDate.Month == minmonth and Table[i].RDate.Month != maxmonth) //вывод max
    //        {
    //            cout.fill(' ');
    //            cout << left << "| "; cout.width(name - 2); cout << left << Table[i_max].Name;
    //            cout << left << "| "; cout.width(company - 2); cout << left << Table[i_max].Company;
    //            cout << left << "| "; cout.width(parts - 2); cout << left << Table[i_max].Parts;
    //            cout << left << "| "; cout.width(price - 2); cout << left << Table[i_max].Price;
    //            cout << left << "| "; if (flag[i_max][0] == 1) { cout << "0"; } cout << left << Table[i_max].RDate.Day << "."; if (flag[i_max][1] == 1) { cout << "0"; } cout << Table[i_max].RDate.Month << "."; cout.width(date - 8); cout << Table[i_max].RDate.Year; cout << "|" << endl;
    //            if (i != lines_table - 1) DrawLineWithSections(); //не печатать для последней строчки
    //        }
    //        if (Table[i].RDate.Month == maxmonth and Table[i].RDate.Month != minmonth) //вывод min
    //        {
    //            cout.fill(' ');
    //            cout << left << "| "; cout.width(name - 2); cout << left << Table[i_min].Name;
    //            cout << left << "| "; cout.width(company - 2); cout << left << Table[i_min].Company;
    //            cout << left << "| "; cout.width(parts - 2); cout << left << Table[i_min].Parts;
    //            cout << left << "| "; cout.width(price - 2); cout << left << Table[i_min].Price;
    //            cout << left << "| "; if (flag[i_min][0] == 1) { cout << "0"; } cout << left << Table[i_min].RDate.Day << "."; if (flag[i_min][1] == 1) { cout << "0"; } cout << Table[i_min].RDate.Month << "."; cout.width(date - 8); cout << Table[i_min].RDate.Year; cout << "|" << endl;
    //            if (i != lines_table - 1) DrawLineWithSections(); //не печатать для последней строчки
    //        }
    //        if ((Table[i].RDate.Month != maxmonth and Table[i].RDate.Month != minmonth) or (Table[i].RDate.Month == maxmonth and Table[i].RDate.Month == minmonth))
    //        {
    //            cout.fill(' ');
    //            cout << left << "| "; cout.width(name - 2); cout << left << Table[i].Name;
    //            cout << left << "| "; cout.width(company - 2); cout << left << Table[i].Company;
    //            cout << left << "| "; cout.width(parts - 2); cout << left << Table[i].Parts;
    //            cout << left << "| "; cout.width(price - 2); cout << left << Table[i].Price;
    //            cout << left << "| "; if (flag[i][0] == 1) { cout << "0"; } cout << left << Table[i].RDate.Day << "."; if (flag[i][1] == 1) { cout << "0"; } cout << Table[i].RDate.Month << "."; cout.width(date - 8); cout << Table[i].RDate.Year; cout << "|" << endl;
    //            if (i != lines_table - 1) DrawLineWithSections(); //не печатать для последней строчки
    //        }
    //    }
    //    break;
    //}
    //}
    //DrawLine();
    //cout.width(n); cout << left << "| Примечание: возможно бесплатно получить продукт StarOffice через Internet "; cout << "|" << endl;
    //DrawLine();
    //prac_0();
    for (int i = 0; i < lines_table; i++) // заполняем массив 2-ой практики
    {
        T[i] = Table[i];
    }
}

void prac_2()
{
    /*
    Практическая № 2 (Динамические массивы)
    Используя функцию malloc() / calloc() создать динамический массив A, элементами которого будут структуры Record, созданная в практической работе №1. В массив А добавить столько соответствующих записей из массива Table[], сколько указано в качестве целочисленного значения поля (элемента структуры).
    Используя функцию new создать массив В, элементами которого будут указатели на структуры в динамической памяти. В массив В занести 10 записей массива А. Остальные записи в массиве А удалить.

    Вывести на экран адреса первого элемента массива Тable, массива А и массива В.

    Вывести на экран в виде таблицы:
    адрес А[i], значение A[i]->строковое_поле,
    адрес В[i], значение В[i] ], значение В[i]->строковое_поле.

    Освободить память.
    */
    SetConsoleCP(1251); //rus
    SetConsoleOutputCP(1251); //rus
    Record* A, * A_old;
    Record MyTable[10];
    prac_1(MyTable);
    int n = MyTable[0].Parts * 3;
    //cout << n << endl;
    A = (Record*)malloc(n * sizeof(Record));
    for (int i = 0; i < n; i++)
    {
        A[i] = MyTable[i];
    }
    //cout << A << endl;
    A_old = A;
    A = (Record*)realloc(A, 10 * sizeof(Record));
    if (A == NULL) A = A_old; // NOT A or A == NULL
    cout << "\nадрес 1-го элемента массива Тable:\n" << &MyTable << endl;
    cout << "адрес 1-го элемента массива A:\n" << &A << endl;
    Record** B;
    B = (Record**)new Record * [10];
    for (int i = 0; i < 10; i++)
    {
        B[i] = &A[i]; //массив указателей на элементы массива А. Использование free(A) приведет к тому, что массив B будет указывать на освободившуюся область.
        B[i] = (Record*)new(Record);
        *(B[i]) = A[i]; //по адресу обращаемся в область памяти и заносим туда A[i]
        //B[i]->Name = A[i].Name;
    }
    cout << "адрес 1-го элемента массива B:\n" << &B << endl;
    /* for (int i = 0; i < 10; i++)
     {
         cout.fill(' ');
         cout << "адрес A[" << i << "] = " << &A[i] << " A[" << i << "] = " << A[i].Name << " " <<
             A[i].Company << " " << A[i].Parts << " " << A[i].Price << " " << A[i].RDate.Day <<"."<< A[i].RDate.Month <<"."<< A[i].RDate.Year << endl;
     }*/
    cout.fill('-'); cout.width(128); cout << left << "|" << "|" << endl;
    cout.fill(' '); cout << left << "| ";
    cout.width(6); cout << left << "Адрес ";
    cout.width(22); cout << left << "| Значение";
    cout.width(98); cout << "| Строковое поле " << "|" << endl;
    cout.fill('-'); cout.width(128); cout << left << "|" << "|" << endl;
    for (int i = 0; i < 10; i++) // вывод
    {
        cout.fill(' ');

        cout << "| A[" << i; cout.width(3); cout << "]" << "| ";
        cout.width(19); cout << &A[i];
        cout << left << " | "; cout.width(name - 2); cout << left << A[i].Name;
        cout << left << "| "; cout.width(company - 2); cout << left << A[i].Company;
        cout << left << "| "; cout.width(parts - 2); cout << left << A[i].Parts;
        cout << left << "| "; cout.width(price - 2); cout << left << A[i].Price;
        cout << left << "| "; if (IntLength(A[i].RDate.Day) == 1) { cout << "0"; }; cout << left << A[i].RDate.Day << "."; if (IntLength(A[i].RDate.Month) == 1) { cout << "0"; }; cout << A[i].RDate.Month << "."; cout.width(date - 8); cout << A[i].RDate.Year; cout << "|" << endl;
        //if (i != 10 - 1) DrawLineWithSections(); //не печатать для последней строчки
    }
    cout.fill('-'); cout.width(128); cout << left << "|" << "|" << endl;
    cout << endl;
    cout.fill('-'); cout.width(52); cout << left << "|" << "|" << endl;
    cout.fill(' '); cout << left << "| ";
    cout.width(6); cout << left << "Адрес ";
    cout.width(22); cout << left << "| Значение";
    cout.width(22); cout << "| Строковое поле " << "|" << endl;
    cout.fill('-'); cout.width(52); cout << left << "|" << "|" << endl;
    for (int i = 0; i < 10; i++) // вывод
    {
        cout.fill(' ');
        cout << "| B[" << i; cout.width(3); cout << "]" << "| "; cout.width(20); cout << &B[i];
        cout << left << "| "; cout.width(20); cout << left << B[i] << "|" << endl;

    }
    cout.fill('-'); cout.width(52); cout << left << "|" << "|" << endl;
    for (int i = 0; i < 10; i++)
    {
        delete[]B[i];
    }
    delete[]B;
    free(A);

}
struct Node
{
    Record info;
    Node* next;
    Node* prev;
};
int prac_3()
{
    SetConsoleCP(1251); //rus
    SetConsoleOutputCP(1251); //rus
    //prac_2();
    cout << "--------------------Однонаправленный кольцевой список--------------------" << endl;
    cout << "#3. Найти элементы списка, у которых полностью совпадает дата, \nвведенная с клавиатуры, и удалить найденные элементы списка." << endl;
    Record MyTable[10];
    prac_1(MyTable);
    Date INPDate;
    cout << "День: "; cin >> INPDate.Day; while (cin.fail() || INPDate.Day < 1 || INPDate.Day > 31) { Clear(); cout << "Ошибка ввода. День [1-31]: "; cin >> INPDate.Day; }
    Clear();
    cout << "Месяц: "; cin >> INPDate.Month; while (cin.fail() || INPDate.Month < 1 || INPDate.Month > 12) { Clear(); cout << "Ошибка ввода. Месяц [1-12]: "; cin >> INPDate.Month; }
    Clear();
    cout << "Год: "; cin >> INPDate.Year; while (cin.fail() || INPDate.Year < 1000) { Clear(); cout << "Ошибка ввода. Год [>1000]: "; cin >> INPDate.Year; }
    Clear();
    //cout << INPDate.Day << INPDate.Month << INPDate.Year << endl;
    Node* newNode; // указатель на структуру типа Node, новый элемент
    Node* head = NULL; // голова списка
    Node* current; // Указатель на текущий элемент
    //Node* last;
    newNode = new Node;
    //cout << newNode->info.Name << " Адрес узла";
    for (int i = 0; i < 2; i++) // заполнение списка таблицей
    {
        for (int j = 0; j < 10; j++)
        {
            newNode = new Node;
            if (newNode == nullptr)
            {
                cout << "Ошибка выделения памяти";
                return -100;
            }
            newNode->info = MyTable[j];
            newNode->next = nullptr;
            newNode->prev = nullptr;
            if (!head) // head == NULL или head==nullptr
            {
                newNode->next = newNode;
                //newNode->prev = newNode;
                head = newNode;
            }
            else // имеется в списке хотя бы 1 элемент
            { // добавление в конец однонаправленного списка 
                bool bFirst = true;
                for (current = head; (current->next != head) | bFirst; current = current->next)
                    if (bFirst) bFirst = false;
                newNode->next = head;
                current->next = newNode;
                //last = current;
                //head->prev = newNode;
            }
        }
    }

    cout << "Значение head = " << head << endl;
    bool bFirst = true;
    int i;
    //cout << "Голова: " << head << endl;
    for (current = head, i = 0; i < 20/*(current)*/; i++, current = current->next) // вывод
    {
        if (bFirst) bFirst = false;
        cout.width(15); cout.fill(' ');
        cout << left << current->info.Name << " "; cout.width(15); cout << current->info.Company;
        cout.fill('0');
        cout.width(2); cout << right << current->info.RDate.Day << ".";
        cout.width(2); cout << right << current->info.RDate.Month << ".";
        cout.width(4); cout << current->info.RDate.Year;
        cout.fill(' '); cout << "  Тек. адрес: " << current << " Next=" << current->next << " Prev=" << current->prev << endl;
    }
    cout << "Завершение вывода результата ввода" << endl << endl;

    // задание
    int count_deleted = 0;
    for (current = head, i = 0; i < 20; i++/*, current = current->next*/)
    {
        Node* temp = head;
        Node* temp_head = head;
        if (temp_head->info.RDate.Day == INPDate.Day &&
            temp_head->info.RDate.Month == INPDate.Month &&
            temp_head->info.RDate.Year == INPDate.Year)
        {
            temp = current->next;
            //delete head;
            head = temp;
            //last = nullptr;
        }
        if (current->next->info.RDate.Day == INPDate.Day &&
            current->next->info.RDate.Month == INPDate.Month &&
            current->next->info.RDate.Year == INPDate.Year)
        {
            temp = current->next->next;
            //if (current->next->next == nullptr) current->next = nullptr;
            //current->next = current->next->next;
            delete current->next;
            current->next = temp;
            count_deleted++;
            //cout << current->info.Name << endl;
        }
        else current = current->next;
        //cout << current->info.Name << endl;
    }
    // задание
    // вывод после выполнения задания
    cout << "Значение head = " << head << endl;
    bFirst = true;

    for (current = head, i = 0; i < 20 - count_deleted/*(current)*/; i++, current = current->next) // вывод
    {
        if (bFirst) bFirst = false;
        cout.width(15); cout.fill(' ');
        cout << left << current->info.Name << " "; cout.width(15); cout << current->info.Company;
        cout.fill('0');
        cout.width(2); cout << right << current->info.RDate.Day << ".";
        cout.width(2); cout << right << current->info.RDate.Month << ".";
        cout.width(4); cout << current->info.RDate.Year;
        cout.fill(' '); cout << "  Тек. адрес: " << current << " Next=" << current->next << " Prev=" << current->prev << endl;
    }
    cout << "Завершение вывода результата задания" << endl << endl;
    // очистка
    bFirst = true;
    for (current = head; (current != head) | bFirst; )
    {
        if (bFirst) bFirst = false;
        Node* delNode = current; // запоминаем узел, который будем удалять
        current = current->next; // тот который будем удалять на следующей итерации
        delete delNode;
        //head = current->next;
        //delete current;
        //current = head; // тот который будем удалять на следующей итерации
    }
    head = NULL;
    if (head == NULL) cout << "Список пустой, память освобождена!";
    else cout << "УПС! Список не пустой, память не освобождена!";
    //delete newNode;
}
void prac_4()
{
    SetConsoleCP(1251); //rus
    SetConsoleOutputCP(1251); //rus
    Record MyTable[10];
    prac_1(MyTable);
    //prac_3();
    FILE* file;
    const int total_lines = 4;
    //ifstream ifst;
    ///////////////////////////////////////////////////////////////// TXT //////////////////////////////////////////////////////////////////////////////////////
    // запись в файл
    cout << "Компания: "; cin >> MyTable[total_lines - 1].Company; Clear();
    cout << "Наименование: "; cin >> MyTable[total_lines - 1].Name; Clear();
    cout << "Сост. части: "; cin >> MyTable[total_lines - 1].Parts;
    while (cin.fail() || MyTable[total_lines - 1].Parts < 1) { Clear(); cout << "Ошибка ввода. Кол-во сост. частей [>0]: "; cin >> MyTable[total_lines - 1].Parts; }
    Clear();
    cout << "Цена: "; cin >> MyTable[total_lines - 1].Price;
    while (cin.fail() || MyTable[total_lines - 1].Price < 0) { Clear(); cout << "Ошибка ввода. Цена ($) [>=0]: "; cin >> MyTable[total_lines - 1].Price; }
    Clear();
    cout << "День: "; cin >> MyTable[total_lines - 1].RDate.Day;
    while (cin.fail() || MyTable[total_lines - 1].RDate.Day < 0 || MyTable[total_lines - 1].RDate.Day > 31) 
    { Clear(); cout << "Ошибка ввода. День [1-31]: "; cin >> MyTable[total_lines - 1].RDate.Day; }
    Clear();
    cout << "Месяц: "; cin >> MyTable[total_lines - 1].RDate.Month;
    while (cin.fail() || MyTable[total_lines - 1].RDate.Month < 0 || MyTable[total_lines - 1].RDate.Month > 12) 
    { Clear(); cout << "Ошибка ввода. Месяц [1-12]: "; cin >> MyTable[total_lines - 1].RDate.Month; }
    Clear();
    cout << "Год: "; cin >> MyTable[total_lines - 1].RDate.Year; 
    while (cin.fail() || MyTable[total_lines - 1].RDate.Year < 1000) 
    { Clear(); cout << "Ошибка ввода. Год [>1000]: "; cin >> MyTable[total_lines - 1].RDate.Year; }
    Clear();
    fopen_s(&file, "KuznetsovTXT.txt", "w");
    for (int i = 0; i < total_lines; i++)
    {
        fprintf(file, "%s %s %d %f %d %d %d \n", MyTable[i].Company, MyTable[i].Name, MyTable[i].Parts, MyTable[i].Price,
            MyTable[i].RDate.Day, MyTable[i].RDate.Month, MyTable[i].RDate.Year);
    }
    fclose(file);
    //чтение файла
    Record ReadMyTable[total_lines];
    fopen_s(&file, "KuznetsovTXT.txt", "r");
    for (int i = 0; i < total_lines; i++)
    {
        fscanf_s(file, "%s %s %d %f %d %d %d", ReadMyTable[i].Company, _countof(ReadMyTable[i].Company), ReadMyTable[i].Name, _countof(ReadMyTable[i].Name),
            &ReadMyTable[i].Parts, &ReadMyTable[i].Price,
            &ReadMyTable[i].RDate.Day, &ReadMyTable[i].RDate.Month, &ReadMyTable[i].RDate.Year);
    }
    // вывод в консоль
    fclose(file);
    cout << "\n--------------------TXT--------------------" << endl;
    for (int i = 0; i < total_lines; i++) // вывод
    {
        cout.width(15);
        cout << left << ReadMyTable[i].Company << " | ";
        cout.width(15); cout << ReadMyTable[i].Name << " | ";
        cout.width(8); cout << ReadMyTable[i].Parts << " | ";
        cout.width(8); cout << ReadMyTable[i].Price << " | ";
        cout.width(2); cout << ReadMyTable[i].RDate.Day << ".";
        cout.width(2); cout << ReadMyTable[i].RDate.Month << "." << ReadMyTable[i].RDate.Year << endl;
    }
    ///////////////////////////////////////////////////////////////// BIN //////////////////////////////////////////////////////////////////////////////////////
    cout << "\n--------------------BIN--------------------" << endl;

    ofstream wf("KuznetsovBIN.bin", ios::out | ios::binary); // создаю файл и записываю
    for (int i = 0; i < total_lines; i++)
    {
        wf.write((char*)&MyTable[i], sizeof(Record)); //запись всей таблицы
    }

    wf.close();

    ifstream rf("KuznetsovBIN.bin", ios::in | ios::binary); // читаю файл и заношу в массив
    for (int i = 0; i < total_lines; i++)
    {
        rf.read((char*)&ReadMyTable[i], sizeof(Record));
    }

    rf.close();

    for (int i = 0; i < total_lines; i++) // задание: удвоить значение четных целых чисел в бинарном файле.
    {
        if (ReadMyTable[i].Parts % 2 == 0) ReadMyTable[i].Parts = ReadMyTable[i].Parts * 2;
        if (ReadMyTable[i].RDate.Day % 2 == 0) ReadMyTable[i].RDate.Day = ReadMyTable[i].RDate.Day * 2;
        if (ReadMyTable[i].RDate.Month % 2 == 0) ReadMyTable[i].RDate.Month = ReadMyTable[i].RDate.Month * 2;
        if (ReadMyTable[i].RDate.Year % 2 == 0) ReadMyTable[i].RDate.Year = ReadMyTable[i].RDate.Year * 2;
    }

    ofstream wf2("KuznetsovBIN.bin", ios::out | ios::binary); // пересоздаю файл и записываю по заданию
    for (int i = 0; i < total_lines; i++)
    {
        wf2.write((char*)&ReadMyTable[i], sizeof(Record)); //запись таблицы [total_lines] раз
    }

    wf2.close();

    //for (int i = 0; i < total_lines; i++) // вывод
    //{
    //    cout << left << ReadMyTable[i].Company << " " << ReadMyTable[i].Name << " " << ReadMyTable[i].Parts << " " << ReadMyTable[i].Price << " " <<
    //        ReadMyTable[i].RDate.Day << " " << ReadMyTable[i].RDate.Month << " " << ReadMyTable[i].RDate.Year << endl;
    //}
    for (int i = 0; i < total_lines; i++) // вывод
    {
        cout.width(15);
        cout << left << ReadMyTable[i].Company << " | ";
        cout.width(15); cout << ReadMyTable[i].Name << " | ";
        cout.width(8); cout << ReadMyTable[i].Parts << " | ";
        cout.width(8); cout << ReadMyTable[i].Price << " | ";
        cout.width(2); cout << ReadMyTable[i].RDate.Day << ".";
        cout.width(2); cout << ReadMyTable[i].RDate.Month << "." << ReadMyTable[i].RDate.Year << endl;
    }
    //ifst.open("Kuznetsov.txt", ios_base::in);

    //fclose(file);

}
class clDate
{
    //private
    int Day;
    int Month;
    int Year;
public:
    clDate() //конструктор по умолчанию 
    {
        Day = 0; Month = 0; Year = 0;
    }
    clDate(int day, int month, int year) //инициализация значениями
    {
        Day = day; Month = month; Year = year;
    }
    clDate(struct Date SDate)
    {
        Day = SDate.Day; Month = SDate.Month; Year = SDate.Year;
    }
    clDate(struct Date* PDate)
    {
        Day = PDate->Day; Month = PDate->Month; Year = PDate->Year;
    }
    ~clDate() { cout << "Привет от деструктора clDate!!!\n"; } // деструктор для деинициализации объекта
    Date getDate()
    {
        Date MD; MD.Day = Day; MD.Month = Month; MD.Year = Year;
        return MD;
    }
    void printDate() //вывод значений
    {
        cout << Day << "." << Month << "." << Year << endl;
    }
    bool setDate(int day, int month, int year)
    {
        if (day > 0 && day < 32 && month>0 && month < 13) { Day = day; Month = month; Year = year; return true; }
        else return false;
    }
    bool setDate(Date mD)
    {
        return setDate(mD.Day, mD.Month, mD.Year);
    }
    void setDate() //ручной ввод
    {
        bool day_input_is_true = true, month_input_is_true = true, year_input_is_true = true;
        while (day_input_is_true)
        {
        /*vvod_d:*/cout << "День: "; cin >> Day;
            if (cin.fail() || (Day > 31 || Day < 1))
            {
                cout << "Ошибка ввода. Область допустимого значения [1-31].\n"; Clear(); //goto vvod_d; // очистка буфера в случае неправильного ввода
            }
            else day_input_is_true = false;
        }
        Clear(); // очистка буфера
        while (month_input_is_true)
        {
        /*vvod_m:*/cout << "Месяц: "; cin >> Month;
            if (cin.fail() || (Month > 12 || Month < 1))
            {
                cout << "Ошибка ввода. Область допустимого значения [1-12].\n"; Clear(); //goto vvod_m; // очистка буфера в случае неправильного ввода
            }
            else month_input_is_true = false;
        }
        Clear(); // очистка буфера
        while (year_input_is_true)
        {
            cout << "Год: "; cin >> Year;
            if (cin.fail() || (Year > 3000 || Year < 0))
            {
                cout << "Ошибка ввода. Область допустимого значения [1-3000].\n"; Clear();
            }
            else year_input_is_true = false;
        }
        Clear(); // очистка буфера

    }
    void addDay(int delta)
    {
        if (setDate(Day = Day + delta, Month, Year));
        else { setDate(Day = Day - delta, Month, Year); cout << "Неверная дата" << endl; }
    }
};

class clDateTime : public clDate
{
protected:
    int hour, minute, second;
public:
    clDateTime() : clDate(1, 1, 1970) { hour = 0; minute = 0; second = 0; }
    clDateTime(int _hour, int _minute, int _second) { hour = _hour; minute = _minute; second = _second; }
    clDateTime(int _year, int _month, int _day, int _hour, int _minute, int _second) : clDate(_day, _month, _year)
    {
        //if (setDate(_day, _month, _year)) 
        { hour = _hour; minute = _minute; second = _second; }
    }
    //void printDateTime() { printDate(); cout << hour << ":" << minute << ":" << second << endl; }
    void printDate()
    {
        clDate::printDate();
        cout << hour << ":" << minute << ":" << second << endl;
    }
};
class clRecord
{
    string Name;
public:
    string Company;

    clRecord() //конструктор по умолчанию 
    {
        Name = "undefined"; Company = "undefined"; Parts = 0; Price = 0;
    }
    
    clRecord(const char _filename[]) // метод для считывания строчки из файла
    {
        //struct Date MethodDate;
        FILE* file;
        Record MethodFileTable;
        fopen_s(&file, _filename, "r");
        //for (int i = 0; i < numberofline; i++)
        //{

        fscanf_s(file, "%s %s %d %f %d %d %d", MethodFileTable.Company, _countof(MethodFileTable.Company), MethodFileTable.Name, _countof(MethodFileTable.Name),
            &Parts, &Price,
            &MethodFileTable.RDate.Day, &MethodFileTable.RDate.Month, &MethodFileTable.RDate.Year); clRDate.setDate(MethodFileTable.RDate);
        Company = MethodFileTable.Company; Name = MethodFileTable.Name;
        //}
        fclose(file);
    }

    clRecord(const char _filename[], int _numberofline) // метод для считывания строчек из файла (для динамического массива объектов класса)
    {
        //struct Date MethodDate;
        FILE* file;
        Record MethodFileTable;
        fopen_s(&file, _filename, "r");
        for (int i = -1; i < _numberofline; ++i)
        {
            fscanf_s(file, "%s %s %d %f %d %d %d", MethodFileTable.Company, _countof(MethodFileTable.Company), MethodFileTable.Name, _countof(MethodFileTable.Name),
                &Parts, &Price,
                &MethodFileTable.RDate.Day, &MethodFileTable.RDate.Month, &MethodFileTable.RDate.Year); clRDate.setDate(MethodFileTable.RDate);
            Company = MethodFileTable.Company; Name = MethodFileTable.Name;
        }
        fclose(file);
    }

    clRecord(Record* _PRecord)
    {
        Company = _PRecord->Company; Name = _PRecord->Name; Parts = _PRecord->Parts; Price = _PRecord->Price;
        clRDate.setDate(_PRecord->RDate.Day, _PRecord->RDate.Month, _PRecord->RDate.Year);
    }

    ~clRecord() { cout << "Привет от деструктора clRecord!\n"; } // деструктор для деинициализации объекта



    void printRecord() //вывод значений
    {
        cout << Name << " " << Company << " " << Parts << " " << Price << " "; clRDate.printDate(); //<< " " << clRDate.Month << " " << clRDate.Year << " " << endl;
    }
private:
    int Parts;
protected:
    float Price;
    clDate clRDate;
};
void prac_5()
{
    SetConsoleCP(1251); //rus
    SetConsoleOutputCP(1251); //rus
    Record MyTable[10];
    prac_1(MyTable);
    const int total_lines = 10;
    FILE* file;
    fopen_s(&file, "KuznetsovTXT.txt", "w");
    for (int i = 0; i < total_lines; i++)
    {
        fprintf(file, "%s %s %d %f %d %d %d \n", MyTable[i].Company, MyTable[i].Name, MyTable[i].Parts, MyTable[i].Price,
            MyTable[i].RDate.Day, MyTable[i].RDate.Month, MyTable[i].RDate.Year);
    }
    fclose(file);
    ////////////////////////////////ПЕРВАЯ ЧАСТЬ 1-4///////////////////////////////////////
    Date MD = { 1,1,2023 };
    //создание статических объектов D1-4
    clDate D1;
    clDate D2(29, 2, 2022); cout << "D2 = "; D2.printDate();
    clDate D3(MD); cout << "D3 = "; D3.printDate();
    clDate D4(&MD); cout << "D4 = "; D4.printDate();
    D1.setDate();
    cout << "D1 = "; D1.printDate();
    //создание динамического объекта D5
    clDate* D5;
    D5 = new clDate(5, 5, 2025); cout << "D5 = "; D5->printDate();
    clDate D6 = *D5; cout << "D6 = "; D6.printDate();
    delete D5;
    D2.addDay(5);
    cout << "D2 = "; D2.printDate();
    ////////////////////////////////ВТОРАЯ ЧАСТЬ 5-10///////////////////////////////////////
    cout << endl << "Вторая часть" << endl;
    clRecord R1; cout << "R1 = "; R1.printRecord(); // считываю строчку из файла
    clRecord R2("KuznetsovTXT.txt"); cout << "R2 = "; R2.printRecord();
    clRecord* R3[3];
    for (int i = 0; i < 3; i++) // считываю строчки из файла и заношу по строчке в объект R3[i] (через указатели и динамический массив)
    {
        R3[i] = new clRecord("KuznetsovTXT.txt", i); cout << "R3[" << i << "] = "; R3[i]->printRecord();
    }
    for (int i = 0; i < 3; i++) // очистка памяти.
    {
        delete R3[i];
    }
    //delete[] R3; // Ошибка _CrtIsValidHeapPointer(block). Может возникать из-за попытки освободить уже освобожденную память или разрушить объект со стеком, который уже был удален
    clRecord R3_2[3];
    for (int i = 0; i < 3; i++) // считываю строчки из файла и заношу по строчке в объект R3_2[i] (статический массив)
    {
        R3_2[i] = clRecord("KuznetsovTXT.txt", i); cout << "R3_2[" << i << "] = "; R3_2[i].printRecord();
    }
    //delete[]R3;
    Record MR = { "BI", "BARSEST", 10, 100, 25, 10, 2004 };
    clRecord R4(&MR); cout << "R4 = "; R4.printRecord();
    _fcloseall();
}


void prac_6()
{
    SetConsoleCP(1251); //rus
    SetConsoleOutputCP(1251); //rus
    clDateTime DT; // объект DT класса clDateTime
    DT.printDate(); // вывести секунды, минуты, часы, день, месяц, год
    DT.clDate::printDate(); // вывести только день, месяц и год

    clDateTime DT1(3, 4, 5); DT1.printDate();
    clDateTime DT2(2023, 10, 25, 3, 4, 5); DT2.printDate();
    clDateTime aDT[4];
    for (int i = 0; i < 4; i++) aDT[i].printDate();
    clDateTime* pDT[4]; // статический с элементом указателя на объект
    for (int i = 0; i < 4; i++) pDT[i] = new clDateTime(10 + i, 11, 12); //адресы 4-ех объектов
    clDateTime* ppDT; // динамический массив
    ppDT = new clDateTime[4];

    for (int i = 0; i < 4; i++) delete pDT[i];
    delete[] ppDT;
}

void prac_7()
{
    
    class A
    {
    public: void f() { cout << "A\n"; }
          A() { cout << "Constructor A\n"; }
    };
    class C : public virtual A
    {
    public: void f() { cout << "C\n"; }
          C() { cout << "Constructor C\n"; }
    };
    class B : public virtual A, public virtual C
    {
    public: void f() { cout << "B\n"; }
          B() { cout << "Constructor B\n"; }
    };
    class D : public virtual B
    {
    public: void f() { cout << "D\n"; }
          D() { cout << "Constructor D\n"; }
    };
    class E : public virtual C, public virtual D
    {
    public: void f() { cout << "E\n"; }
          E() { cout << "Constructor E\n"; }
    };
    class F : virtual public D, public virtual E
    {
        ;
    };
    F Object; Object.f();
}

int menu();
//int isValidInt(string num);

int main()
{
    menu();
}

int menu()
{
    SetConsoleCP(1251); //rus
    SetConsoleOutputCP(1251); //rus
    string sMenu; int iMenu=-1, myMenu=-1;
    bool Menu_is_active = true;
    //for (;iMenu!=0;) // бесконечный цикл
    while (Menu_is_active)//myMenu !=0)
    {
        system("cls");
        cout << "Кузнецов Алексей Александрович, БАСО-04-22, вариант 34 (две последние цифры зачетной книжки)" << endl;
        cout << "Выберите практическую работу для проверки:" << endl;
        cout << "   1. Практическая №1. Массив структур." << endl;
        cout << "   2. Практическая №2. Динамические массивы." << endl;
        cout << "   3. Практическая №3. Динамические связные списки." << endl;
        cout << "   4. Практическая №4. Файлы." << endl;
        cout << "   5. Практическая №5. Классы и объекты." << endl;
        cout << "   6. Практическая №6. Наследование и друзья." << endl;
        cout << "   7. Практическая №7. Виртуальные базовые классы." << endl;
        cout << "   0. Завершение работы программы" << endl;
        cout << "> ";
        //cin >> sMenu;
        //getline(cin, sMenu);
        bool myMenu_input_is_active = true;
        while (myMenu_input_is_active)
        {
            //cout << "Введите ответ: ";
            cin >> myMenu;
                if (cin.fail() || !(myMenu >= 0 && myMenu <= 7))
                {
                    Clear();
                    cout << "Ошибка ввода. Допустимая область значений [0-7]\n> ";
                }
                else myMenu_input_is_active = false;
        }
            //iMenu = stoi(sMenu);
            //switch (iMenu)
        Clear(); // противодействие остаточным данным в буфере, введенным через пробел
        switch (myMenu)
        {
        case 1: prac_1(); system("pause"); break;
        case 2: prac_2(); system("pause"); break;
        case 3: prac_3(); system("pause"); break;
        case 4: prac_4(); system("pause"); break;
        case 5: prac_5(); system("pause"); break;
        case 6: prac_6(); system("pause"); break;
        case 7: prac_7(); system("pause"); break;
        case 0: Menu_is_active = false; break;
        default: cout << "Ошибка ввода. " << endl; break;
        }
    }
    return 0;
}
//int siValidInt(string num)
//{
//    ...
//}