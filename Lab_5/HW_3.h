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
“очка Ч это позици€ в пространстве. ¬ектор Ч это величина, котора€ имеет длину и направление (но не положение).
» то, и другое можно задать в трЄхмерном пространстве с помощью трЄх чисел.
“очки и векторы часто используютс€ в компьютерной графике
(точка дл€ представлени€ вершин фигуры,а векторы Ч дл€ перемещени€ фигуры).
—оздайте два класса описывающие эти геометрические объекты: Point и Vector.
ѕри этом Point(0.0, 1.0, 2.0) будет точкой в координатном пространстве x = 0.0, y = 1.0 и z = 2.0.
ј Vector(1.0, 0.0, 0.0) будет вектором, представл€ющим направление только вдоль положительной оси x длиной 1.0.

¬ектор может примен€тс€ к точке дл€ перемещени€ точки на новую позицию.
Ёто делаетс€ путем добавлени€ направлени€ вектора к позиции точки.
Ќапример, Point(0.0, 1.0, 2.0) + Vector(0.0, 2.0, 0.0) даст точку Point(0.0, 3.0, 2.0).
—оздайте дл€ этой операции функцию movePointByVector().

—делайте это всеми из перечисленных способов:
+ a)	объ€вите функцию movePointByVector() отдельно от классов Point и Vector, объекты этих классов предаютс€ как параметры в эту функцию, в результате функци€ возвращает новый объект класса Point;
+ b)	объ€вите класс Point дружественным классу Vector и реализуйте метод movePointByVector () в классе Point;
+ c)	объ€вите метод Point:: movePointByVector () дружественным классу Vector;
+ d)	объ€вите класс Vector дружественным классу Point и реализуйте метод movePointByVector () в классе Vector;
+ e)	объ€вите метод Vector:: movePointByVector () дружественным классу Point.

*/


/*
ƒоработайте программу из 3 задани€ лабораторной работы є 1, 
заменив функционал метода movePointByVector() перегрузкой операторов 
сложени€ и вычитани€ дл€ соответствующих операндов.  роме того, 
перегрузите оператор [] дл€ получени€ значений координат x, y, z по 
соответствующему индексу 0,1,2 и символу УxФ, УyФ, УzФ.
*/