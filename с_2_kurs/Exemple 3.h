#pragma once

#include <stdio.h> 
#include <math.h>
#include <locale.h> // ���������� ��� �������� ������� (������������ ���������)
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
		while (printf("���� ��� �������? "), scanf_s("%i", &number)) {
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


/*���������� 3.
�������� ����� Summa ��������� �� ���� ��������(x � y), ������������ � ������ ��� ���������� �� �����(Calculate).
���������������� ������ ��������� �������� �������� ������������������ �������� ������������� ����� �����.

����������� ������������ ����� ������ � ���������� :

#include <stdio.h>

int number, result;
while (printf("���� ��� �������? "), scanf_s("%i", &number)) {
	...
}

*/