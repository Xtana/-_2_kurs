/*

��������� ��������� ������ - ������.

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

    // �����������
    Point2D(int x = 0, int y = 0) : x(x), y(y) {  }

    // ���������� ��������� ������
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
            cout << "\n������ �������" << endl;
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
                else if (i == prey->location.y + 1 && j == prey->location.x + 1) cout << "�";
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
        cout << "�������� �����������" << endl;
        cout << "0 - '�����', 1 - '�����-�����', 2 - '������', 3 - '����-������', 4 - '����', 5 - '����-�����', 6 - '�����', 7 - '�����-�����'" << endl;
        cin >> diraction;
    }
    switch (diraction) {
    case 0:
        if (location.y + numCells <= 9) {
            location.y += numCells;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 1:
        if ((location.y + numCells <= 9)&&(location.x + numCells <= 9)) {
            location.y += numCells;
            location.x += numCells;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 2:
        if (location.x + numCells <= 9) {
            location.x += numCells;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 3:
        if ((location.y - numCells >= 1)&&(location.x + numCells <= 9)) {
            location.x += numCells;
            location.y -= numCells;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 4:
        if (location.y - numCells >= 1) {
            location.y -= numCells;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 5:
        if ((location.y - numCells >= 1)&& (location.x - numCells >= 1)) {
            location.x -= numCells;
            location.y -= numCells;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 6:
        if (location.x - numCells >= 1) {
            location.x -= numCells;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 7:
        if ((location.y + numCells <= 9)&&(location.x - numCells >= 1)) {
            location.x -= numCells;
            location.y += numCells;
        }
        else cout << "����� �� �������" << endl;
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
        cout << "�������� �����������" << endl;
        cout << "0 - '�����', 1 - '�����', 2 - '����', 3 - '�����'" << endl;
        cin >> diraction;
        cout << "�������� ���������� ������ (1-5)" << endl;
        cin >> numCells;
    }
    switch (diraction) {
    case 0:
        if (location.y + numCells <= 9) {
            location.y += numCells;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 1:
        if (location.x + numCells <= 9) {
            location.x += numCells;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 2:
        if (location.y - numCells >= 1) {
            location.y -= numCells;
        }
        else cout << "����� �� �������" << endl;
        break;
    case 3:
        if (location.x - numCells >= 1) {
            location.x -= numCells;
        }
        else cout << "����� �� �������" << endl;
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

    cout << "\n�� ���� �� ������ ������? (prey/predator)\n"
         << "���� �� ������ ������ � ������ ������� ����� ������" << endl;
    string personag = "";
    cin >> personag;

    arena.printArena();

    while (1) {
        std::cout << predator.GetName() << " (�)" << endl;
        predator.AvtoMove(personag);
        arena.printArena();
        if (arena.ChekPos()) return 0;

        std::cout << prey.GetName() << " (�)" << endl;
        prey.AvtoMove(personag);
        arena.printArena();
        if (arena.ChekPos()) return 0;
    }

    return 0;
}

/*
��� ��� ��� ��������� ��������� �������� (���������) ��������� ����, � ��� �������� ������� ������� ����� �����,
���������� �������� ����� � ����� ��������� � ���.
������ ��������� ������� ��������:
����������, ���������, ���������� � �����������

���������� �������� ������ �� ����� ������� ����� ��������� ��� ����������,
��� ��� ��� ������� ��������� ��� ������ � �������� �������.

��� � � ������ ����������, ��������� � ��������� ����� �������� ����������� �����-������ � ����������������.
������, � ������� �� ����������, ����� ����� ������������ ����� ��� ������ ������ � �������,
� ����� �� ��������� �������������� � ������������������ ����� ������.

� ���������� ������� ����� ����� ��������� ����� �� ������� (���� �� �������� ������ �������), �� ��������������� �������
����� ������ � ����������� ���� �����.
(����� ���� ��� �����������������, ��� � ����������������)

����������� ���������, ����� ���� ������ ���������� � ����������� ������� ������� ��� ���������� ������������� �������.
(������ ����������, ������ �������� ����������������).

��� ������� ����� ���� �������������� ��� ���� � ���������?


���������� ���� ������ - ������ (������ ��� �����-������ ��� ������� ���)

���������� 1.1. ����������
������� ����� Predator ���������� ������ Prey.

���������� 1.2. ���������
�������� ����� Arena. ������� ����������� ����� ����������� � ���������: ������ � ������,
� ����������� �� ����� �������� � �����. ��� ��� �������� ������ ���� ����������.
�������� ����� �������� �������� �����������.
� ������� � ������ ����������� ��� ��������� �� ������� ��������������� �������, ��������:

    Prey* prey

���������� 1.3. ����������
�������� � ������ Predator � Prey ����� AvtoMove(), ���������� �� �������������� �����������.
��� ���������� ��� �������� ���� ���������� �� ������ �� ����������.
��� ������ ����� ������ �������� ��� � ������ �� ������� ���������� ��� ������������� �� ��������� � �������
� ������� ������ � ��������� ����������.

����� �������, ��� predator ����� ������� ������ (�������� �� 5 ������) �� ������ �� ����������� ��� ���������, �
prey ������ �� ���� ������ � ����� �����������. ����������� ��������������� ������� ������ ������ AvtoMove().
���� ����� ������������ �������� rand()...

���������� 1.4. �����������
�� ����� ��� ��� ������ ��������� � ���� �����������, ��� ������ ���������:  ������� � std::cout (���� std::ostream).

�������� ����� � ������� ��������� ��������� �������� � ������, � ���� ����� ������� (������������� � ������������� ������� ���������),
���������� ��� ������� �� ��� �������� operator<< ().
�������� � main() ��������������� ������:

std::cout << prey << '\n';

���������� 1.5. ����

�������� � main() ������ ������������ �� ���� �� ����� ������, � ��������� ��������������� ������� ������ ���������. ���������� ��������.


*/
