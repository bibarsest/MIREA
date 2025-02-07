// Разработать программу, которая вводит фактические данные из таблицы,
//представленной в Вашем варианте индивидуального задания и выводит на экран таблицу,
//подобную той, которая находится в индивидуальном задании(включая заголовок и
//примечания)
// Вариант 4
// Студент Кузнецов Алексей Александрович
// Группа БАСО-04-22

#include <iostream>
using namespace std;
//#include <locale.h> //русский
#include <Windows.h>

int n = 80; //max ширина таблицы
const int name = 17, company = 18, parts = 30, price = 15; //длины полей таблицы
int num;
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
    cout.fill('-'); cout.width(name); cout << left << "|"; cout.width(company); cout << left << "|"; cout.width(parts); cout << left << "|"; cout.width(price); cout << left << "|"; cout << "|" << endl;
}
void Preset() //шапка программы
{
    cout.width(n); cout << left << "| Офисные пакеты"; cout << "|" << endl;
    DrawLine();
    cout.width(name); cout << left << "| Наименование";
    cout.width(company); cout << left << "| Производитель";
    cout.width(parts); cout << left << "| Количество сост. частей";
    cout.width(price); cout << left << "| Цена ($)"; cout << "|" << endl;
}

//struct Lines
//{
//    string Name{};
//    string Company{};
//    string Parts{};
//    string Price{};
//};
//struct Lines line;

char lines1[name], lines2[company]; int lines3, lines4;
char lines5[name], lines6[company]; int lines7, lines8;
char lines9[name], lines10[company]; int lines11, lines12;
char lines[12][20];
void Input()
{
    //1 строка
    for (int i = 0; i < 3; i++)
    {
        cout << "Наименование: ";
        //cin.getline(lines[1+i*4], name);
        cin >> lines[1 + i * 4];
        cout << "Производитель: ";
        //cin.getline(lines[2+i*4], company);
        cin >> lines[2 + i * 4];
        cout << "Количество сост. частей: ";
        cin >> lines[3 + i * 4];
        while (cin.fail() || (int)lines[3 + i * 4][0] < 1) { cin.clear(); cin.ignore(2000, '\n'); cout << "Ошибка ввода. Количество сост. частей: "; cin >> lines[3 + i * 4]; }
        cout << "Цена ($): ";
        cin >> lines[4 + i * 4];
        while (cin.fail() || (int)lines[4 + i * 4][0] < 0) { cin.clear(); cin.ignore(2000, '\n'); cout << "Ошибка ввода. Цена ($): "; cin >> lines[4 + i * 4]; }
    }
    ////2 строка
    //cout << "Наименование: ";
    //cin.get(); //пропускаю /n в стеке
    //cin.getline(lines5, name);
    //cout << "Производитель: ";
    //cin.getline(lines6, company);
    //cout << "Количество сост. частей: ";
    //cin >> lines7;
    //cout << "Цена ($): ";
    //cin >> lines8;
    ////3 строка
    //cout << "Наименование: ";
    //cin.get(); //пропускаю /n в стеке
    //cin.getline(lines9, name);
    //cout << "Производитель: ";
    //cin.getline(lines10, company);
    //cout << "Количество сост. частей: ";
    //cin >> lines11;
    //cout << "Цена ($): ";
    //cin >> lines12;
    //cout << endl;
}
void Output(int num) // старый вывод
{
    switch (num)
    {
    case 1:
        cout.fill(' ');
        /*cout.width(name - size(line.Name)); cout << left << "|" << left << line.Name;
        cout.width(company - size(line.Company)); cout << left << "|" << left << line.Company;
        cout.width(parts - size(line.Parts)); cout << left << "|" << left << line.Parts;
        cout.width(price - size(line.Price)); cout << left << "|" << left << line.Price; cout << "|" << endl;*/
        cout << left << "| "; cout.width(name - 2); cout << left << lines[1];
        cout << left << "| "; cout.width(company - 2); cout << left << lines[2];
        cout << left << "| "; cout.width(parts - 2); cout << left << lines[3];
        cout << left << "| "; cout.width(price - 2); cout << left << lines[4]; cout << "|" << endl;
        break;
    case 2:
        cout.fill(' ');
        cout << left << "| "; cout.width(name - 2); cout << left << lines[5];
        cout << left << "| "; cout.width(company - 2); cout << left << lines[6];
        cout << left << "| "; cout.width(parts - 2); cout << left << lines[7];
        cout << left << "| "; cout.width(price - 2); cout << left << lines[8]; cout << "|" << endl;
        break;
    case 3:
        cout.fill(' ');
        cout << left << "| "; cout.width(name - 2); cout << left << lines[9];
        cout << left << "| "; cout.width(company - 2); cout << left << lines[10];
        cout << left << "| "; cout.width(parts - 2); cout << left << lines[11];
        cout << left << "| "; cout.width(price - 2); cout << left << lines[12]; cout << "|" << endl;
        break;
    }

}
void Output(int num, int i) // рефакторинг старой функции
{
    //for (int _num = num; num < _num + 1; num++)
    for (num; num < 3; num++)
    {
        cout.fill(' ');
        cout << left << "| "; cout.width(name - 2); cout << left << lines[1 + num * 4];
        cout << left << "| "; cout.width(company - 2); cout << left << lines[2 + num * 4];
        cout << left << "| "; cout.width(parts - 2); cout << left << lines[3 + num * 4];
        cout << left << "| "; cout.width(price - 2); cout << left << lines[4 + num * 4]; cout << "|" << endl;
        DrawLineWithSections();
    }
    //DrawLineWithSections();
}
int main()
{
    //setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //cin >> line.Name >> line.Company >> line.Parts >> line.Price;
    Input();
    DrawLine();
    Preset();
    DrawLineWithSections();
    /*Output(1,1);
    DrawLineWithSections();
    Output(2,1);
    DrawLineWithSections();
    Output(3,1);
    DrawLine();*/
    Output(0, 3);
    cout.fill(' ');
    cout.width(n); cout << left << "| Примечание: возможно бесплатно получить продукт StarOffice через Internet "; cout << "|" << endl;
    DrawLine();
    system("pause");
}
