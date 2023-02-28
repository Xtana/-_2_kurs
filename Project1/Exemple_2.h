/*

��������� ���������.

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
    assert((top > 0) && "���� ������");
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

    printf("��������� � ���� '1' ��������:\n");
    s1.push(1);
    s1.push(0);
    s1.push(3);
    s1.push(2);
    s1.push(2);
    s1.print();

    printf("��������� � ���� '2' ��������:\n");
    s2.push(8);
    s2.push(9);
    s2.push(1);
    s2.push(0);
    s2.push(9);
    s2.push(9);
    s2.print();


    printf("��������� � ���� '3' ��������:\n");
    s3.push(6);
    s3.push(6);
    s3.push(6);
    s3.print();

    printf("������� �������� �� ����� '3':\n");
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

���������� 1.

�������� ����� Stack, ����������� ���������� �����. ����� Stack ������ �����:
- �������� ������������� (������������) ������ �������� ������, ��� ������ ���������� ��� �������� �����;
- �������� ������������� �������� ��� ������������ ����� ����� (�������� ������� �������);
- �������� ����� push(), ������� ����� ��������� �������� � ����
  (����� push() ������ ���������� �������� false, ���� ������ ��� ��������, � ��������� ������ � true);
- �������� ����� pop() ��� �������� �������� �� �����
  (���� � ����� ��� ��������, �� ������� ������������������ ������ � ������� ������� assert - https://en.cppreference.com/w/cpp/error/assert)
  (���������� ����� ������������ ������� ��������� ���� ������);
- �������� ����� � ������ print() ��� ������ �������� �����.

���������������� ������ ��������� ������ ��������� ������ � ������� ����������� � ����.


*/