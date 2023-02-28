#pragma once

/*

Разберите программу.

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
        cout << voltage << "\tВ\n";
        if (200 < voltage && voltage < 239)                         // исправить вольтаж
            return true;
        else
            return false;
    }
    bool CheckWater() {
        cout << volume_water << "\tМл\n";
        if (volume_water > 100) {
            volume_water -= 100;
            return true;
        }
        else
            cout << "\nДобавь воды\n";
        return false;
    }

    bool CheckCoffee() {
        cout << coffee_mass << "\tГр\n";
        if (coffee_mass > 20) {
            coffee_mass -= 20;
            return true;
        }
        else
            cout << "\nДобавь зерна\n";
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
        cout << namePersen << " запустил кофкмашину " << coff.nameCoffee << "\n" << endl;
        printf("Сколько стаканчиков кофе сделать: ");
        scanf_s("%i", &coff.cupDo);

        while ((coff.cups > 0) && (coff.CheckVoltage() || coff.CheckVoltage() || coff.CheckVoltage()) && coff.CheckWater() && coff.CheckCoffee()) {
            cout << "Ваш кофе готов\n";
            cout << "______________\n";
            coff.cups--;
            coff.cupDo--;
            cout << "Осталось " << coff.cups << " cup(s)\n" << endl;
            if (coff.cupDo == 0) break;
            if (coff.cups == 0) {
                cout << "\nСтаканчики закончились\n";
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

    // несколько пользователей одной кофе машины
    persen1.start(coffee1);
    persen2.start(coffee1);
    persen3.start(coffee1);
    cout << "\n\n" << endl;
    // одним пользователем нескольких кофе машин
    persen1.start(coffee2);
    persen1.start(coffee3);


    /*persen1.setCoffeeMass(coffee, rand() % 500);
    persen1.setVolumeWater(coffee, rand() % 2000);
    persen1.setCups(coffee, 3);
    persen1.start(coffee);*/

    return 0;
}


/*

+ Упражнение 1.1.
Добавьте в программу проверку достаточного колличества воды и кофе, функции CheckWater() и
CheckCoffee() аналогично CheckVoltage()
(обратите внимание, что для кофе и воды разумно вводить лишь ограничение снизу).

+ Упражнение 1.2.
Добавьте в класс скрытый атрибут cups хранящий значение количества чашек кофе для приготовления
и метод установки значения этого атрибута setCups(). Организуйте последовательное приготовление кофемашиной
заданного колличества чашек кофе. Если обнаруживается нехватка кофе или воды, процесс прерывается.
Если происходят сбои в цепи питания, то машина трижды проверяет напряжение перед тем как прерывает процесс.

+ Упражнение 1.3.
Добавьте в класс скрытые атрибуты для хранения: размера чашки кофя (мл), необходимого для её приготовления кофе (мг),
количество чашек доступных для одновременнного приготовления и конструктр для инициализации этих параметров.
Организуйте раюоту кофе машины с учётом новых атрибутов.
(помните, что конструктор это одноименный с классом метод, и при создании объекта должды передоваться параметры конструктора,
например:     CoffeeMachine coffee(100, 30, 2); )

Комментарий:
Важным механизмом ООП является процесс взаимодействия объектов разных классов между собой и с внешними функциями.
В С++ это может быть реализовано с помощью дружественных функций и классов.
Дружественные функции - это функции, которые не являются членами класса, однако имеют доступ к его закрытым членам -
переменным и функциям, которые имеют спецификатор private.

+ Упражнение 1.4.
Для определения дружественных функций используется ключевое слово friend.
Сделайте метод getCups() дружественной функцией, для этого необходимо добавить её объявление в класс:
friend void getCups(coffee &, int cups);
И вынесите описание этой функции за пределы класса

+ Упражнение 1.5.
Создадим класс пользователей кофе машины и перенесём в него функции по её настройке (какие это функции)  ???  .    // ? //
Один класс называется дружественным другому классу когда всем членам первого класса открыт доступ к закрытым членам второго класса.
Добавьте в программу описание класса Person, в котором определён конструктор, закрытый атрибут name, хранящий имя пользователя и
методы по настройке кофе машины (как это реализовать)  ???  :
При этом методы настройки должны быть или объявлены как дружественные в классе CoffeeMachine:
friend void Person::getCups(coffee &, int cups);
friend void Person::Settings(coffee &, int cups); (что это за метод)  ???
или весь класс Person должен быть объявлен в CoffeeMachine как дружественный:
friend class Person;
Выберете вариант наиболее удобный для Вас.

+ Упражнение 1.6.
Напишите программу, использующую разработанные классы для описания ситуации с несколькими пользователями одной кофе машины и
одним пользователем нескольких кофе машин.

+ Упражнение 1.7.
Перенесите функцию запуска кофе машины start() в класс Person.

*/


