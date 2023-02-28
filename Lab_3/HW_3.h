#pragma once

#include <malloc.h>
#include <iostream>
#include <stdio.h> 
#include <math.h>
#include <locale.h> // ���������� ��� �������� ������� (������������ ���������)
#include <stdlib.h>
#include <string>
using namespace std;

class Matrix {
	int** m;
	int len1, len2;

public:

	Matrix(int len1, int len2) {
		this->len1 = len1;
		this->len2 = len2;
		m = (int**)malloc(sizeof(int*) * len1);
		for (int i = 0; i < len1; i++) {
			m[i] = (int*)malloc(sizeof(int) * len2);
		}
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				m[i][j] = 0;
			}
		}
	}

	void print() {
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				printf("%i\t", m[i][j]);
			}
			cout << "\n" << endl;
		}
	}

	void setItem() {
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				cout << "������� �������� [" << i << "][" << j << "] : " << endl;
				scanf_s("%i", &m[i][j]);
			}
		}
		cout << endl;
	}

	Matrix operator+ (const Matrix Mat) {
		Matrix a(len1, len2);
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				a.m[i][j] = m[i][j] + Mat.m[i][j];
			}
		}
		return a;
	}

	Matrix operator- (const Matrix Mat) {
		Matrix a(len1, len2);
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				a.m[i][j] = m[i][j] - Mat.m[i][j];
			}
		}
		return a;
	}

	Matrix operator* (const Matrix Mat) {
		Matrix a(len1, len2);
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				for (int k = 0; k < len2; k++) {
					a.m[i][j] += m[i][k] * Mat.m[k][j];
				}
			}
		}
		return a;
	}
};

void HW_3() {
	setlocale(LC_ALL, "Rus");

	Matrix a(2, 2);
	Matrix b(2, 2);
	Matrix c(2, 2);

	printf("������� 1: \n\n");
	a.setItem();
	a.print();
	printf("������� 2: \n\n");
	b.setItem();
	b.print();

	printf("�����:\n\n");
	c = a + b;
	c.print();
	cout << "---------------\n" << endl;
	printf("��������:\n\n");
	c = a - b;
	c.print();
	cout << "---------------\n" << endl;
	printf("������������:\n\n");
	c = a * b;
	c.print();


}


/*
�������� ����� Matrix, ������� �������� ����� ���� ������������������� � ���������� ��� �� �����. 
��� �������� ������� ����������� ������������ ������, ���������� (�����������) 
��� �������� ����� ������ �������� ��������, ��������� � ��������� � ��������� ������� ������ �� ������.
*/ 