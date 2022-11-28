/*-------------------------------------------------------------------------------------------------------------
34-15*2=4
Вариант 4. Задача: Дан двумерный массив, размером (n⋅на⋅m). Найти минимальный элемент в каждой строке матрицы.
Затем все отрицательные элементы каждой строки заменить на соответствующий найденный
минимальный элемент, в случае отсутствия в строке отрицательных элементов данную строку
заменить строкой, содержащую максимальный элемент из найденных минимальных
-------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <string.h>
#include "stdio.h"
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	const int ASTROKI_MAX = 10, ASTOLBCI_MAX = 10;
	int ASTROKI, ASTOLBCI;
	printf("Количество строк: ");
	scanf_s("%d", &ASTROKI);
	printf("Количество столбцов: ");
	scanf_s("%d", &ASTOLBCI);
	int array[ASTROKI_MAX][ASTOLBCI_MAX];
	//int min[ASTROKI_MAX];
	int min, max_min;

	for (int i = 0; i < ASTROKI; i++)
	{
		for (int j = 0; j < ASTOLBCI; j++)
		{
			printf("A[%d][%d] = ", i, j);
			scanf_s("%d", &array[i][j]);
		}
	}
	printf("Исходный массив:\n");
	for (int i = 0; i < ASTROKI; i++)
		for (int j = 0; j < ASTOLBCI; j++)
		{
			printf("A[%d][%d]=%d\n", i, j, array[i][j]); //Вывод исходного массива
		}
	printf("Модифицированный массив:\n");
	for (int flag = 0, i = 0; i < ASTROKI; i++)
	{
		min = 10000;
		max_min = -10000;
		for (int j = 0; j < ASTOLBCI; j++)
		{
			if (array[i][j] < min) { min = array[i][j]; }
			if (array[i][j] < 0) { flag = 1; }
			if (min > max_min) { max_min = min; }
		}
		if (flag == 0)
		{
			for (int j = 0; j < ASTOLBCI; j++) { array[i][j] = max_min; }
		}
		for (int k = 0; k < ASTOLBCI; k++)
		{
			if (array[i][k] < 0) { array[i][k] = min; };
			printf("A[%d][%d]=%d\n", i, k, array[i][k]);
		}
	}

}
