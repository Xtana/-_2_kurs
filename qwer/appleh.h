
#include <iostream>
#include <stdio.h> 
#include <math.h>
#include <locale.h> // Библиотека для указания локации (региональной кодировки)
#include <stdlib.h>
#include <string>
using namespace std;

class Apple {

	friend ostream& operator<< (ostream& os, const Apple& A);
	double value, price;

public:

	Apple() {
		this->price = 0;
		this->value = 0;
	}

	Apple(float value) {
		this->price = 0;
		this->value = value;
	}

	Apple operator+ (const Apple& A) {
		Apple a;
		a.price += (value + A.value) * 0.05;
		return a;
	}

	Apple operator- (const Apple& A) {
		Apple a;
		a.price += (value - A.value) * 0.05;
		return a;
	}

	Apple operator* (const Apple& A) {
		Apple a;
		a.price += (value * A.value) * 0.05;
		return a;
	}

	Apple operator/ (const Apple& A) {
		Apple a;
		a.price += (value / A.value) * 0.05;
		return a;
	}

	Apple& operator+= (const Apple& A) {
		price += A.price;
		return *this;
	}
};

ostream& operator<< (ostream& os, const Apple& A) {
	return os << "Стоимость всех арифметических операций = " << A.price << endl;
}

int apple() {

	setlocale(LC_ALL, "Rus");

	Apple a1(20), a2(10), a3;

	a3 += a1 + a2;
	a3 += a1 - a2;
	a3 += a1 * a2;
	a3 += a1 / a2;
	cout << a3;
	return 0;
}
