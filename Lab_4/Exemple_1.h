#pragma once

/*

��������� ���������.

*/

#include <iostream>
#include <ctime>
#include <string>

using std::string;
using std::rand;
using std::cout;
using std::endl;

class Persen;
class CoffeeMachine;

class CoffeeMachine {

    friend Persen;

    string nameCoffee;
    int cups, coffee_mass, volume_water, cupDo = 0;

    bool CheckVoltage() {
        int voltage = 200 + rand() % 40;
        cout << voltage << "\t�\n";
        if (200 < voltage && voltage < 239)                         // ��������� �������
            return true;
        else
            return false;
    }
    bool CheckWater() {
        cout << volume_water << "\t��\n";
        if (volume_water > 100) {
            volume_water -= 100;
            return true;
        }
        else
            cout << "\n������ ����\n";
        return false;
    }

    bool CheckCoffee() {
        cout << coffee_mass << "\t��\n";
        if (coffee_mass > 20) {
            coffee_mass -= 20;
            return true;
        }
        else
            cout << "\n������ �����\n";
        return false;
    }

public:

    CoffeeMachine(string nameCoffee, int volume_water, int coffee_mass, int cups) {
        this->nameCoffee = nameCoffee;
        this->volume_water = volume_water;
        this->coffee_mass = coffee_mass;
        this->cups = cups;
    }

    CoffeeMachine(string nameCoffee) {
        this->volume_water = 0;
        this->coffee_mass = 0;
        this->cups = 0;
    }
};

class Persen {

    string namePersen;

public:

    Persen(CoffeeMachine& coff, string namePersen) {
        this->namePersen = namePersen;
    }

    void setCoffeeMass(CoffeeMachine& coff, int coffee_mass) {
        coff.coffee_mass = coffee_mass;
    }

    void setVolumeWater(CoffeeMachine& coff, int volume_water) {
        coff.volume_water = volume_water;
    }

    void setCups(CoffeeMachine& coff, int cups) {
        coff.cups = cups;
    }

    void start(CoffeeMachine& coff) {
        cout << namePersen << " �������� ���������� " << coff.nameCoffee << "\n" << endl;
        printf("������� ����������� ���� �������: ");
        scanf_s("%i", &coff.cupDo);

        while ((coff.cups > 0) && (coff.CheckVoltage() || coff.CheckVoltage() || coff.CheckVoltage()) && coff.CheckWater() && coff.CheckCoffee()) {
            cout << "��� ���� �����\n";
            cout << "______________\n";
            coff.cups--;
            coff.cupDo--;
            cout << "�������� " << coff.cups << " cup(s)\n" << endl;
            if (coff.cupDo == 0) break;
            if (coff.cups == 0) {
                cout << "\n���������� �����������\n";
                break;
            }
        }
    }

};

int Exemple_1()
{
    setlocale(LC_ALL, "Rus");

    srand(time(0));

    //CoffeeMachine coffee("coff");
    CoffeeMachine coffee1("coff1", 1000, 500, 4);
    CoffeeMachine coffee2("coff2", 1000, 500, 2);
    CoffeeMachine coffee3("coff3", 1000, 500, 2);

    Persen persen1(coffee1, "Roma");
    Persen persen2(coffee1, "Max");
    Persen persen3(coffee1, "John");

    // ��������� ������������� ����� ���� ������
    persen1.start(coffee1);
    persen2.start(coffee1);
    persen3.start(coffee1);
    cout << "\n\n" << endl;
    // ����� ������������� ���������� ���� �����
    persen1.start(coffee2);
    persen1.start(coffee3);


    /*persen1.setCoffeeMass(coffee, rand() % 500);
    persen1.setVolumeWater(coffee, rand() % 2000);
    persen1.setCups(coffee, 3);
    persen1.start(coffee);*/

    return 0;
}


/*

+ ���������� 1.1.
�������� � ��������� �������� ������������ ����������� ���� � ����, ������� CheckWater() �
CheckCoffee() ���������� CheckVoltage()
(�������� ��������, ��� ��� ���� � ���� ������� ������� ���� ����������� �����).

+ ���������� 1.2.
�������� � ����� ������� ������� cups �������� �������� ���������� ����� ���� ��� �������������
� ����� ��������� �������� ����� �������� setCups(). ����������� ���������������� ������������� �����������
��������� ����������� ����� ����. ���� �������������� �������� ���� ��� ����, ������� �����������.
���� ���������� ���� � ���� �������, �� ������ ������ ��������� ���������� ����� ��� ��� ��������� �������.

+ ���������� 1.3.
�������� � ����� ������� �������� ��� ��������: ������� ����� ���� (��), ������������ ��� � ������������� ���� (��),
���������� ����� ��������� ��� ��������������� ������������� � ���������� ��� ������������� ���� ����������.
����������� ������ ���� ������ � ������ ����� ���������.
(�������, ��� ����������� ��� ����������� � ������� �����, � ��� �������� ������� ������ ������������ ��������� ������������,
��������:     CoffeeMachine coffee(100, 30, 2); )

�����������:
������ ���������� ��� �������� ������� �������������� �������� ������ ������� ����� ����� � � �������� ���������.
� �++ ��� ����� ���� ����������� � ������� ������������� ������� � �������.
������������� ������� - ��� �������, ������� �� �������� ������� ������, ������ ����� ������ � ��� �������� ������ -
���������� � ��������, ������� ����� ������������ private.

+ ���������� 1.4.
��� ����������� ������������� ������� ������������ �������� ����� friend.
�������� ����� getCups() ������������� ��������, ��� ����� ���������� �������� � ���������� � �����:
friend void getCups(coffee &, int cups);
� �������� �������� ���� ������� �� ������� ������

+ ���������� 1.5.
�������� ����� ������������� ���� ������ � �������� � ���� ������� �� � ��������� (����� ��� �������)  ???  .    // ? //
���� ����� ���������� ������������� ������� ������ ����� ���� ������ ������� ������ ������ ������ � �������� ������ ������� ������.
�������� � ��������� �������� ������ Person, � ������� �������� �����������, �������� ������� name, �������� ��� ������������ �
������ �� ��������� ���� ������ (��� ��� �����������)  ???  :
��� ���� ������ ��������� ������ ���� ��� ��������� ��� ������������� � ������ CoffeeMachine:
friend void Person::getCups(coffee &, int cups);
friend void Person::Settings(coffee &, int cups); (��� ��� �� �����)  ???
��� ���� ����� Person ������ ���� �������� � CoffeeMachine ��� �������������:
friend class Person;
�������� ������� �������� ������� ��� ���.

+ ���������� 1.6.
�������� ���������, ������������ ������������� ������ ��� �������� �������� � ����������� �������������� ����� ���� ������ �
����� ������������� ���������� ���� �����.

+ ���������� 1.7.
���������� ������� ������� ���� ������ start() � ����� Person.

*/


