#pragma once
/*

Разберите программу.

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>      

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
    if (!init) init = "";                                            // Не передали ли нам пустой указатель
    len = strlen(init);
    str = new char[len + 1];                                         // Выделение пямяти + /0
    strcpy(str, init);                                               // Копирование
}

String::~String() { delete[] str; str = NULL; }                      // Обнуление памяти

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
        char* tmp = strcpy(new char[strlen(str_new.str) + 1], str_new.str);  // Тоже самое, но используем вспомогательную переменную
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

    printf("Создаем объект c базывым значением 'str22':\n");
    printf("%s\n", string2.Get_str());
    printf("Длинна: %i\n\n", string2.Get_len());

    string2 = "Hi";

    printf("Приравнивем этому оъекту новое значение 'Hi':\n");
    printf("%s\n", string2.Get_str());
    printf("Длинна: %i\n\n", string2.Get_len());

    string2 = "str222222";

    printf("Приравнивем этому оъекту новое значение 'str222222':\n");
    printf("%s\n", string2.Get_str());
    printf("Длинна: %i\n\n", string2.Get_len());

    string2 = string1;

    printf("Приравнивем этому оъекту другой объект 'str1':\n");
    printf("%s\n", string2.Get_str());
    printf("Длинна: %i\n", string2.Get_len());


    return 0;
}


/*

Упражнение 1.
+ 1.1. Добавьте в описание класса переменную хранящую длинну строки, и организуйте перевыделение памяти только в том случае,
     если нехватает места для новой строки.
+ 1.2. Добавьте метод для присвоения значения одной строке значение другой:
     String &operator =( const String &that );
+ 1.3. Добавьте методы для вывода на экран строки и метод для сравнения строк.
+ 1.4. Проиллюстрируйте внесённые изменения примерами.

*/