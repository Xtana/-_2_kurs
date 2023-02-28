#pragma once

#include <iostream>
#include <stdio.h> 
#include <math.h>
#include <locale.h> // ���������� ��� �������� ������� (������������ ���������)
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
			cout << "������� ���������� ��������� �� �������� " << i << " :" << endl;
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

	printf("���������� 1: ");
	a.print();
	printf("\n���������� 2: ");
	b.print();
	printf("\n\n��������: ");
	c = a - b;
	c.print();
	cout << endl;
	printf("�����: ");
	c = a + b;
	c.print();
	cout << endl;
	printf("������������: ");
	c = a * b;
	c.print();
}

/*
�������� ����� ����������� �� ����� ����������, 
���������� �������� ���������� � �������� �������������. 
������������� ������ ��� ���������� �������� ���������� ��� ��������� ���������, 
�������� ��������, ��������� � ��������� ����������� � ���������� ������ �������-����������, 
����� �� ����� �������� ����������.
*/