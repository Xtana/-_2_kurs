#pragma once

#include <stdio.h> 
#include <math.h>
#include <locale.h> // Библиотека для указания локации (региональной кодировки)
#include <stdlib.h>

class Point_2 {
public:
	double x, y;
	//  конструктор инициализации
	Point_2(double ax = 0, double ay = 0) {
		this->x = ax;
		this->y = ay;
	}
	//  конструктор инициализации
	Point_2(Point_2& ap) {
		x = ap.x;
		y = ap.y;
	}

	void remove_point_2(double ax = 0, double ay = 0) {
		x = ax;
		y = ay;
	}

	double distans_2(Point_2 p) {
		double l;
		l = sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
		return l;
	}

};

class Circle_2 {
public:
	Point_2 p;
	double r;
	//  конструктор инициализации
	Circle_2(double x, double y, double ar) {
		p.x = x;
		p.y = y;
		r = fabs(ar);
	}
	//  конструктор инициализации
	Circle_2(Point_2 ap, double ar) {
		p.x = ap.x;
		p.y = ap.y;
		r = fabs(ar);
	}
	//  конструктор копирования
	Circle_2(const Circle_2& c) {
		p.x = c.p.x;
		p.y = c.p.y;
		r = c.r;
	}

	int in_circle_2(Point_2 ap) {
		if ((p.x - ap.x) * (p.x - ap.x) + (p.y - ap.y) * (p.y - ap.y) < r * r)
			return 1;
		else
			return 0;
	}

	void move_circle_2(Point_2 ap) {
		p.x = ap.x;
		p.y = ap.y;
	}

	void re_r_2(double ar) {
		r = ar;
	}

	int in_circle_2(double l, Circle_2 c2) {
		if (l <= r + c2.r)
			return 1;
		else
			return 0;
	}

};


int Exemple_2() {

	setlocale(LC_ALL, "Rus");

	Point_2 p1 = { 0.0, 0.0 };
	Point_2 p2 = { 0.0, 3.0 };

	Circle_2 c1 = Circle_2{ 2.5, -1.2, 0.5 };
	Circle_2 c2_1 = Circle_2(p1, 1.49);
	Circle_2 c2_2 = Circle_2(p2, 1.5);
	Circle_2 c3 = Circle_2(c1);

	printf("p1 in circle c1: %i\n", c1.in_circle_2(p1)); // аналогично in_circle(c1, p)
	c1.move_circle_2(p1);
	printf("p1 in circle c1: %i\n", c1.in_circle_2(p1)); // аналогично in_circle(c1, p)

	printf("1)   x = %6.3f, y = %6.3f, r = %6.3f\n", c1.p.x, c1.p.y, c1.r);
	printf("2.1) x = %6.3f, y = %6.3f, r = %6.3f\n", c2_1.p.x, c2_1.p.y, c2_1.r);
	printf("2.2) x = %6.3f, y = %6.3f, r = %6.3f\n", c2_2.p.x, c2_2.p.y, c2_2.r);
	printf("3)   x = %6.3f, y = %6.3f, r = %6.3f\n\n\n", c3.p.x, c3.p.y, c3.r);

	printf("Изменим радиуc окружности 1\n");
	c1.re_r_2(5);
	printf("x = %6.3f, y = %6.3f, r = %6.3f\n\n\n", c1.p.x, c1.p.y, c1.r);


	printf("Проверим пересечение окружностей 2.1 и 2.2\n");
	printf("Окружности пересекаются: %d\n\n", c2_1.in_circle_2(p1.distans_2(p2), c2_2));

	return 0;
}

/*Упражнение 2.
Сделайте Point классом с методами для инициализации(конструктором), методом для изменения координат точки
и методом для вычисления расстояния между двумя точками.
Измените реализацию пункта 1.2 использую возможности класса Point.*/
