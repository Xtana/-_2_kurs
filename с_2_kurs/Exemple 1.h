#pragma once

#include <stdio.h> 
#include <math.h>
#include <locale.h> // Библиотека для указания локации (региональной кодировки)
#include <stdlib.h>

typedef struct point_1 {
	double x, y;
} point_1;

class Circle_1 {
public:
	point_1 p;
	double r;
	//  конструктор инициализации
	Circle_1(double x, double y, double ar) {
		p.x = x;
		p.y = y;
		r = fabs(ar);
	}
	//  конструктор инициализации
	Circle_1(point_1 ap, double ar) {
		p.x = ap.x;
		p.y = ap.y;
		r = fabs(ar);
	}
	//  конструктор копирования
	Circle_1(const Circle_1& c) {
		p.x = c.p.x;
		p.y = c.p.y;
		r = c.r;
	}

	int in_circle_1(point_1 ap) {
		if ((p.x - ap.x) * (p.x - ap.x) + (p.y - ap.y) * (p.y - ap.y) < r * r)
			return 1;
		else
			return 0;
	}

	void move_circle_1(point_1 ap) {
		p.x = ap.x;
		p.y = ap.y;
	}



	void re_r_1(double ar) {
		r = ar;
	}

	int in_circle_1(Circle_1 c2) {
		if (sqrt((p.x - c2.p.x) * (p.x - c2.p.x) + (p.y - c2.p.y) * (p.y - c2.p.y)) <= r + c2.r)
			return 1;
		else
			return 0;
	}

};


void Exemple_1() {

	setlocale(LC_ALL, "Rus");

	point_1 p1 = { 200.0, 2.0 };
	point_1 p2 = { 5.0, 2.0 };

	Circle_1 c1 = Circle_1{ 2.5, -1.2, 0.5 };
	Circle_1 c2_1 = Circle_1(p1, 1);
	Circle_1 c2_2 = Circle_1(p2, 2);
	Circle_1 c3 = Circle_1(c1);

	printf("p in circle c1: %i\n", c1.in_circle_1(p1)); // аналогично in_circle(c1, p)
	c1.move_circle_1(p1);
	printf("p in circle c1: %i\n", c1.in_circle_1(p1)); // аналогично in_circle(c1, p)

	printf("1)   x = %6.3f, y = %6.3f, r = %6.3f\n", c1.p.x, c1.p.y, c1.r);
	printf("2.1) x = %6.3f, y = %6.3f, r = %6.3f\n", c2_1.p.x, c2_1.p.y, c2_1.r);
	printf("2.2) x = %6.3f, y = %6.3f, r = %6.3f\n", c2_2.p.x, c2_2.p.y, c2_2.r);
	printf("3)   x = %6.3f, y = %6.3f, r = %6.3f\n\n\n", c3.p.x, c3.p.y, c3.r);

	printf("Изменим радиуc окружности 1\n");
	c1.re_r_1(5);
	printf("x = %6.3f, y = %6.3f, r = %6.3f\n\n\n", c1.p.x, c1.p.y, c1.r);

	printf("Проверим пересечение окружностей 2.1 и 2.2\n");
	printf("Окружности пересекаются: %d\n\n", c2_1.in_circle_1(c2_2));
}



/*

Упражнение 1.
1.1. Добавьте метод который изменяет радиус окружности.
1.2. Добавьте метод определяющий пересикаются ли окружности.
1.3. Проиллюстрируйте внесённые изменения примерами.

*/
