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


// а)
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
Точка — это позиция в пространстве. Вектор — это величина, которая имеет длину и направление (но не положение).
И то, и другое можно задать в трёхмерном пространстве с помощью трёх чисел. 
Точки и векторы часто используются в компьютерной графике 
(точка для представления вершин фигуры,а векторы — для перемещения фигуры).
Создайте два класса описывающие эти геометрические объекты: Point и Vector. 
При этом Point(0.0, 1.0, 2.0) будет точкой в координатном пространстве x = 0.0, y = 1.0 и z = 2.0.
А Vector(1.0, 0.0, 0.0) будет вектором, представляющим направление только вдоль положительной оси x длиной 1.0.

Вектор может применятся к точке для перемещения точки на новую позицию. 
Это делается путем добавления направления вектора к позиции точки. 
Например, Point(0.0, 1.0, 2.0) + Vector(0.0, 2.0, 0.0) даст точку Point(0.0, 3.0, 2.0). 
Создайте для этой операции функцию movePointByVector(). 

Сделайте это всеми из перечисленных способов:
+ a)	объявите функцию movePointByVector() отдельно от классов Point и Vector, объекты этих классов предаются как параметры в эту функцию, в результате функция возвращает новый объект класса Point;
+ b)	объявите класс Point дружественным классу Vector и реализуйте метод movePointByVector () в классе Point;
+ c)	объявите метод Point:: movePointByVector () дружественным классу Vector;
+ d)	объявите класс Vector дружественным классу Point и реализуйте метод movePointByVector () в классе Vector;
+ e)	объявите метод Vector:: movePointByVector () дружественным классу Point.

*/
