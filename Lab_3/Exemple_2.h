#pragma once

/*

Разберите программу.

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
        cout << "Номер\t\t" << i << endl;
        cout << "Значение\t" << v << "\n" << endl;
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
    printf("\n\nСумма:\n");
    c = a + b;
    c.Get_fib();
    printf("Произведение:\n");
    c = a * b;
    c.Get_fib();
    printf("Разность:\n");
    c = a - b;
    c.Get_fib();
    printf("Деление:\n");
    c = a / b;
    c.Get_fib();

    return 0;
}

/*

+ Упражнение 2.1.
Создайте класс для вычисления чисел Фибоначчи. Каждое число фибоначи является объектом этого класса,
которое имеет атрибуты: значение и номер. Используйте функции для инициализации (вычисления) чисел
Фибоначчи как сторонние по отношению к этому классу.

+ Упражнение 2.2.
Поместите функции для вычисления чисел Фибоначчи внутрь созданного класса.

+ Упражнение 2.3.
Напишите функцию выполняющую операцию сложения двух чисел Фибоначи как операцию с
номерами чисел Фибоначи. В результате работы этой функции создаётся новый экземпляр этого класса.

+ Упражнение 2.4.
Перегрузите операции сложения, вычитания, умножения и деления для созданного класса как операции с
номерами чисел Фибоначи.

*/