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
			cout << "�������� ��������, �������� ��������" << endl;
			this->fractPart = 0;
			this->integPart = 0;
		}
	}

	void rounding(int integ, int fract) {
		if ((fract / 100 > 0)||(fract / 100 < 0)) {
			int k = 0, fract_i = fract;								// ������� ����, ��������������� ���������� fract_i

			while ((fract_i > 0)||(fract_i < 0)) {									// ������� ���������� ���� � fract 
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

	// ���������� 
	if ((Fix.fractPart / 100 > 0) || (Fix.fractPart / 100 < 0)) {
		int k = 0, fract_i = Fix.fractPart;								// ������� ����, ��������������� ���������� fract_i

		while ((fract_i > 0) || (fract_i < 0)) {									// ������� ���������� ���� � fract 
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
		cout << "�������� ��������, �������� ��������" << endl;
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
�������� ����� ��� ���������� �������� ���� ����� � ������������� ������ � ����� ������� ����� ����� (��������, 11.47, 5.00 ��� 1465.78). �������� ������ ������ ���� �� -9999.99 �� 9999.99, 
� ������� ����� ����� ���� ����� ��� �����, �� ���������� ������� � ���������.
��� �������� ����� ����� ����������� ��� ������������� ����������: ���� ��� ����� �����, ������ ��� �������.
������� � ������ FixedPoint ������������ ��� ������������� ����� ���������������� ���� � ���� ���������:
1)	�� ������ ���� ����� �����, ��� ���� ���� ������� ��� ����� ����� �������� �������� ��������������, �� ����� ��������� �������������;
2)	�� ������ ����� � ��������� ������ (float, double), ��� ��������� ������� ����� � ������ ��������� ����������� ���������� (��������, � ������� ������� round() �� ���������� cmath).
����������� ��������� ��������, ��������� � ����� / ������, � ���������� � �������� ������� ������������� �������� ������������.
����� ����, ������ ��������� �������� ���:
FixedPoint a(3, 8);
std::cout << a << '\n';   //  3.80
FixedPoint b(-3, 9);
std::cout << b << '\n';   // -3.90
std::cout << a+b << '\n'; // -0.10
std::cout << a-b << '\n'; //  7.70
FixedPoint �;
std::cin >> b;          // 11.999999
std::cout << b << '\n';   // 12.00

*/