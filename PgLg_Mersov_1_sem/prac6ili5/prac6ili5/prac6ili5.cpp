﻿// prac6ili5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//min max сколько отриц, сколько положит, массив (поменять отр с положит.)

#include <stdio.h>

int main()
{
    int a[30];
    int n, i, min, max, kotr = 0, kpol = 0;
a1: printf("vvedite dlinu massiva: ");
    scanf_s("%d", &n);
    if (n > 30 || n < 1) { printf("error dlina\n"); goto a1; }
    for (i = 0; i < n; i++)
    {
        printf("enter element a[%d] = ", i);
        scanf_s("%d", &a[i]);
        if (a[i] < 0) { kotr++; }
        if (a[i] > 0) { kpol++; }
    }
    min = max = a[0];
    for (i = 1; i < n; i++)
    {
        if (min > a[i]) { min = a[i]; }
        if (max < a[i]) { max = a[i]; }
    }
    printf("\nNEGATIVE NUMBERS: %d", kotr);
    printf("\nPOSITIVE NUMBERS: %d", kpol);
    printf("\nMIN: %d", min);
    printf("\nMAX: %d", max);
    for (i = 0; i < n; i++)
    {
        if (a[i] == min) { printf("\na[%d]=%d", i, max); }
        if (a[i] == max) { printf("\na[%d]=%d", i, min); }
        if (a[i] != min && a[i] != max) { printf("\na[%d]=%d", i, a[i]); }
        
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