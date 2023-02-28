#pragma once

#include <iostream>
#include <stdio.h> 
#include <locale.h> // Библиотека для указания локации (региональной кодировки)
#include <math.h>
using namespace std;

class Vector {

	int x, y, z;

public:

	Vector(int x = 0, int y = 0, int z = 0) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void print() {
		cout<< "( " << x << ", " << y << ", " << z << " )" << endl;
	}

	double len() {
		return sqrt((x * x)+(y * y)+(z * z));
	}

	double cos(const Vector self1, const Vector self2) {
		return (self1.x * self2.x + self1.y * self2.y + self1.z * self2.z) / (sqrt(self1.x * self1.x + self1.y * self1.y + self1.z * self1.z) * sqrt(self2.x * self2.x + self2.y * self2.y + self2.z * self2.z));
	}

	Vector& operator+ (const Vector Vec) {
		Vector vec;
		vec.x = x + Vec.x;
		vec.y = y + Vec.y;
		vec.z = z + Vec.z;
		return vec;
	}

	Vector& operator- (const Vector Vec) {
		Vector vec;
		vec.x = x - Vec.x;
		vec.y = y - Vec.y;
		vec.z = z - Vec.z;
		return vec;
	}

	Vector& operator* (const Vector Vec) {
		Vector vec;
		vec.x = x * Vec.x;
		vec.y = y * Vec.y;
		vec.z = z * Vec.z;
		return vec;
	}
};

void HW_2() {

	setlocale(LC_ALL, "Rus");

	Vector a(1, 1, 1);
	Vector b(3, 5, 0);
	Vector c;

	printf("Вектор 1:\n");
	a.print();
	printf("Вектор 2:\n");
	b.print();

	printf("\nСумма :\n");
	c = a + b;
	c.print();
	printf("Разность :\n");
	c = a - b;
	c.print();
	printf("Произведение :\n");
	c = a * b;
	c.print();
	printf("Длинна :\n");
	printf("%f\n",c.len());
	printf("Cos :\n");
	printf("%f", c.cos(a, b));
}

/*
Составить описание класса для вектора, заданного координатами его концов в трехмерном пространстве. 
Обеспечить операции сложения и вычитания векторов с получением нового вектора (суммы или разности),
вычисления скалярного произведения двух векторов, длины вектора, косинуса угла между векторами.
*/