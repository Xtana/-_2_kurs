#pragma once
#include <stdio.h> 
#include <math.h>
#include <locale.h> // ���������� ��� �������� ������� (������������ ���������)
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;


class Calenadr {
	int d, m, y;
	std::string str;

public:

	Calenadr(int d, int m, int y, std::string str) {
		this->d = d;
		this->m = m;
		this->y = y;
		this->str = str;
	}

	void setD(int d) {
		this->d = d;
	}

	void setM(int m) {
		this->m = m;
	}

	void setY(int y) {
		this->y = y;
	}

	void setStr(std::string wer) {
		str = wer;
	}

	int getD() {
		return d;
	}

	int getM() {
		return m;
	}

	int getY() {
		return y;
	}

	std::string getStr() {
		return str;
	}
};

void Exemple_5() {
	setlocale(LC_ALL, "Rus");

	Calenadr a(5, 2, 2022, "Laba 1 in Computer Science and Programming");
	Calenadr b(6, 2, 2022, "Laba 2 in Computer Science and Programming");
	Calenadr c(7, 2, 2022, "Laba 3 in Computer Science and Programming");
	Calenadr d(8, 2, 2022, "Laba 4 in Computer Science and Programming");
	Calenadr e(9, 2, 2022, "Laba 5 in Computer Science and Programming");
	Calenadr f(10, 2, 2022, "Laba 6 in Computer Science and Programming");
	Calenadr g(11, 2, 2022, "Laba 7 in Computer Science and Programming\n");

	//Calenadr list[7]{a, b, c, d, e, f, g};

	Calenadr list[7] = { a, b, c, d, e, f, g };

	for (int i = 0; i <= 6; i++) {
		cout << list[i].getD() << " / " << list[i].getM() << " / " << list[i].getY() << " - " << list[i].getStr() << endl;
	}

	a.setStr("complet");
	b.setStr("complet");
	c.setStr("complet");
	d.setStr("complet");
	e.setStr("complet");

	Calenadr list_1[7] = { a, b, c, d, e, f, g };


	for (int i = 0; i <= 6; i++) {
		cout << list_1[i].getD() << " / " << list_1[i].getM() << " / " << list_1[i].getY() << " - " << list_1[i].getStr() << endl;
	}
}


/*���������� 5.
�������� ����� Calendar, ��������� �� ����(������� �� 3 int: ����, �����, ���) � ����� �� ����(������ std::string).��� ��������
������ ���� private, ������ � ��� ���������� ����������� ����� ������� set � get.�������� ��������� ���������� ������ �� 7 ��������
Calendar � ��������� �� ������� �� ������.�������� ���� �� ������ � ������� :

10 / 02 / 2022 - Laba 1 in Computer Science and Programming

������ ������ �� std::string : (https ://en.cppreference.com/w/cpp/string)

#include <string>

	std::string str = "hello";

*/