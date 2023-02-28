#pragma once
/*

��������� ���������.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>������

class String {
public:
    String(const char* init);
    ~String();

    String &operator= (const char *str);
    String &operator= (const String &str_new);

    int Get_len() {
        return len;
    }

    char* Get_str() {
        return str;
    }

private:
    int len = 0;
    char* str;
};

String::String(const char *init) {
    if (!init) init = "";                                            // �� �������� �� ��� ������ ���������
    len = strlen(init);
    str = new char[len + 1];                                         // ��������� ������ + /0
    strcpy(str, init);                                               // �����������
}

String::~String() { delete[] str; str = NULL; }                      // ��������� ������

String& String::operator= (const char* str_new) {
    if (!str_new) str_new = "";
    if (len >= strlen(str_new)) {
        strcpy(str, str_new);
    }
    else {
        char* tmp = strcpy(new char[strlen(str_new) + 1], str_new);  
        delete[] str;
        str = tmp;
        len = strlen(str);
    }
    return *this;                                                    
}

String& String::operator= (const String& str_new) {
     //if (!str_new.str) str_new.str = "";
     if (len >= strlen(str_new.str)) {
        strcpy(str, str_new.str);
    }
    else {
        char* tmp = strcpy(new char[strlen(str_new.str) + 1], str_new.str);  // ���� �����, �� ���������� ��������������� ����������
        delete[] str;
        str = tmp;
        len = strlen(str);
    }
     return *this;
}

int Exemple_1_1()
{
    setlocale(LC_ALL, "Rus");

    String string1("str1");
    String string2("str22");

    printf("������� ������ c ������� ��������� 'str22':\n");
    printf("%s\n", string2.Get_str());
    printf("������: %i\n\n", string2.Get_len());

    string2 = "Hi";

    printf("����������� ����� ������ ����� �������� 'Hi':\n");
    printf("%s\n", string2.Get_str());
    printf("������: %i\n\n", string2.Get_len());

    string2 = "str222222";

    printf("����������� ����� ������ ����� �������� 'str222222':\n");
    printf("%s\n", string2.Get_str());
    printf("������: %i\n\n", string2.Get_len());

    string2 = string1;

    printf("����������� ����� ������ ������ ������ 'str1':\n");
    printf("%s\n", string2.Get_str());
    printf("������: %i\n", string2.Get_len());


    return 0;
}


/*

���������� 1.
+ 1.1. �������� � �������� ������ ���������� �������� ������ ������, � ����������� ������������� ������ ������ � ��� ������,
     ���� ��������� ����� ��� ����� ������.
+ 1.2. �������� ����� ��� ���������� �������� ����� ������ �������� ������:
     String &operator =( const String &that );
+ 1.3. �������� ������ ��� ������ �� ����� ������ � ����� ��� ��������� �����.
+ 1.4. ���������������� �������� ��������� ���������.

*/