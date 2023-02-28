#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class String2 {

    friend bool oper(String2 a, String2 b);

    string str;
    int len = 0;
    
public:

    String2(string init);
    ~String2();

    void print() {
        cout << str << "\n";
    }
};

String2::String2(string init) {
    str = init;
}

String2::~String2() { }

bool oper(String2 a, String2 b) {
    if (a.str == b.str) return 1;
    else return 0;
}

int Exemple_1_2()
{

    setlocale(LC_ALL, "Rus");

    String2 a("qwe");
    String2 b("qwe");
    String2 c("ret");

    printf("������ ������: ");
    a.print();
    printf("������ ������: ");
    b.print();
    printf("������ ������: ");
    c.print();
    printf("\n������ == �������: %i\n", oper(a, b));
    printf("������ == �������: %i\n", oper(c, b));

    return 0;
}

/*
���������� 2.
�������� ����� �������� ��������� �������� �������� ������������ ������ ��������� �� String (��������, Text). ���������� ���������� ���
������������, �����������, ������ ��� ������ �������� ������ �� �����. ����������� ��������� �����������.
�������� ��������� ������� (�� ���� ������) ��� ��������� ����� �������� (������ �� ��� ����������� ���� ������������� ��������?).
���������������� ������ ��������� ���������.
*/



/*
class String2 {
public:
    char* str;
    int len = 0;

    String2(const char* init);
    ~String2();

    void print() {
        printf("%s\n", str);
    }

private:

};

String2::String2(const char* init) {
    if (!init) init = "";                                            // �� �������� �� ��� ������ ���������
    len = strlen(init);
    str = new char[len + 1];                                         // ��������� ������ + /0
    strcpy(str, init);                                               // �����������
}

String2::~String2() { delete[] str; str = NULL; }

bool oper(String2 a, String2 b) {
    printf("%s %s\n", a.str, b.str);
    if (a.str == b.str) return 1;
    else return 0;
}

int Exemple_1_2()
{

    String2 a("qwertyuio");
    String2 b("123dh be;");

    a.print();
    b.print();
    printf("%i", oper(a, b));

    return 0;
}
*/