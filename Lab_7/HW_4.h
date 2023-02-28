#include <malloc.h>
#include <iostream>
#include <stdio.h> 
#include <math.h>
#include <locale.h> // Библиотека для указания локации (региональной кодировки)
#include <stdlib.h>
#include <string>
#include <ctime>
using namespace std;

class Matrix {
	friend class Vector1;
	friend ostream& operator<< (ostream& os, const Matrix& M);

protected:

	int** m;
	int len1 = 1, len2 = 3;
	int x, y, z;
public:

	Matrix() {
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

	void setItem() {
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				cout << "Введите значение [" << i << "][" << j << "] : " << endl;
				scanf_s("%i", &m[i][j]);
			}
		}
		cout << endl;
	}

	virtual Matrix operator+ (const Matrix Mat) {
		Matrix a(len1, len2);
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				a.m[i][j] = m[i][j] + Mat.m[i][j];
			}
		}
		return a;
	}

	virtual Matrix operator- (const Matrix Mat) {
		Matrix a(len1, len2);
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				a.m[i][j] = m[i][j] - Mat.m[i][j];
			}
		}
		return a;
	}

	virtual Matrix operator* (const Matrix Mat) {
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

class Vector1 : public Matrix {

public:

	Vector1() {
		x = 0, y = 0, z = 0;
		len1 = 1;
		len2 = 3;
		m[0][0] = 0;
		m[0][1] = 0;
		m[0][2] = 0;
	}

	Vector1(int x, int y, int z) {
		len1 = 1;
		len2 = 3;
		this->x = x;
		this->y = y;
		this->z = z;
		m[0][0] = x;
		m[0][1] = y;
		m[0][2] = z;
	}

	double skory(const Vector1 self1) {
		double l1 = 0, l2 = 0, cos = 0;

		l1 = sqrt((self1.x * self1.x) + (self1.y * self1.y) + (self1.z * self1.z));
		l2 = sqrt((x * x) + (y * y) + (z * z));
		cos = (self1.x * x + self1.y * y + self1.z * z) / (sqrt(self1.x * self1.x + self1.y * self1.y + self1.z * self1.z) * sqrt(x * x + y * y + z * z));
		return l1 * l2 * cos;
	}

	Matrix operator* (const Matrix Mat) override {
		Matrix a(len1, len2);
		a.m[0][0] = m[0][1] * Mat.m[0][2] - m[0][2] * Mat.m[0][1];
		a.m[0][1] = m[0][2] * Mat.m[0][0] - m[0][0] * Mat.m[0][2];
		a.m[0][2] = m[0][0] * Mat.m[0][1] - m[0][1] * Mat.m[0][0];
		return a;
	}
};

ostream& operator<< (ostream& os, const Matrix& M) {
	string str = "";
	for (int i = 0; i < M.len1; i++) {
		for (int j = 0; j < M.len2; j++) {
			str += to_string(M.m[i][j]) + "\t";
		}
		str += "\n\n";
	}
	return os << str;
}

int HW_4() {
	/*Matrix m1(2, 2);
	m1.setItem();
	Matrix m2(2, 2);
	m2.setItem();*/
	Vector1 v1(1, 2, 3);
	Vector1 v2(1, 2, 3);
	
	cout << "+" << endl;
	cout << v1 + v2;
	cout << "-" << endl;
	cout << v1 - v2;
	cout << "*" << endl;
	cout << v1 * v2;

	return 0;
}