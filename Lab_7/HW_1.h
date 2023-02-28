#include <stdio.h> 
#include <math.h>
#include <locale.h> // Библиотека для указания локации (региональной кодировки)
#include <stdlib.h>
using namespace std;

class Shapes {
protected:
	double p = 0, s = 0;

public:
	virtual void area() = 0;
	virtual void perimeter() = 0;
	virtual bool in(double x, double y) = 0;

};

class Circle : public Shapes {

	friend ostream& operator << (ostream& os, const Circle& cir);

private:
	const double pi = 3.14;
	double xO, yO;
	double r;

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

	void area() override {
		s = pi * r * r;
	}

	void perimeter() override {
		p = 2 * pi * r;
	}

	bool in(double x, double y) override {
		if (x * x + y * y <= r * r)
			return true;
		else
			return false;
	}
};

class Rectangle : public Shapes {
	friend ostream& operator<< (ostream& os, const Rectangle& cir);

private:
	double x1, y1, x2, y2, x3, y3, x4, y4;
	double a = 0, b = 0;

public:

	Rectangle() {
		x1 = 0; x2 = 0; x3 = 0; x4 = 0;
		y1 = 0; y2 = 0; y3 = 0; y4 = 0;
	}

	Rectangle(double X1, double Y1, double X2, double Y2, double X3, double Y3, double X4, double Y4) {
		x1 = X1; x2 = X2; x3 = X3; x4 = X4;
		y1 = Y1; y2 = Y2; y3 = Y3; y4 = Y4;
		a = sqrt((x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4));
		b = sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
	}

	void area() override {
		s = a * b;
	}

	void perimeter() override {
		p = 2 * a * b;
	}

	bool in(double x, double y) override {
		if (x >= x1 && x <= x2 && y >= y3 && y <= y2)
			return true;
		else
			return false;
	}
};

class Triangle : public Shapes {
	friend ostream& operator<< (ostream& os, const Triangle& cir);

private:
	double x1, y1, x2, y2, x3, y3;
	double a = 0, b = 0, c = 0;
public:

	Triangle() {
		x1 = 0; x2 = 0; x3 = 0;
		y1 = 0; y2 = 0; y3 = 0;
	}

	Triangle(double X1, double Y1, double X2, double Y2, double X3, double Y3) {
		x1 = X1; x2 = X2; x3 = X3;
		y1 = Y1; y2 = Y2; y3 = Y3;
		a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
		c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	}

	void perimeter() override {
		p = (a + b + c);
	}

	void area() override {
		s = sqrt(p/2 * (p/2 - a) * (p/2 - b) * (p/2 - c));
	}

	 bool in(double x, double y) override {
		double q = (x1 - x) * (y2 - y1) - (x2 - x1) * (y1 - y);
		double w = (x2 - x) * (y3 - y2) - (x3 - x2) * (y2 - y);
		double e = (x3 - x) * (y1 - y3) - (x1 - x3) * (y3 - y);
		if ((q < 0 && w < 0 && e < 0) || (q >= 0 && w >= 0 && e >= 0))
			return true;
		else
			return false;
	}
};

ostream& operator<< (ostream& os, const Circle& cir) {
	os << "X0 - " << cir.xO << "\tY0 - " << cir.xO <<"\t R - "<< cir.r
	   << "\nP - "<< cir.p << "\tS - "<< cir.s;
	return os;
}

ostream& operator<< (ostream& os, const Rectangle& rec) {
	os << "X1Y1 - (" << rec.x1 << "," << rec.y1 << ")" << "\tX2Y2 - (" << rec.x2 << "," << rec.y2 << ")\n"
	   << "X4Y4 - (" << rec.x4 << "," << rec.y4 << ")" << "\tX3Y3 - (" << rec.x3 << "," << rec.y3 << ")\n"
		<< "P - " << rec.p << "\tS - " << rec.s;
	return os;
}

ostream& operator<< (ostream& os, const Triangle& trig) {
	os << "X1Y1 - (" << trig.x1 << "," << trig.y1 << ")\tX2Y2 - (" << trig.x2 << ", " << trig.y2 << ")" << "\tX3Y3 - (" << trig.x3 << ", " << trig.y3 << ")\n"
		<< "P - " << trig.p << "\tS - " << trig.s;
	return os;
}


int HW_1() {

	setlocale(LC_ALL, "Rus");

	Circle A(1, 1, 5);
	Rectangle B(-1, 1, 1, 1, 1, -1, -1, -1);
	Triangle C(-1, 1, 1, 1, 1, -1);
	A.area();
	A.perimeter();
	B.area();
	B.perimeter();
	C.perimeter();
	C.area();

	printf("ОКРУЖНОТЬ\n");
	cout << A << endl;
	printf("Точко лежмт внутри окружности: %d\n\n", A.in(1, 2));

	printf("ПРЯМОУГОЛЬНИК\n");
	cout << B << endl;
	printf("Точко лежмт внутри прямоугольника: %d\n\n", B.in(0, 1));

	printf("ТРЕУГОЛЬНИК\n");
	cout << C << endl;
	printf("Точко лежмт внутри треугольника: %d\n\n", C.in(0, 0.9));

	return 0;
}
