﻿// practic3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// -15.246 0.04642 2000.1

#include "stdio.h"
#include "math.h"

int main()
{
    double a, x, y, z, xm; int c;
    printf("Vvedite kodificator: ");
    scanf_s("%d", &c);
    switch (c)
    {
    case 21: case 22: //решение контрольного примера без проверки 
        x = -15.246; y = 0.04642; z = 2000.1;
        xm = -sqrt(fabs(x));
        a = log(pow(y, xm)) * (x - (y / 2)) + pow(sin(atan(z)), 2);
        printf("%lf", a);
        break;
    case 33: case 44: return 676; //завершение работы программы
    case 5:
        printf("x y z\n"); //обработка неверного ввода и завершение работы
        scanf_s("%lf %lf %lf", &x, &y, &z);
        xm = -sqrt(fabs(x));
        a = log(pow(y, xm)) * (x - (y / 2)) + pow(sin(atan(z)), 2);
        printf("%lf", a);
        return 526; 
    default: //решение с проверкой
        printf("x y z\n");
        scanf_s("%lf %lf %lf", &x, &y, &z);
        xm = -sqrt(fabs(x));
        if (y<=0 || pow(y, xm) <= 0) { printf("error: y"); return 823; }
        if (atan(z) < -1 && atan(z) > 1) { printf("error: z"); return 923; }
        a = log(pow(y, xm)) * (x - (y / 2)) + pow(sin(atan(z)), 2);
        printf("%lf", a);
    }

    /*
    scanf_s("%lf %lf %lf", &x, &y, &z);
    xm = -sqrt(fabs(x));
    a = log(pow(y, xm)) * (x - (y / 2)) + pow(sin(atan(z)), 2);
    printf("%lf", a);
    */
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