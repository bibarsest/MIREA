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
    return count; //
}
int main()
{
    SetConsoleCP(1251); //rus
    SetConsoleOutputCP(1251); //rus
    int lines_table;
    cout << "Введите количество строк таблицы: ";
    cin >> lines_table;
    while (cin.fail() || lines_table < 1) { cin.clear(); cin.ignore(2000, '\n'); cout << "Ошибка ввода. Введите количество строк таблицы: "; cin >> lines_table; }
    int flag[10][1];
    int minmonth = 30, maxmonth = 0, i_min, i_max; char uslovie_1;
usl1:cout << "Выполнить код согласно условию 1-ой практики, вариант 3? (y/n) \n Условие: Поменять местами записи (элементы массива структур), содержащие минимальный и максимальный номер месяца даты" << endl;
    cin >> uslovie_1;
    if (uslovie_1 != 'y' && uslovie_1 != 'n') { goto usl1; }
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
        while (cin.fail() || Table[i].Parts < 1) { cin.clear(); cin.ignore(2000, '\n'); cout << "Ошибка ввода. Количество сост. частей: "; cin >> Table[i].Parts; }
        cout << "Цена: ";
        cin >> Table[i].Price;
        while (cin.fail() || Table[i].Price < 1) { cin.clear(); cin.ignore(2000, '\n'); cout << "Ошибка ввода. Цена ($): "; cin >> Table[i].Price; }
    d1:cout << "День: ";
        cin >> Table[i].RDate.Day;
        while (cin.fail() || !(Table[i].RDate.Day > 0 && Table[i].RDate.Day < 32)) { cin.clear(); cin.ignore(2000, '\n'); cout << "Ошибка ввода. День: "; cin >> Table[i].RDate.Day; }
        count = IntLength(Table[i].RDate.Day);
        if (count == 1) { flag[i][0] = 1; }
        //if (count != 2 and count != 1 ) { count = 0; goto d1; }
    d2:cout << "Месяц: ";
        cin >> Table[i].RDate.Month;
        while (cin.fail() || !(Table[i].RDate.Month > 0 && Table[i].RDate.Month < 13)) { cin.clear(); cin.ignore(2000, '\n'); cout << "Ошибка ввода. Месяц: "; cin >> Table[i].RDate.Month; }
        count = IntLength(Table[i].RDate.Month);
        //if (Table[i].RDate.Month < 1 or Table[i].RDate.Month > 12) { goto d2; }
        if (count == 1) { flag[i][1] = 1; }
        //if (count != 2 and count != 1) { count = 0; goto d2; }
        if (Table[i].RDate.Month < minmonth) { minmonth = Table[i].RDate.Month; i_min = i; }
        if (Table[i].RDate.Month > maxmonth) { maxmonth = Table[i].RDate.Month; i_max = i; }
    d3:cout << "Год: ";
        cin >> Table[i].RDate.Year;
        while (cin.fail() || !(Table[i].RDate.Year > 1900)) { cin.clear(); cin.ignore(2000, '\n'); cout << "Ошибка ввода. Год: "; cin >> Table[i].RDate.Year; }
        //count = IntLength(Table[i].RDate.Year);
        //if (count != 4) { count = 0; goto d3; }
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