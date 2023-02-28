#pragma once

#include <stdio.h> 
#include <math.h>
#include <locale.h> // Библиотека для указания локации (региональной кодировки)
#include <stdlib.h>

class Summa_3 {
public:
	int x;
	int y;

	Summa_3(int X, int Y) {
		x = X;
		y = Y;
	}

	void Calculate_3() {
		int number, result = 0;
		result = x + y;
		printf("%i + %i = %i\n", x, y, result);
		while (printf("Есть что сложить? "), scanf_s("%i", &number)) {
			printf("%i + %i = ", result, number);
			result = result + number;
			printf("%i\n", result);
		}
	}
};

int Exemple_3() {
	setlocale(LC_ALL, "Rus");

	Summa_3 a(33, 77);

	a.Calculate_3();
	return 0;
}


/*Упражнение 3.
Создайте класс Summa состоящий из двух значений(x и y), конструктора и метода для вычисления их суммы(Calculate).
Проиллюстрируйте работу программы вычислив значение последовательности вводимых пользователем целых чисел.

Напоминание относительно ввода данных с клавиатуры :

#include <stdio.h>

int number, result;
while (printf("Есть что сложить? "), scanf_s("%i", &number)) {
	...
}

*/