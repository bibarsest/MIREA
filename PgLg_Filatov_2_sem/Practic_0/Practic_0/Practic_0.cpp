// Разработать программу, которая вводит фактические данные из таблицы,
//представленной в Вашем варианте индивидуального задания и выводит на экран таблицу,
//подобную той, которая находится в индивидуальном задании(включая заголовок и
//примечания)
// Вариант 4
// Студент Кузнецов Алексей Александрович
// Группа БАСО-04-22

#include <iostream>
using namespace std;
#include <locale.h> //русский

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
void Input()
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
void Output(int num)
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

int main()
{
    setlocale(LC_ALL, "Rus");
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
