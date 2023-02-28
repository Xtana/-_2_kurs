#pragma once
#include <stdio.h> 
#include <math.h>
#include <locale.h> // Ѕиблиотека дл€ указани€ локации (региональной кодировки)
#include <stdlib.h>

class Circle {
private:
	const double pi = 3.14;
	double xO, yO;
	double r, s = 0, p = 0;

public:

	Circle() {
		xO = 0;
		yO = 0;
		r = 1;
	}

	Circle(double XO, double YO, double R) {
		xO = XO;
		yO = YO;
		r = R;
	}

	double circle_area() {
		s = pi * r * r;
		return s;
	}

	double circle_perimeter() {
		p = 2 * pi * r;
		return p;
	}

	bool in_circle(double XO, double YO) {
		if (XO * XO + YO * YO <= r * r)
			return true;
		else
			return false;
	}

	void Set_X(double XO) {
		xO = XO;
	}

	void Set_Y(double YO) {
		yO = YO;
	}

	void Set_R(double R) {
		r = R;
	}

	double Get_X() {
		return xO;
	}

	double Get_Y() {
		return yO;
	}

	double Get_R() {
		return r;
	}

	double Get_S() {
		return s;
	}

	double Get_P() {
		return p;
	}
};

class Rectangle {
private:
	double x1, y1, x2, y2, x3, y3, x4, y4;
	double s = 0, p = 0;

public:

	Rectangle() {
		x1 = 0; x2 = 0; x3 = 0; x4 = 0;
		y1 = 0; y2 = 0; y3 = 0; y4 = 0;
	}

	Rectangle(double X1, double Y1, double X2, double Y2, double X3, double Y3, double X4, double Y4) {
		x1 = X1; x2 = X2; x3 = X3; x4 = X4;
		y1 = Y1; y2 = Y2; y3 = Y3; y4 = Y4;
	}

	double calculate_side_rectangle_a() {
		double a;
		a = sqrt((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4));
		return a;
	}

	double calculate_side_rectangle_b() {
		double b;
		b = sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
		return b;
	}

	double rectangle_area(double a, double b) {
		s = a * b;
		return s;
	}

	double rectangle_perimeter(double a, double b) {
		p = 2 * a * b;
		return p;
	}

	bool in_rectangle(double x, double y) {
		if (x >= x1 && x <= x2 && y >= y3 && y <= y2)
			return true;
		else
			return false;
	}

	// Set

	void Set_X1(double X1) {
		x1 = X1;
	}

	void Set_Y1(double Y1) {
		y1 = Y1;
	}

	void Set_X2(double X2) {
		x2 = X2;
	}

	void Set_Y2(double Y2) {
		y2 = Y2;
	}

	void Set_X3(double X3) {
		x3 = X3;
	}

	void Set_Y3(double Y3) {
		y3 = Y3;
	}

	void Set_X4(double X4) {
		x4 = X4;
	}

	void Set_Y4(double Y4) {
		y4 = Y4;
	}

	// Get

	double Get_X1() {
		return x1;
	}

	double Get_Y1() {
		return y1;
	}

	double Get_X2() {
		return x2;
	}

	double Get_Y2() {
		return y2;
	}

	double Get_X3() {
		return x3;
	}

	double Get_Y3() {
		return y3;
	}

	double Get_X4() {
		return x4;
	}

	double Get_Y4() {
		return y4;
	}

	double Get_S() {
		return s;
	}

	double Get_P() {
		return p;
	}

};

int HW_2() {

	setlocale(LC_ALL, "Rus");

	//______________ –”√______________//

	Circle A(1, 1, 5);

	A.circle_area();
	A.circle_perimeter();

	printf("ќ –”∆Ќќ“№\n");
	printf("xO - %.3f\n", A.Get_X());
	printf("yO - %.3f\n", A.Get_Y());
	printf("r  - %.3f\n", A.Get_R());
	printf("s  - %.3f\n", A.Get_S());
	printf("p  - %.3f\n\n", A.Get_P());

	printf("“очко лежмт внутри окружности: %d\n\n", A.in_circle(1, 2));
	printf("»зменим параметры\n");

	A.Set_X(0); A.Set_Y(0); A.Set_R(2);

	printf("xO - %.3f\n", A.Get_X());
	printf("yO - %.3f\n", A.Get_Y());
	printf("r  - %.3f\n\n\n", A.Get_R());

	//______________ѕ–яћќ”√ќЋ№Ќ» ______________//

	Rectangle B(-1, 1, 1, 1, 1, -1, -1, -1);

	B.rectangle_area(B.calculate_side_rectangle_a(), B.calculate_side_rectangle_b());
	B.rectangle_perimeter(B.calculate_side_rectangle_a(), B.calculate_side_rectangle_b());

	printf("ѕ–яћќ”√ќЋ№Ќ» \n");
	printf("x1 - %.3f\n", B.Get_X1());
	printf("y1 - %.3f\n", B.Get_Y1());
	printf("x2 - %.3f\n", B.Get_X2());
	printf("y2 - %.3f\n", B.Get_Y2());
	printf("x3 - %.3f\n", B.Get_X3());
	printf("y3 - %.3f\n", B.Get_Y3());
	printf("x4 - %.3f\n", B.Get_X4());
	printf("y4 - %.3f\n", B.Get_Y4());
	printf("s  - %.3f\n", B.Get_S());
	printf("p  - %.3f\n\n", B.Get_P());

	printf("“очко лежмт внутри пр€моугольника: %d\n\n", B.in_rectangle(0, 1.1));
	printf("»зменим параметры\n");

	B.Set_X1(0); B.Set_Y1(0); B.Set_X2(0); B.Set_Y2(2); B.Set_X3(2); B.Set_Y3(2); B.Set_X4(2); B.Set_Y4(0);

	printf("x1 - %.3f\n", B.Get_X1());
	printf("y1 - %.3f\n", B.Get_Y1());
	printf("x2 - %.3f\n", B.Get_X2());
	printf("y2 - %.3f\n", B.Get_Y2());
	printf("x3 - %.3f\n", B.Get_X3());
	printf("y3 - %.3f\n", B.Get_Y3());
	printf("x4 - %.3f\n", B.Get_X4());
	printf("y4 - %.3f\n", B.Get_Y4());

	return 0;
}



/*—оздайте три класса геометрических фигур атрибутами которых будут:
параметры фигуры (радиус или диаметр дл€ окружности или сферы), периметр,
площадь и координаты некоторой характерной точки или точек (например, 
центра или вершин). ƒобавьте метод, определ€ющий находитс€ ли точка внутри
геометрической фигуры. ƒобавьте методы дл€ изменени€ параметров геометрических фигур,
вывода параметров на экран и Ђплотной выдачиї (функции вывода на экран заданного 
количества координат точек на контуре фигуры).*/