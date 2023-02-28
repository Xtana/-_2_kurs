#include <math.h>
#include <iostream>
#include <ctime>
#include <string>

using std::string;
using std::rand;
using std::cout;
using std::cin;
using std::endl;

template<typename T> class Prey;
template<typename T> class Predator;
template<typename T> class Arena;
template<typename T> class Personage;

template<typename T>
class Point2D {
    friend class Arena<T>;
    friend class Personage<T>;
    friend class Predator<T>;
    friend class Prey<T>;

protected:
    T x;
    T y;

public:
    // Конструктор
    Point2D(T x = 0, T y = 0) : x(x), y(y) {  }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const Point2D<T>& point) {
        out << "(" << point.x << ", " << point.y << ")";
        return out;
    }

    void setPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }

    bool operator== (Point2D<T> a) {
        if (x == a.x && y == a.y)
            return true;
        else
            return false;
    }
};
template<typename T>
class Personage {

    friend class Arena<T>;
    friend class Predator<T>;
    friend class Prey<T>;

protected:
    string name;
    Point2D <T> location;

public:

    void MoveTo(int x, int y) {
        location.setPoint(x, y);
    }

    Point2D<T>& GetXY() {
        return location;
    }

    string GetName() {
        return name;
    }
    int GetX() {
        return location.x;
    }

    virtual void AvtoMove() = 0;
};

template<typename T>
class Predator : public Personage<typename T> {
    friend class Arena<T>;

public:
    Predator(const std::string& name, const Point2D<T>& location) {
        this->name = name;
        this->location = location;
    }

    void AvtoMove() override;
};

template<typename T>
class Prey : public Personage<typename T> {
    friend class Arena<T>;

public:
    Prey(const std::string& name, const Point2D<T>& location) {
        this->name = name;
        this->location = location;
    }

    void AvtoMove() override;
};


template<typename T>
//class Arena : public Point2D<T> {
class Arena {

    int w = 0, h = 0;
    Prey<T>* prey;
    Predator<T>* predator;

public:

    Arena(Prey<T>* prey, Predator<T>* predator) {
        this->prey = prey;
        this->predator = predator;
    }

    Arena(int h, int w, Prey<T>* prey, Predator<T>* predator) {
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
        int xPrey = round(prey->location.x);
        int yPrey = round(prey->location.y);
        int xPredator = round(predator->location.x);
        int yPredator = round(predator->location.y);


        int n = w, m = h, numX = 1, numY = n;
        cout << ' ';
        for (int i = n + 2; i >= 0; i--) {
            for (int j = 0; j <= m + 1; j++) {
                if (i == prey->location.y + 1 && i == predator->location.y + 1 && j == prey->location.x + 1 && j == predator->location.x + 1) cout << "!";
                else if (i == yPrey + 1 && j == xPrey + 1) cout << "Ж";
                else if (i == yPredator + 1 && j == xPredator + 1) cout << "X";
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

template<typename T>
void Prey<T>::AvtoMove() {
    int numCells = 1;
    int diraction = 0;
    cout << "Выберете направление" << endl;
    cout << "0 - 'Вверх', 1 - 'Вверх-враво', 2 - 'Вправо', 3 - 'Вниз-вправо', 4 - 'Вниз', 5 - 'Вниз-влево', 6 - 'Влево', 7 - 'Вверх-влево'" << endl;
    cin >> diraction;
    switch (diraction) {
    case 0:
        this->location.x += numCells;
        break;
    case 1:
        this->location.x += numCells;
        this->location.y += numCells;
        break;
    case 2:
        this->location.x += numCells;
        break;
    case 3:
        this->location.x += numCells;
        this->location.y -= numCells;
        break;
    case 4:
        this->location.y -= numCells;
        break;
    case 5:
        this->location.x -= numCells;
        this->location.y -= numCells;
        break;
    case 6:
        this->location.x -= numCells;
        break;
    case 7:
        this->location.x -= numCells;
        this->location.y += numCells;
        break;
    default:
        break;
    }
}

template<typename T>
void Predator<T>::AvtoMove() {
    int numCells = 2;
    int diraction = 0;
    cout << "Выберете направление" << endl;
    cout << "0 - 'Вверх', 1 - 'Враво', 2 - 'Вниз', 3 - 'Влево'" << endl;
    cin >> diraction;
    switch (diraction) {
    case 0:
        this->location.y += numCells;
        break;
    case 1:
        this->location.x += numCells;
        break;
    case 2:
        this->location.y -= numCells;
        break;
    case 3:
        this->location.x -= numCells;
        break;
    default:
        break;
    }
}

int HW_1()
{
    setlocale(LC_ALL, "Rus");

    std::cout << "Enter a name for your prey: ";
    std::string name;
    std::cin >> name;
    Prey<float> prey(name, Point2D<float>(3.4, 7.12));

    std::cout << "Enter a name for your predator: ";
    std::cin >> name;
    Predator<float> predator(name, Point2D<float>(5.6, 6));

    Arena<float> arena(9, 9, &prey, &predator);

    cout << "Prey " << prey.GetXY() << endl;
    cout << "Predator " << predator.GetXY()<< "\n" << endl;
    arena.printArena();

    while (1) {

        cout <<"Prey "<< prey.GetXY() << endl;
        cout << "Predator " << predator.GetXY() << "\n" << endl;
        std::cout << predator.GetName() << " (Х)" << endl;
        predator.AvtoMove();
        arena.printArena();
        if (arena.ChekPos()) return 0;

        cout << "Prey " << prey.GetXY() << endl;
        cout << "Predator " << predator.GetXY() << "\n" << endl;
        std::cout << prey.GetName() << " (Ж)" << endl;
        prey.AvtoMove();
        arena.printArena();
        if (arena.ChekPos()) return 0;
    }

    return 0;
}

/*
Доработайте программу из предыдущей лабораторной. Создайте шаблон Point2D для работы с
координатами персонажей разных типов. Сделайте версию реализации программы для работы с
координатами как с числами float или double.
*/
