/*

Разберите программу Хищник - Жертва.

*/

#include <iostream>
#include <ctime>
#include <string>

using std::string;
using std::rand;
using std::cout;
using std::cin;
using std::endl;

class Point2D {
    friend class Arena;
    friend class Predator;
    friend class Prey;

private:
    int x;
    int y;

public:

    // Конструктор
    Point2D(int x = 0, int y = 0) : x(x), y(y) {  }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const Point2D& point) {
        out << "(" << point.x << ", " << point.y << ")";
        return out;
    }

    void setPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }

    bool operator== (Point2D a) {
        if (x == a.x && y == a.y)
            return true;
        else
            return false;
    }

};

class Predator {

    friend class Arena;

    std::string name;
    Point2D location;

public:
    Predator(const std::string& name, const Point2D& location) : name(name), location(location) {   }

    void MoveTo(int x, int y) {
        location.setPoint(x, y);
    }

    Point2D& GetXY() {
        return location;
    }

    string GetName() {
        return name;
    }

    void AvtoMove(string personag);
};

class Prey {
    friend class Arena;

    std::string name;
    Point2D location;

public:
    Prey(const std::string& name, const Point2D& location) : name(name), location(location) {   }

    void MoveTo(int x, int y) {
        location.setPoint(x, y);
    }

    Point2D& GetXY() {
        return location;
    }

    string GetName() {
        return name;
    }

    void AvtoMove(string personag);
};

class Arena {

    int w=0, h=0;
    Prey* prey;
    Predator* predator;

public:

    Arena(Prey* prey, Predator* predator) {
        this->prey = prey;
        this->predator = predator;
    }

    Arena(int h, int w, Prey* prey, Predator* predator) {
        this->h = h;
        this->w = w;
        this->prey = prey;
        this->predator = predator;
    }

    bool ChekPos() {
        if (prey->GetXY() == predator->GetXY()) {
            cout << "\nЖертва поймана" << endl;
            return 1;
        }
        else
            return 0;
    }

    void printArena() {
        int n = w, m = h, numX = 1, numY = n;
        cout << ' ';
        for (int i = n + 2; i >= 0; i--) {
            for (int j = 0; j <= m + 1; j++) {
                if ((prey->location.x + 1 == j)&&(predator->location.x + 1 == j)&&(predator->location.y + 1 == i)&&(prey->location.y + 1 == i)) cout << "!";
                else if (i == prey->location.y + 1 && j == prey->location.x + 1) cout << "Ж";
                else if (i == predator->location.y + 1 && j == predator->location.x + 1) cout << "X";
                else if (i == 1) cout << '.';
                else if (j == 1 && i < n + 2 && i > 1) cout << '|';
                else if (i == n + 2) cout << '.';
                else if (j == 0 && i < n + 2 && i > 1) {
                    cout << numY;
                    numY--;
                }
                else if (j >= 1 && j <= m && i == 0) {
                    cout << numX;
                    numX++;
                }
                else cout << ' ';
            }
            if (i > 1 && i < n + 2)cout << "|";
            cout << "" << endl;
            if (i == 2 || i == 1) cout << ' ';
        }
    }
};

void Prey::AvtoMove(string personag) {
    int numCells = 1;
    int diraction = 0;
    if (personag == "predator") {
        diraction = rand() % 8;
    }
    else {
        cout << "Выберете направление" << endl;
        cout << "0 - 'Вверх', 1 - 'Вверх-враво', 2 - 'Вправо', 3 - 'Вниз-вправо', 4 - 'Вниз', 5 - 'Вниз-влево', 6 - 'Влево', 7 - 'Вверх-влево'" << endl;
        cin >> diraction;
    }
    switch (diraction) {
    case 0:
        if (location.y + numCells <= 9) {
            location.y += numCells;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 1:
        if ((location.y + numCells <= 9)&&(location.x + numCells <= 9)) {
            location.y += numCells;
            location.x += numCells;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 2:
        if (location.x + numCells <= 9) {
            location.x += numCells;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 3:
        if ((location.y - numCells >= 1)&&(location.x + numCells <= 9)) {
            location.x += numCells;
            location.y -= numCells;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 4:
        if (location.y - numCells >= 1) {
            location.y -= numCells;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 5:
        if ((location.y - numCells >= 1)&& (location.x - numCells >= 1)) {
            location.x -= numCells;
            location.y -= numCells;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 6:
        if (location.x - numCells >= 1) {
            location.x -= numCells;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 7:
        if ((location.y + numCells <= 9)&&(location.x - numCells >= 1)) {
            location.x -= numCells;
            location.y += numCells;
        }
        else cout << "Выход за пределы" << endl;
        break;
    default:
        break;
    }
}

void Predator::AvtoMove(string personag) {
    int numCells = 0;
    int diraction = 0;
    if (personag == "prey") {
        numCells = rand() % 5 + 1;
        diraction = rand() % 4;
    }
    else {
        numCells = 2;
        diraction = 0;
        cout << "Выберете направление" << endl;
        cout << "0 - 'Вверх', 1 - 'Враво', 2 - 'Вниз', 3 - 'Влево'" << endl;
        cin >> diraction;
        cout << "Выберете количество клеток (1-5)" << endl;
        cin >> numCells;
    }
    switch (diraction) {
    case 0:
        if (location.y + numCells <= 9) {
            location.y += numCells;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 1:
        if (location.x + numCells <= 9) {
            location.x += numCells;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 2:
        if (location.y - numCells >= 1) {
            location.y -= numCells;
        }
        else cout << "Выход за пределы" << endl;
        break;
    case 3:
        if (location.x - numCells >= 1) {
            location.x -= numCells;
        }
        else cout << "Выход за пределы" << endl;
        break;
    }
}

int Exemple_1()
{
    setlocale(LC_ALL, "Rus");

    std::cout << "Enter a name for your prey: ";
    std::string name;
    std::cin >> name;
    Prey prey(name, Point2D(1, 1));

    std::cout << "Enter a name for your predator: ";
    std::cin >> name;
    Predator predator(name, Point2D(3, 3));

    Arena arena(9, 9, &prey, &predator);

    cout << "\nЗа кого вы хотите играть? (prey/predator)\n"
         << "Если вы хотите играть с дркгом нажмите дюбой символ" << endl;
    string personag = "";
    cin >> personag;

    arena.printArena();

    while (1) {
        std::cout << predator.GetName() << " (Х)" << endl;
        predator.AvtoMove(personag);
        arena.printArena();
        if (arena.ChekPos()) return 0;

        std::cout << prey.GetName() << " (Ж)" << endl;
        prey.AvtoMove(personag);
        arena.printArena();
        if (arena.ChekPos()) return 0;
    }

    return 0;
}

/*
Так как ООП имитирует отношение объектов (феноменов) реального мира, а все реальные объекты связаны между собой,
существуют типичные связи и между объектами в ООП.
Такими типичными связями являются:
Композиция, Агрегация, Ассоциация и Зависимость

Композиции являются одними из самых простых типов отношений для реализации,
так как это обычные структуры или классы с обычными членами.

Как и в случае композиции, отношения в агрегации также являются отношениями части-целого и однонаправленные.
Однако, в отличие от композиции, части могут принадлежать более чем одному целому в моменте,
и целое не управляет существованием и продолжительностью жизни частей.

В ассоциации объекты между собой формально никак не связаны (один не является частью другого), но ассоциированные объекты
имеют доступ к функционалу друг друга.
(могут быть как однонаправленными, так и двунаправленными)

Зависимость возникает, когда один объект обращается к функционалу другого объекта для выполнения определенного задания.
(слабее ассоциации, всегда является однонаправленной).

Как думаете какие типы взаимодействий уже есть в программе?


Рассмотрим игру Хищник - Жертва (аналог игр шофёр-убийца или человек лев)

Упражнение 1.1. Композиции
Опишите класс Predator аналогично классу Prey.

Упражнение 1.2. Агрегация
Создайте класс Arena. Опишите Конструктор арены принимающий её параметры: длинну и ширину,
и находящихся на орене хищников и жертв. Все эти атрибцты должны быть приватными.
Габориты арены являются простыми параметрами.
А хищники и жертвы добавляются как указатели на объекты соответствующих классов, например:

    Prey* prey

Упражнение 1.3. Ассоциация
Добавьте в классы Predator и Prey метод AvtoMove(), отвечающий за автоматическое перемещение.
Это необходимо для имитации игры компьютера за одного из персонажей.
Для работы этого метода добавьте его в каждый из классов персонажей как дружественный по отношению к другому
и имеющий доступ к положению пративника.

Будем считать, что predator может прыгать далеко (например на 5 клеток) но только по горизонтале или вертикале, а
prey ходить на одну клетку в любом направлении. Организуйте соответствующим образом работу метода AvtoMove().
Пока можно пользоваться функцией rand()...

Упражнение 1.4. Зависимость
Мы много раз уже видели отношений в виде зависимости, это пример отношения:  классов и std::cout (типа std::ostream).

Добавьте вывод в консоль координат положения Хищьника и Жертвы, и всей арены целиком (прямоугольник с демонстрацией текущих положений),
перегрузив для каждого из них оператор operator<< ().
Добавьте в main() соответствующую строку:

std::cout << prey << '\n';

Упражнение 1.5. Игра

Добавьте в main() запрос пользователю за кого он хочет играть, и постройте соответствующим образом логику программы. Попробуйте поиграть.


*/
