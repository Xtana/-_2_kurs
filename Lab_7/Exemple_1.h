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

class Personag {

protected:
    std::string name;
    Point2D location;

public:

    virtual void MoveTo(int x, int y) {
        location.setPoint(x, y);
    }

    virtual Point2D& GetXY() {
        return location;
    }

    virtual string GetName() {
        return name;
    }

    virtual void AvtoMove() = 0;
};

class Predator : public Personag {
    friend class Arena;

public:
    Predator(const std::string& name, const Point2D& location) {
        this->name = name;
        this->location = location;
    }

    void AvtoMove() override;
};

class Prey : public Personag {
    friend class Arena;

public:
    Prey(const std::string& name, const Point2D& location) {
        this->name = name;
        this->location = location;
    }

    void AvtoMove() override;
};

class Arena {

    int w = 0, h = 0;
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
                if (i == prey->location.y + 1 && i == predator->location.y + 1 && j == prey->location.x + 1 && j == predator->location.x + 1) cout << "!";
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

void Prey::AvtoMove() {
    int numCells = 1;
    int diraction = 0;
    cout << "Выберете направление" << endl;
    cout << "0 - 'Вверх', 1 - 'Вверх-враво', 2 - 'Вправо', 3 - 'Вниз-вправо', 4 - 'Вниз', 5 - 'Вниз-влево', 6 - 'Влево', 7 - 'Вверх-влево'" << endl;
    cin >> diraction;
    switch (diraction) {
    case 0:
        location.y += numCells;
        break;
    case 1:
        location.x += numCells;
        location.y += numCells;
        break;
    case 2:
        location.x += numCells;
        break;
    case 3:
        location.x += numCells;
        location.y -= numCells;
        break;
    case 4:
        location.y -= numCells;
        break;
    case 5:
        location.x -= numCells;
        location.y -= numCells;
        break;
    case 6:
        location.x -= numCells;
        break;
    case 7:
        location.x -= numCells;
        location.y += numCells;
        break;
    default:
        break;
    }
}

void Predator::AvtoMove() {
    int numCells = 2;
    int diraction = 0;
    cout << "Выберете направление" << endl;
    cout << "0 - 'Вверх', 1 - 'Враво', 2 - 'Вниз', 3 - 'Влево'" << endl;
    cin >> diraction;
    switch (diraction) {
    case 0:
        location.y += numCells;
        break;
    case 1:
        location.x += numCells;
        break;
    case 2:
        location.y -= numCells;
        break;
    case 3:
        location.x -= numCells;
        break;
    default:
        break;
    }
}

int Exemple_1()
{
    setlocale(LC_ALL, "Rus");

    std::cout << "Enter a name for your prey: ";
    std::string name;
    std::cin >> name;
    Prey prey(name, Point2D(4, 7));

    std::cout << "Enter a name for your predator: ";
    std::cin >> name;
    Predator predator(name, Point2D(5, 6));

    Arena arena(9, 9, &prey, &predator);

    arena.printArena();

    while (1) {
        std::cout << predator.GetName() << " (Х)" << endl;
        predator.AvtoMove();
        arena.printArena();
        if (arena.ChekPos()) return 0;

        std::cout << prey.GetName() << " (Ж)" << endl;
        prey.AvtoMove();
        arena.printArena();
        if (arena.ChekPos()) return 0;
    }

    return 0;
}

/*
Доработайте программу из предыдущей лабораторной. 
Создайте класс Personage и сделайте классы Prey и Predator. 
При этом все общие функции должны быть в классе Personage виртуальными, 
а сам класс Personage – абстрактным.
*/
