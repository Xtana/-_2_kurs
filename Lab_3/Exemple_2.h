#pragma once

/*

��������� ���������.

*/

#include "Exemple_1.h"
#include "Exemple_2.h"


class Fib {

    int i, v;

public:

    Fib() {
        this->i = 0;
        v = FFFib(this->i);
    }

    Fib(int i) {
        this->i = i;
        v = FFFib(this->i);
    }

    void Get_fib() {
        cout << "�����\t\t" << i << endl;
        cout << "��������\t" << v << "\n" << endl;
    }

    Fib sumFib(Fib& i) {
        Fib a(this->i + i.i);
        return a;
    }

    int FFFib(int i);

    Fib& operator+ (Fib& i);
    Fib& operator- (Fib& i);
    Fib& operator* (Fib& i);
    Fib& operator/ (Fib& i);
};

int Fib::FFFib(int i) {
    if (i < 1) return 0;
    if (i == 1) return 1;
    return FFFib(i - 1) + FFFib(i - 2);
}

Fib& Fib::operator+ (Fib& i) {
    Fib a(this->i + i.i);
    return a;
}

Fib& Fib::operator- (Fib& i) {
    Fib a(this->i - i.i);
    return a;
}

Fib& Fib::operator* (Fib& i) {
    Fib a(this->i * i.i);
    return a;
}

Fib& Fib::operator/ (Fib& i) {
    Fib a(this->i / i.i);
    return a;
}


int Exemple_2() {

    setlocale(LC_ALL, "Rus");


    Fib a(8);
    Fib b(2);
    Fib c;

    a.sumFib(b).Get_fib();
    printf("\n\n�����:\n");
    c = a + b;
    c.Get_fib();
    printf("������������:\n");
    c = a * b;
    c.Get_fib();
    printf("��������:\n");
    c = a - b;
    c.Get_fib();
    printf("�������:\n");
    c = a / b;
    c.Get_fib();

    return 0;
}

/*

+ ���������� 2.1.
�������� ����� ��� ���������� ����� ���������. ������ ����� �������� �������� �������� ����� ������,
������� ����� ��������: �������� � �����. ����������� ������� ��� ������������� (����������) �����
��������� ��� ��������� �� ��������� � ����� ������.

+ ���������� 2.2.
��������� ������� ��� ���������� ����� ��������� ������ ���������� ������.

+ ���������� 2.3.
�������� ������� ����������� �������� �������� ���� ����� �������� ��� �������� �
�������� ����� ��������. � ���������� ������ ���� ������� �������� ����� ��������� ����� ������.

+ ���������� 2.4.
����������� �������� ��������, ���������, ��������� � ������� ��� ���������� ������ ��� �������� �
�������� ����� ��������.

*/