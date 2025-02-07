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
int test1()
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
    return 0;
}

//int sum(int L, int R, int length)
//{
//    int t = 4 * length;
//    int ans = 0;
//    while (L <= R)
//    {
//        if (L % 2 != 0) ans += t[L];
//        if (R % 2 == 0) ans += t[R];
//        L = (L + 1) / 2;
//        R = (R - 1) / 2;
//    }
//    return ans;
//}
////const int length = 8;
////int t[4 * length];
////void build(int a[], int v, int L, int R)
////{
////    
////    if (L == R) t[v] = a[L];
////    else 
////    {
////        int tm = (L + R) / 2;
////        build(a, v * 2, L, tm);
////        build(a, v * 2 + 1, tm + 1, R);
////        t[v] = t[v * 2] + t[v * 2 + 1];
////    }
////}
////int sum(int v, int tl, int tr, int l, int r) {
////    if (l > r)
////        return 0;
////    if (l == tl && r == tr)
////        return t[v];
////    int tm = (tl + tr) / 2;
////    return sum(v * 2, tl, tm, l, min(r, tm))
////        + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
////}
////int main()
////{
////    //int c = sum(2,1,5);
////    //cout << c;
////    int c = sum(1,0,7,10,14);
////    cout << c;
////}
const int MAXN = 100005;

int amount_of_elements, amount_of_segments, a[MAXN], sum[4 * MAXN];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        sum[v] = a[tl];
    }
    else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        sum[v] = sum[v * 2] + sum[v * 2 + 1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return sum[v];
    }
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) +
        query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Количество элементов в нижней строке дерева: "; cin >> amount_of_elements;
    cout << "Количество отрезков: "; cin >> amount_of_segments;
    for (int i = 1; i <= amount_of_elements; i++) {
        cout << "a[" << i << "]: "; cin >> a[i]; 
    }
    build(1, 1, amount_of_elements);
    for (int i = 1; i <= amount_of_segments; i++) {
        int l, r;
        cout << "Номер первого элемента отрезка: "; cin >> l; 
        cout << "Номер последнего элемента отрезка: "; cin >> r; 
        cout << query(1, 1, amount_of_elements, l, r) << endl;
    }
    return 0;
}