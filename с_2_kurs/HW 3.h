#pragma once

#include <stdio.h> 
#include <math.h>
#include <locale.h> // Ѕиблиотека дл€ указани€ локации (региональной кодировки)
#include <stdlib.h>

class Trigonometry {

private:
	double x;

public:

	double trig_sin() {
		return sin(x);
	}

	double trig_cos() {
		return cos(x);
	}

	void SetX_6(double X) {
		x = X;
	}

	double GetX_6() {
		return x;
	}

	void Calculate() {
		float X;
		string X1;
		while (printf("¬веденное значение в градусах: ") && scanf_s("%f", &X)) {
			X = 0.0174532925 * X;
			SetX_6(X);
			printf("«начение в радианах: %lf\n", X);
			printf("тригонометринческие функции равны sin(x) = %.4f, cos(x) = %.4f\n\n", trig_sin(), trig_cos());
		}
	}
};


int HW_3() {

	setlocale(LC_ALL, "Rus");
	 
	Trigonometry().Calculate();

	return 0;
}

/*
—оздайте класс Trigonometry состо€щий из значени€ (x), конструктора и методов дл€ вычислени€ основных тригонометрических функций (sin(x), cos(x)) от этого числа.
ѕроиллюстрируйте работу программы вычислив значение тригонометрических функций от последовательности вводимых пользователем чисел,
выводите полученные результаты на экран в формате: Ђ¬веденное значение Е, тригонометрические функции равны sin(x) = Е, cos(x) = Еї. „исла с плавающей точкой выводить в формате с 4 знаками после зап€той.

*/