#include <stdio.h> 
#include <math.h>
#include <locale.h> // Библиотека для указания локации (региональной кодировки)
#include <stdlib.h>


class Summa {
private:
	int x;
	int y;

public:
	// конструктор
	Summa(int X, int Y) {
		x = X;
		y = Y;
	}

	int GetX_4() {
		return x;
	}

	void SetX_4(int valueX) {
		x = valueX;
	}

	int GetY_4() {
		return y;
	}

	void SetY_4(int valueX) {
		y = valueX;
	}


	void Calculate() {
		int number, result;
		result = x + y;
		printf("%i + %i = %i\n", x, y, result);
		while (printf("Есть что сложить? "), scanf_s("%i", &number)) {
			printf("%i + %i = ", result, number);
			result = result + number;
			printf("%i\n", result);
		}
	}
};

int Exemple_4() {
	setlocale(LC_ALL, "Rus");

	Summa a(5, 6);

	printf("Исходные значерия:   X = %i  Y = %i\n", a.GetX_4(), a.GetY_4());
	a.SetX_4(1);
	a.SetY_4(2);
	printf("Измененные значерия: X = %i  Y = %i\n", a.GetX_4(), a.GetY_4());

	a.Calculate();
	return 0;
}

/*Упражнение 4.
Модифицируйте программу из упражнения 3 таким образом, что:
-атребуты x и y становятся private
- для установки их значений используются функции set_x и set_y, для их получения get_x и get_y
Проиллюстрируйте внесённые изменения на примере.*/
