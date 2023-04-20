// Разработать программу, которая вводит фактические данные из таблицы,
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

char lines1[name], lines2[company]; int lines3, lines4;
char lines5[name], lines6[company]; int lines7, lines8;
char lines9[name], lines10[company]; int lines11, lines12;
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
    cout << "Введите количество строк таблицы: ";
    int lines_table;
    cin >> lines_table;
    int flag[10][1];
    int minmonth = 30, maxmonth = 0, i_min, i_max; char uslovie_1;
usl1:cout << "Выполнить код согласно условию 1-ой практики, вариант 3? (y/n) \n Условие: Поменять местами записи (элементы массива структур), содержащие минимальный и максимальный номер месяца даты" << endl;
    cin >> uslovie_1;
    if (uslovie_1 != 'y' and uslovie_1 != 'n') { goto usl1; }
    struct Record Table[10];
    for (int i = 0; i < lines_table; i++) // ввод
    {
        int count = 0;
        cout << "Наименование: ";
        cin >> Table[i].Name;
        cout << "Компания: ";
        cin >> Table[i].Company;
        cout << "Кол-во составляющих: ";
        cin >> Table[i].Parts;
        cout << "Цена: ";
        cin >> Table[i].Price;
    d1:cout << "День: ";
        cin >> Table[i].RDate.Day;
        count = IntLength(Table[i].RDate.Day);
        if (count == 1) { flag[i][0] = 1; }
        if (count != 2 and count != 1) { count = 0; goto d1; }
    d2:cout << "Месяц: ";
        cin >> Table[i].RDate.Month;
        count = IntLength(Table[i].RDate.Month);
        if (Table[i].RDate.Month < 1 or Table[i].RDate.Month > 12) { goto d2; }
        if (count == 1) { flag[i][1] = 1; }
        if (count != 2 and count != 1) { count = 0; goto d2; }
        if (Table[i].RDate.Month < minmonth) { minmonth = Table[i].RDate.Month; i_min = i; }
        if (Table[i].RDate.Month > maxmonth) { maxmonth = Table[i].RDate.Month; i_max = i; }
    d3:cout << "Год: ";
        cin >> Table[i].RDate.Year;
        count = IntLength(Table[i].RDate.Year);
        if (count != 4) { count = 0; goto d3; }
    }
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
    //cout << "Введите количество строк таблицы: ";
    const int lines_table = 10;
    //cin >> lines_table;
    //int flag[10][1];
    //int minmonth = 30, maxmonth = 0, i_min=300, i_max=0; char uslovie_1;
//usl1:cout << "Выполнить код согласно условию 1-ой практики, вариант 3? (y/n) \n Условие: Поменять местами записи (элементы массива структур), содержащие минимальный и максимальный номер месяца даты" << endl;
    //cin >> uslovie_1;
    //if (uslovie_1 != 'y' and uslovie_1 != 'n') { goto usl1; }
    struct Record Table[lines_table] =
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

int main()
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
    Record* A;
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
    A = (Record*)realloc(A, 10 * sizeof(Record));
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
    cout.fill('-'); cout.width(128); cout<<left <<"|" <<"|"<< endl;
    cout.fill(' '); cout << left << "| "; 
    cout.width(6); cout << left << "Адрес ";
    cout.width(22); cout << left << "| Значение";
    cout.width(98); cout << "| Строковое поле " << "|" << endl;
    cout.fill('-'); cout.width(128); cout << left << "|" << "|" << endl;
    for (int i = 0; i < 10; i++) // вывод
    {
        cout.fill(' ');

        cout << "| A[" << i; cout.width(3); cout << "]"<< "| ";
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
        delete B[i];
    }
    delete[]B;
    free(A);

}