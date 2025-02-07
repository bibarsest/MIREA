// Exam.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int num1()
{
    struct {
        char month[3]; // 3 
        char m[9]; // 9
        // 3+9=12
        char a[2]; // 2
        // 12+2=14 | округление до 16
        //char b[1]; // 1
        // 14+1=15 | округление до 16
        int year; // 4
        //char b[1]; // 1 | округление до 4
    } str;
    
    //cout << sizeof(str) << endl;
    struct {
        int Y; // 4 | округление до 8
        int* Z; // 8
        //char m[13]; // 16
    } str1;
    //cout << sizeof(str1) << endl;

    struct {
        int X; // 4
        char Y[2]; // 4
        char* Z[2]; // 16
    } str2;

    //cout << sizeof(str2) << endl;
    struct {
        char month[3]; // 3 
        //char m[9]; // 9
        char a[2]; // 2
        //int year; // 4
    } str3;

    //cout << sizeof(str3) << endl;

    struct {
        char month[3]; // 3 
        char a[2]; // 2
    } str4;

    cout << sizeof(str4) << endl;
    return { 0 };
}
void num2()
{
    //class A {
    // //private:
    //    int price;
    //    A() { price = 10; cout << price << endl; }
    //public:
    //    void construct() { A(); };
    //    ~A() { cout << "destruct\n"; }
    //};
    //A obj.construct();
}
void num3() {
    class A { 
        void f1() { cout << "f1() "; f4(); } 
    private:
        void f2() { cout << "f2() "; f4(); };
    public:
        A() { f2(); };
        void f3() { cout << "f3() "; f4(); };
    protected:
        void f4() { cout << "f4() "; };
    };
    A B; (&B)->f3();
};
void num4() {
    class A
    {
        int s1;
    public:
        void F() { cout << "out of A\n"; }
    };
    class B : public A
    {
        int s2;
    };
    B obj; obj.F();
}
//void num5()
//{
//    class A {
//        int y; double z;
//    public:
//        static int x;
//        A() { x++; y = 0; z = 0; };
//        A(int k) { x += k; y = x; };
//        A(double k) { x += 2; z = k; };
//        ~A() { cout << x << " "; };
//        A operator+(A& s) { return x + s.x; }
//        A operator-(A& s) { return x - s.x; }
//    };
//    //int operator-(A& s1, int s2) { return s1.x - s2; }
//    int A::x = 0;
//    A b(-1);
//    A c(4.1);
//    A d = b + c;
//}

//class A {
//    int y; double z;
//public:
//    static int x;
//    A() { x++; y = 0; z = 0; };
//    A(int k) { x += k; y = x; };
//    A(double k) { x += 2; z = k; };
//    ~A() { cout << x << " "; };
//    A operator+(A& s) { return x + s.x; }
//    //A operator-(A& s) { return x - s.x; }
//};
//int operator-(A& s1, int s2) { return s1.x - s2; }
//int A::x = 0;

class A {
    int y; double z;
public:
    static int x;
    A() { x++; y = 0; z = 0; }
    A(int k) { x += k; y = x; }
    A(double k) { x += 2; z = k; }
    ~A() { cout << x << " "; }
    A operator+(A& s) { return x + s.x; }
};
int operator-(A& s1, int s2) { return s1.x - s2; }
int A::x = 0;


int main()
{
    //num1();
    //num2();
    //num3();
    //num4();
    //num5();
    /*cout << A::x << endl;
    A b(-3); cout << A::x << endl;
    A c(4.1); cout << A::x << endl;
    A d = b + c; cout << A::x << endl;
    cout << "\ndone\n";*/
    A b; A c(3.0); b.x += 2; c.x = b - 2;
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
