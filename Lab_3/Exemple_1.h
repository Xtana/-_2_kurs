#pragma once

/*

��������� ���������.

*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Person {
public:
    int age;
    Person(string n, int a) {
        name = n; age = a;
    }
    string getName() {
        return name;
    }
    void move() {
        cout << name << " is moving" << endl;
    }
    ~Person() {
        std::cout << "Destructor called for Person " << name << std::endl;
    }
private:
    string name;
};

Person operator+ (Person& p1, Person& p2) {
    string name = p1.getName() + "&" + p2.getName();
    return Person(name, p1.age + p2.age);
}

Person operator+ (Person& p1, Person* p2) {
    string name = p1.getName() + "&" + p2->getName();
    return Person(name, p1.age + p2->age);
}



int Exemple_1() {

    setlocale(LC_ALL, "Rus");

    Person tom = Person("Tom", 22);
    Person* sam = new Person("Sam", 21);                                         // ������������ ������
    cout << "Name: " << tom.getName() << "\tAge: " << tom.age << endl;
    cout << "Name: " << sam->getName() << "\tAge: " << sam->age << endl;
    // cout << "Name: " << (*sam).getName() << "\tAge: " << (*sam).age << endl;     ���� �����

    Person tomtom = tom + tom;                                                   // 2 �����������  �������� � ������� �� ��������
    Person tomsan = tom + sam;                                                   // 1 ����������

    tom.age = 23;
    tom.move();

    cout << "Name: " << tomtom.getName() << "\tAge: " << tomtom.age << endl;
    cout << "Name: " << tomsan.getName() << "\tAge: " << tomsan.age << endl;

    delete sam;

    return 0;
}

/*

+ ���������� 1.1.
������ ������� ��� ���������� ����������?

+ ���������� 1.2.
������� ������ ������ ������� ������ � ������� operator+() � �������� �� ��������, �� �������� �� ������.


*/
