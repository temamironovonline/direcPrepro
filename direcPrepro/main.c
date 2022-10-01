#include "Header.h"
#define square(a) pow(a,2)


#define GetLength(yx1, yy1, yx2, yy2) sqrt(square(yx2 - yx1) + square(yy2 - yy1))

#define a1 4
#define b1 7
#define c1 6

int main(void)
{
	system("chcp 1251>nul");
	while (1)
	{
		int number;
		while (1)
		{
			printf("\nВыберите действие:\n1 - Нахождение длины отрезка по координатам двух точек\n2 - Проверка существования треугольника и нахождение периметра и площади\n");
			scanf_s("%d", &number);
			if (number == 1 || number == 2) {
				break;
			}
			else
			{
				system("cls");
				printf("Введены некоректнные данные!!! Повторите ввод!");
			}
		}
		
		if (number == 1) {
			system("cls");
			GetLengthOtr();
			system("pause");
			system("cls");
		}
		if (number == 2) {
			system("cls");
			GetPerPlosh();
			system("pause");
			system("cls");
		}
	}
	return 0;
}



void GetLengthOtr() // Нахождение длины отрезка по введённым координатам
{
	int x1, y1, x2, y2;
	printf("Есть две точки A(x1; y1) и B(x2; y2)\n");
	printf("Введите x1: ");
	scanf_s("%d", &x1);
	printf("Введите y1: ");
	scanf_s("%d", &y1);
	printf("Введите x2: ");
	scanf_s("%d", &x2);
	printf("Введите y2: ");
	scanf_s("%d", &y2);
	float dl = GetLength(x1, y1, x2, y2);
	printf("Длина отрезка: %f\n", dl);
}


void GetPerPlosh() // Проверка треугольника и нахождение его периметра и площади
{
	
	int prov = GetCheck();
	if (prov == 0)
	{
		printf("Введённые точки не образуют треугольник!\n");
	}
	else
	{
		float P = a1 + b1 + c1;
		printf("Периметр треугольника равен: %f\n", P);
		float p = P / 2;
		float h = (2 * sqrt(p * (p - a1) * (p - b1) * (p - c1))) / a1;
		float S = 0.5 * a1 * h;
		printf("Площадь треугольника равна: %f\n", S);
	}
}

int GetCheck() // Проверка существования треугольника
{
#if (a1 >= b1 + c1)
	return 0;
#elif (b1 >= a1 + c1)
	return 0;
#elif (c1 >= a1 + b1)
	return 0;
#else
	return 1;
#endif
}
