#pragma once

#include <iostream>

class Point;

class Vector {

	//friend Point;    //b)
	//friend Point Point::movePointByVector(Point& dot, Vector& vec);   //  c)
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

	Point movePointByVector(Point& dot, Vector& vec); // d) e)

};

class Point {

	//friend Vector;  // d)
	friend Point Vector::movePointByVector(Point& dot, Vector& vec);   // e)

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
	// b) c)
	//
	//Point movePointByVector(Point& dot, Vector& vec);  

	void print() {
		printf("X: %i\n", x);
		printf("Y: %i\n", y);
		printf("Z: %i\n", z);
	}
};

// c) d) e)
//
Point Vector::movePointByVector(Point& dot, Vector& vec) {
	Point a;
	a.x = dot.x + vec.x;
	a.y = dot.y + vec.y;
	a.z = dot.z + vec.z;
	return a;
}


// �)
// 
//Point movePointByVector(Point &dot1, Vec &vec) {
//
//	Point dot2;
//
//	dot2.x = dot1.x + vec.x;
//	dot2.y = dot1.y + vec.y;
//	dot2.z = dot1.z + vec.z;
//
//	return dot2;
//
//}

void HW_3() {

	Point a(5,10,30);
	Vector b(1,0,0);
	Point c;
	Vector d;

	//movePointByVector(a, b).print();     a)
	//c.movePointByVector(a, b).print();   //b) c)
	d.movePointByVector(a, b).print();		// d) e)
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
