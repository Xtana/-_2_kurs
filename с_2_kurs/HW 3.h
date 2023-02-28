#pragma once

#include <stdio.h> 
#include <math.h>
#include <locale.h> // ���������� ��� �������� ������� (������������ ���������)
#include <stdlib.h>

class Trigonometry {

private:
	double x;

public:

	double trig_sin() {
		return sin(x);
	}

	double trig_cos() {
		return cos(x);
	}

	void SetX_6(double X) {
		x = X;
	}

	double GetX_6() {
		return x;
	}

	void Calculate() {
		float X;
		string X1;
		while (printf("��������� �������� � ��������: ") && scanf_s("%f", &X)) {
			X = 0.0174532925 * X;
			SetX_6(X);
			printf("�������� � ��������: %lf\n", X);
			printf("������������������� ������� ����� sin(x) = %.4f, cos(x) = %.4f\n\n", trig_sin(), trig_cos());
		}
	}
};


int HW_3() {

	setlocale(LC_ALL, "Rus");
	 
	Trigonometry().Calculate();

	return 0;
}

/*
�������� ����� Trigonometry ��������� �� �������� (x), ������������ � ������� ��� ���������� �������� ������������������ ������� (sin(x), cos(x)) �� ����� �����.
���������������� ������ ��������� �������� �������� ������������������ ������� �� ������������������ �������� ������������� �����,
�������� ���������� ���������� �� ����� � �������: ���������� �������� �, ������������������ ������� ����� sin(x) = �, cos(x) = ��. ����� � ��������� ������ �������� � ������� � 4 ������� ����� �������.

*/