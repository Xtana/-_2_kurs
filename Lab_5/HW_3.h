#include <iostream>

class Point;

class Vector {
	
	friend Point;

	int x, y, z;

public:

	Vector() {
		x = 0;
		y = 0;
		z = 0;
	}
	Vector(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

};

class Point {

	int x, y, z;

public:
	Point() {
		x = 0;
		y = 0;
		z = 0;
	}
	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void print() {
		printf("X: %i\n", x);
		printf("Y: %i\n", y);
		printf("Z: %i\n\n", z);
	}

	int operator[](string str) {
		if (str == "x") return x;
		if (str == "y") return y;
		if (str == "z") return z;
	}

	int operator[](int a) {
		if (a == 0) return x;
		if (a == 1) return y;
		if (a == 2) return z;
	}
	Point& operator+(Vector& vec);
	Point& operator-(Vector& vec);
};

Point& Point::operator+(Vector& vec) {
	this->x = x + vec.x;
	this->y = y + vec.y;
	this->z = z + vec.z;
	return *this;
}

Point& Point::operator-(Vector& vec) {
	this->x = x - vec.x;
	this->y = y - vec.y;
	this->z = z - vec.z;
	return *this;
}

void HW_3() {

	Point a(10, 10, 30);
	Vector b(2, 5, 0);
	Point d;

	d = a + b;
	d.print();
	d = a - b;
	d.print();
	printf("%i\n", a["z"]);
	printf("%i", a[2]);
	

}

/*
����� � ��� ������� � ������������. ������ � ��� ��������, ������� ����� ����� � ����������� (�� �� ���������).
� ��, � ������ ����� ������ � ��������� ������������ � ������� ��� �����.
����� � ������� ����� ������������ � ������������ �������
(����� ��� ������������� ������ ������,� ������� � ��� ����������� ������).
�������� ��� ������ ����������� ��� �������������� �������: Point � Vector.
��� ���� Point(0.0, 1.0, 2.0) ����� ������ � ������������ ������������ x = 0.0, y = 1.0 � z = 2.0.
� Vector(1.0, 0.0, 0.0) ����� ��������, �������������� ����������� ������ ����� ������������� ��� x ������ 1.0.

������ ����� ���������� � ����� ��� ����������� ����� �� ����� �������.
��� �������� ����� ���������� ����������� ������� � ������� �����.
��������, Point(0.0, 1.0, 2.0) + Vector(0.0, 2.0, 0.0) ���� ����� Point(0.0, 3.0, 2.0).
�������� ��� ���� �������� ������� movePointByVector().

�������� ��� ����� �� ������������� ��������:
+ a)	�������� ������� movePointByVector() �������� �� ������� Point � Vector, ������� ���� ������� ��������� ��� ��������� � ��� �������, � ���������� ������� ���������� ����� ������ ������ Point;
+ b)	�������� ����� Point ������������� ������ Vector � ���������� ����� movePointByVector () � ������ Point;
+ c)	�������� ����� Point:: movePointByVector () ������������� ������ Vector;
+ d)	�������� ����� Vector ������������� ������ Point � ���������� ����� movePointByVector () � ������ Vector;
+ e)	�������� ����� Vector:: movePointByVector () ������������� ������ Point.

*/


/*
����������� ��������� �� 3 ������� ������������ ������ � 1, 
������� ���������� ������ movePointByVector() ����������� ���������� 
�������� � ��������� ��� ��������������� ���������. ����� ����, 
����������� �������� [] ��� ��������� �������� ��������� x, y, z �� 
���������������� ������� 0,1,2 � ������� �x�, �y�, �z�.
*/