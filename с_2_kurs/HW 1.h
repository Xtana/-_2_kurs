#pragma once
#include <stdio.h> 
#include <math.h>
#include <locale.h> // ���������� ��� �������� ������� (������������ ���������)
#include <stdlib.h>

class Noumber {
private:
	int x;
	int y;

public:

	int GetX() {
		return x;
	}

	void SetX(int valueX) {
		x = valueX;
	}

	int GetY() {
		return y;
	}

	void SetY(int valueY) {
		y = valueY;
	}

	int Sum() {
		int s;
		s = x + y;
		return s;
	}

	int Compairs() {
		if (x > y)
			return x;
		else
			return y;
	}
};

int HW_1() {

	Noumber a;
	a.SetY(13);
	a.SetX(26);
	printf("X = %i\nY = %i\n",a.GetX(),a.GetY());
	printf("X + Y = %i\n", a.Sum());
	printf("max - %i\n\n", a.Compairs());

	return 0;
}


/* �1 �������� ����� � ����� ����������� (����������). �������� ��� ���������� ��� ���������,
�������� ������� ������ �� ����� � ������� ��������� ���� ����������. �������� �������, 
������� ������� � ���������� ����� �������� ���� ����������, � �������, ������� ������� 
� ���������� ���������� �������� �� ���� ���� ����������.*/