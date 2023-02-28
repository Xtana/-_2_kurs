//#include <malloc.h>
//#include <iostream>
//#include <stdio.h> 
//#include <math.h>
//#include <locale.h> // Библиотека для указания локации (региональной кодировки)
//#include <stdlib.h>
//#include <string>
//using namespace std;
//
//class Matrix {
//	friend class Vector1;
//	friend class Vector2;
//	friend ostream& operator<< (ostream& os, const Matrix& M);
//
//protected:
//
//	int** m;
//	int len1=2, len2=2;
//	int x, y, z;
//	
//public:
//
//	Matrix() {
//		m = (int**)malloc(sizeof(int*) * len1);
//		for (int i = 0; i < len1; i++) {
//			m[i] = (int*)malloc(sizeof(int) * len2);
//		}
//		for (int i = 0; i < len1; i++) {
//			for (int j = 0; j < len2; j++) {
//				m[i][j] = 0;
//			}
//		}
//	}
//
//	Matrix(int len1, int len2) {
//		this->len1 = len1;
//		this->len2 = len2;
//		m = (int**)malloc(sizeof(int*) * len1);
//		for (int i = 0; i < len1; i++) {
//			m[i] = (int*)malloc(sizeof(int) * len2);
//		}
//		for (int i = 0; i < len1; i++) {
//			for (int j = 0; j < len2; j++) {
//				m[i][j] = 0;
//			}
//		}
//	}
//
//	void setItem() {
//		for (int i = 0; i < len1; i++) {
//			for (int j = 0; j < len2; j++) {
//				cout << "Введите значение [" << i << "][" << j << "] : " << endl;
//				scanf_s("%i", &m[i][j]);
//			}
//		}
//		cout << endl;
//	}
//
//	virtual Matrix& operator+ (const Matrix Mat) {
//		Matrix a(len1, len2);
//		for (int i = 0; i < len1; i++) {
//			for (int j = 0; j < len2; j++) {
//				a.m[i][j] = m[i][j] + Mat.m[i][j];
//			}
//		}
//		return a;
//	}
//
//	virtual Matrix& operator- (const Matrix Mat) {
//		Matrix a(len1, len2);
//		for (int i = 0; i < len1; i++) {
//			for (int j = 0; j < len2; j++) {
//				a.m[i][j] = m[i][j] - Mat.m[i][j];
//			}
//		}
//		return a;
//	}
//
//	virtual Matrix& operator* (const Matrix Mat) {
//		Matrix a(len1, len2);
//		for (int i = 0; i < len1; i++) {
//			for (int j = 0; j < len2; j++) {
//				for (int k = 0; k < len2; k++) {
//					a.m[i][j] += m[i][k] * Mat.m[k][j];
//				}
//			}
//		}
//		return a;
//	}
//};
//
//class Vector1 : public Matrix {
//
//	friend ostream& operator<< (ostream& os, const Vector1& V);
//
//public:
//
//	Vector1() {
//		this->x = 0;
//		this->y = 0;
//		this->z = 0;
//	}
//
//	Vector1(int x , int y, int z) {
//		this->x = x;
//		this->y = y;
//		this->z = z;
//	}
//
//	Vector1& operator+ (const Matrix Vec) override {
//		Vector1 vec;
//		vec.x = x + Vec.x;
//		vec.y = y + Vec.y;
//		vec.z = z + Vec.z;
//		return vec;
//	}
//
//	Vector1& operator- (const Matrix Vec) override {
//		Vector1 vec;
//		vec.x = x - Vec.x;
//		vec.y = y - Vec.y;
//		vec.z = z - Vec.z;
//		return vec;
//	}
//
//	Vector1& operator* (const Matrix Vec) override {
//		Vector1 vec;
//		vec.x = x * Vec.x;
//		vec.y = y * Vec.y;
//		vec.z = z * Vec.z;
//		return vec;
//	}
//};
//
//class Vector2 :public Vector1 {
//
//
//public:
//	Vector2() {
//		this->x = 0;
//		this->y = 0;
//		this->z = 0;
//	}
//
//	Vector2(int x, int y, int z) {
//		this->x = x;
//		this->y = y;
//		this->z = z;
//	}
//
//	double len() {
//		return sqrt((x * x) + (y * y) + (z * z));
//	}
//
//	double cos(const Matrix self1, const Matrix self2) {
//		return (self1.x * self2.x + self1.y * self2.y + self1.z * self2.z) / (sqrt(self1.x * self1.x + self1.y * self1.y + self1.z * self1.z) * sqrt(self2.x * self2.x + self2.y * self2.y + self2.z * self2.z));
//	}
//
//};
//
//class Point : public Vector1 {
//
//public:
//	Point() {
//		x = 0;
//		y = 0;
//		z = 0;
//	}
//	Point(int x, int y, int z) {
//		this->x = x;
//		this->y = y;
//		this->z = z;
//	}
//
//	int operator[](string str) {
//		if (str == "x") return x;
//		if (str == "y") return y;
//		if (str == "z") return z;
//	}
//
//	int operator[](int a) {
//		if (a == 0) return x;
//		if (a == 1) return y;
//		if (a == 2) return z;
//	}
//};
//
//ostream& operator<< (ostream& os, const Matrix& M) {
//	string str = "";
//	for (int i = 0; i < M.len1; i++) {
//		for (int j = 0; j < M.len2; j++) {
//			str += to_string(M.m[i][j])+"\t";
//		}
//		str += "\n\n";
//	}
//	return os << str;
//}
//
//ostream& operator<< (ostream& os, const Vector1& V) {
//	return os << "( " << V.x << ", " << V.y << ", " << V.z << " )" << endl;
//}
//
//
//void HW_2() {
//	setlocale(LC_ALL, "Rus");
//
//	Matrix a(2, 2);
//	Vector1 v1(1, 2, 3);
//	Vector1 v2(3, 2, 1);
//	Vector2 v3(1, 2, 3);
//	Point p1(3, 2, 1);
//	Matrix m(2, 2);
//	Matrix M(2, 2);
//	m.setItem();
//	M = m + m;
//	cout << M;
//	cout << endl;
//	cout << "V1" << endl;
//	cout << v1;
//	cout << "V2" << endl;
//	cout << v2 << endl;
//	cout << "Разностьт" << endl;
//	cout << v2 - p1;
//	cout << "Сумма" << endl;
//	cout << v2 + p1;
//	cout << "Произведение" << endl;
//	cout << v2 * p1;
//
//}
//
//
///*
//Создайте класс Matrix, объекты которого могут быть проинициализированы с клавиатуры или из файла.
//Для хранения матрицы используйте динамический массив, обеспечьте (перегрузите)
//для объектов этого класса операции сложения, вычитания и умножения с созданием объекта такого же класса.
//*/
//
///*
//Создайте класс Matrix для работы с матрицами произвольной размерности, 
//перегрузите для этого класса операции сложения и умножения, а также операции
//\ввода и вывода в потоки >> и << соответственно. Создайте на основе этого класса, 
//класс наследник Vector, с аналогичным функционалом. Создайте на основе 
//класса Vector с помощью операции наследования следующие классы Point и Vector
//с функционалом использования аналогичным классам из задания 3 лабораторной работы 1,
//и класс Complex с функционалом использования аналогичным примеру из файла Example 2.cpp.
//*/