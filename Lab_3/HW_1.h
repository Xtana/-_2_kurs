#pragma once

#include <iostream>
#include <stdio.h> 
#include <math.h>
#include <locale.h> // Библиотека для указания локации (региональной кодировки)
#include <stdlib.h>
#include <string>
using namespace std;

class Polynomial {

	int* coef;
	int* degree;
	int len;

public:

	Polynomial(int len) {
		this->len = len;
		degree = new int[len];
		coef = new int[len];
		for (int i = 0; i < len; i++) {
			degree[i] = i;
		}
	}

	void setCoef() {
		for (int i = 0; i < len; i++) {
			cout << "Введите коэффицент одночлена со степенью " << i << " :" << endl;
			scanf_s("%i", &coef[i]);
		}
	}

	void print() {
		for (int i = 0; i < len; i++) {
			if (coef[i] == 0) {
				continue;
			}
			if ((degree[i] == 0) && (i + 1 < len)) {
				printf("%i + ", coef[i]);
				continue;
			}
			if ((degree[i] == 0) && (i + 1 == len)) {
				printf("%i", coef[i]);
				continue;
			}
			if ((degree[i] == 1) && (i + 1 < len)) {
				printf("%ix + ", coef[i]);
				continue;
			}
			if ((degree[i] == 1) && (i + 1 ==  len)) {
				printf("%ix", coef[i]);
				continue;
			}
			printf("%ix^%i", coef[i], degree[i]);
			if (i < len - 1) {
				printf(" + ");
			}
		}
	}

	Polynomial& operator+ (const Polynomial Pol) {

		Polynomial a(len);

		for (int i = 0; i < len; i++) {
			a.coef[i] = coef[i] + Pol.coef[i];
		}
		return a;
	}

	Polynomial& operator- (const Polynomial Pol) {
		Polynomial a(len);

		for (int i = 0; i < len; i++) {
			a.coef[i] = coef[i] - Pol.coef[i];
		}
		return a;
	}

	Polynomial& operator* (const Polynomial Pol) {

		Polynomial a(len+len-1);

		for (int i = 0; i < len * len; i++) {
			a.coef[i] = 0;
		}

		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				a.coef[i + j] += coef[i] * Pol.coef[j];
			}
		}
		return a;
	}
};


void HW_1() {

	setlocale(LC_ALL, "Rus");

	Polynomial a(3);
	Polynomial b(3);
	Polynomial c(3);

	a.setCoef();
	b.setCoef();

	printf("Мнтогочлен 1: ");
	a.print();
	printf("\nМнтогочлен 2: ");
	b.print();
	printf("\n\nРазность: ");
	c = a - b;
	c.print();
	cout << endl;
	printf("Сумма: ");
	c = a + b;
	c.print();
	cout << endl;
	printf("Произведение: ");
	c = a * b;
	c.print();
}

/*
Создайте класс многочленов от одной переменной, 
задаваемых степенью многочлена и массивом коэффициентов. 
Предусмотреть методы для вычисления значения многочлена для заданного аргумента, 
операции сложения, вычитания и умножения многочленов с получением нового объекта-многочлена, 
вывод на экран описания многочлена.
*/