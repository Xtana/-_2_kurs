#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class FixedPoint {

	friend ostream& operator << (ostream& os, const FixedPoint& Fix);
	friend istream& operator >> (istream& is, FixedPoint& Fix);

	int integPart = 0, fractPart = 0;


public:
	FixedPoint() {
		integPart = 0;
		fractPart = 0;
	}

	FixedPoint(int integ, int fract) {
		if (integ < 0 || fract < 0) {
			if (integ > 0) integ = -integ;
			if (fract > 0) fract = -fract;
		}
		rounding(integ, fract);
		examination();
	}

	FixedPoint(float number) {
		int integ = (int)number;
		int fract = (number - integ) * 1000;
		if (integ < 0 || fract < 0) {
			if (integ > 0) integ = -integ;
			if (fract > 0) fract = -fract;
		}
		rounding(integ, fract);
		examination();
	}

	FixedPoint& operator+ (const FixedPoint Fix) {
		FixedPoint fix;
		fix.integPart = integPart + Fix.integPart;
		fix.fractPart = fractPart + Fix.fractPart;
		if (fix.fractPart > 100) {
			fix.fractPart = fractPart - 100;
			fix.integPart++;
		}
		return fix;
	}

	FixedPoint& operator- (const FixedPoint Fix) {
		FixedPoint fix;
		fix.integPart = integPart - Fix.integPart;
		if (fractPart < Fix.fractPart) {
			fix.fractPart = fractPart + 100;
			fix.integPart--;
		}
		fix.fractPart = fractPart - Fix.fractPart;
		if (fix.fractPart > 100) {
			fix.fractPart = fix.fractPart - 100;
			fix.integPart++;
		}
		return fix;
	}

	void examination() {
		if (integPart > 9999 || integPart < -9999) {
			cout << "Неверный диапозон, значения обнулены" << endl;
			this->fractPart = 0;
			this->integPart = 0;
		}
	}

	void rounding(int integ, int fract) {
		if ((fract / 100 > 0)||(fract / 100 < 0)) {
			int k = 0, fract_i = fract;								// счетчик цифр, вспомогательная переменная fract_i

			while ((fract_i > 0)||(fract_i < 0)) {									// находим количество цифр у fract 
				k++;
				fract_i = fract_i / 10;
			}

			int k1 = k;
			while (k1 - 3 >= 0) {
				k1--;
				if (fract % 10 >= 5) fract = (fract / 10) + 1;
				else fract = (fract / 10);
			}
		}

		if (fract == 100) {
			this->fractPart = 0;
			this->integPart = integ + 1;
		}
		else {
			this->fractPart = fract;
			this->integPart = integ;
		}
	}
};

ostream& operator<< (ostream& os, const FixedPoint& Fix) {
	if (Fix.fractPart < 0) {
		if (Fix.integPart == 0) os << "-" << Fix.integPart << "." << -Fix.fractPart << endl;
		else os << Fix.integPart << "." << -Fix.fractPart << endl;
		return os;
	}
	else os << Fix.integPart << "." << Fix.fractPart << endl;
	return os;
}

istream& operator>> (istream& is, FixedPoint& Fix) {
	is >> Fix.integPart >> Fix.fractPart;

	// Округление 
	if ((Fix.fractPart / 100 > 0) || (Fix.fractPart / 100 < 0)) {
		int k = 0, fract_i = Fix.fractPart;								// счетчик цифр, вспомогательная переменная fract_i

		while ((fract_i > 0) || (fract_i < 0)) {									// находим количество цифр у fract 
			k++;
			fract_i = fract_i / 10;
		}

		int k1 = k;
		while (k1 - 3 >= 0) {
			k1--;
			if (Fix.fractPart % 10 >= 5) Fix.fractPart = (Fix.fractPart / 10) + 1;
			else Fix.fractPart = (Fix.fractPart / 10);
		}
	}

	if (Fix.fractPart == 100) {
		Fix.fractPart = 0;
		Fix.integPart = Fix.integPart + 1;
	}
	else {
		Fix.fractPart = Fix.fractPart;
		Fix.integPart = Fix.integPart;
	}

	if (Fix.integPart > 9999 || Fix.integPart < -9999) {
		cout << "Неверный диапозон, значения обнулены" << endl;
		Fix.fractPart = 0;
		Fix.integPart = 0;
	}

	return is;
}

int HW_4() {

	setlocale(LC_ALL, "Rus");

	FixedPoint a(3, 80);
	std::cout << a << '\n';   //  3.80
	FixedPoint b(-3.9);
	std::cout << b << '\n';   // -3.90
	std::cout << a + b << '\n'; // -0.10
	std::cout << a - b << '\n'; //  7.70
	FixedPoint e;
	std::cin >> e;          // 11.999999
	std::cout << e << '\n';   // 12.00


	return 0;
}

/*
Напишите класс для реализации значений типа чисел с фиксированной точкой с двумя цифрами после точки (например, 11.47, 5.00 или 1465.78). Диапазон класса должен быть от -9999.99 до 9999.99, 
в дробной части могут быть любые две цифры, не допускайте проблем с точностью.
Для хранения таких чисел используйте две целочисленные переменные: одну для целой части, другую для дробной.
Опишите в классе FixedPoint конструкторы для инициализации чисел рассматриваемого типа в двух вариантах:
1)	На основе двух целых чисел, при этом если дробная или целая части значения являются отрицательными, то число считается отрицательным;
2)	На основе чисел с плавающей точкой (float, double), для получения дробной части с нужной точностью используйте округление (например, с помощью функции round() из библиотеки cmath).
Перегрузите операторы сложения, вычитания и ввода / вывода, и имитируйте в тестовом примере использования проблему переполнения.
Кроме того, должен корректно работать код:
FixedPoint a(3, 8);
std::cout << a << '\n';   //  3.80
FixedPoint b(-3, 9);
std::cout << b << '\n';   // -3.90
std::cout << a+b << '\n'; // -0.10
std::cout << a-b << '\n'; //  7.70
FixedPoint с;
std::cin >> b;          // 11.999999
std::cout << b << '\n';   // 12.00

*/