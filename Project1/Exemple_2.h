/*

Разберите программу.

*/

#include <iostream>
#include <cassert>

class Point {
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void showCoords() {
        std::cout << " Coords x: " << x << std::endl << " Coords y: " << y << std::endl;
    }
    Point& move(int x, int y) {
        this->x += x;
        this->y += y;
        return *this;
    }
private:
    int x;
    int y;
};

class Stack {
    int* arr;
    int space;
    int top;

public:
    Stack(const int init);
    ~Stack();

    int push(int n);
    int pop();
    void print();
};

Stack::Stack(const int init) {
    arr = new int[init];
    space = init;
    top = 0;
}

Stack::~Stack() {
    delete[] arr;
}

int Stack::push(int n) {
    if (top >= space)
        return 1;
    else
        top++;
    arr[top] = n;
    return 0;
}

int Stack::pop() {
    assert((top > 0) && "СТЕК ПУСТОЙ");
    int tmp = arr[top];
    top--;
    return tmp;
}

void Stack::print() {
    for (int i = 1; i <= top; i++)
        printf("%d\t", arr[i]);
    printf("\n\n");
}

int Exemple_2()
{
    setlocale(LC_ALL, "ru");

    Stack s1(5);
    Stack s2(5);
    Stack s3(5);

    printf("Добавляем в стек '1' значения:\n");
    s1.push(1);
    s1.push(0);
    s1.push(3);
    s1.push(2);
    s1.push(2);
    s1.print();

    printf("Добавляем в стек '2' значения:\n");
    s2.push(8);
    s2.push(9);
    s2.push(1);
    s2.push(0);
    s2.push(9);
    s2.push(9);
    s2.print();


    printf("Добавляем в стек '3' значения:\n");
    s3.push(6);
    s3.push(6);
    s3.push(6);
    s3.print();

    printf("Удаляем значения из стека '3':\n");
    s3.pop();
    s3.print();
    s3.pop();
    s3.print();
    s3.pop();
    s3.print();
    s3.pop();
    s3.print();



    //Point p1(20, 50);
    //p1.move(10, 5).move(10, 10);
    //p1.showCoords();



    return 0;
}

/*

Упражнение 1.

Создайте класс Stack, реализующий функционал стека. Класс Stack должен иметь:
- закрытый целочисленный (динамический) массив заданной длинны, она должна задаваться при создании стека;
- закрытое целочисленное значение для отслеживания длины стека (рабочего размера массива);
- открытый метод push(), который будет добавлять значение в стек
  (метод push() должен возвращать значение false, если массив уже заполнен, в противном случае — true);
- открытый метод pop() для возврата значений из стека
  (если в стеке нет значений, то должена инициализироваться ошибка с помощью команды assert - https://en.cppreference.com/w/cpp/error/assert)
  (предложите более рациональный вариант обработки этой ошибки);
- открытый метод с именем print() для вывода значений стека.

Проиллюстрируйте работу программы создав несколько стеков и проведя манипуляции с ними.


*/