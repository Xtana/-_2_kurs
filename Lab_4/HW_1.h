
class Number {
    double a;

public:

    Number(double a = 0) {
        this->a = a;
    }

    ~Number() {
        cout << "\n����������";
    }

    void setValues(double a) {
        this->a = a;
    }

    void print() {
        cout << a << endl;
    }

    bool isEqual(Number& num);

};

bool Number::isEqual(Number& num) {
    return a == num.a;
}


int HW_1() {

    setlocale(LC_ALL, "Rus");

    Number a(5);
    Number b(7);
    cout << "Number1:" << endl;
    a.print();
    cout << "Number2:" << endl;
    b.print();
    cout << "������� �������� Number1" << endl;
    a.setValues(2);
    a.print();

    if (a.isEqual(b))
        cout << "\nNumber1 and Number2 are equal\n";
    else
        cout << "Number1 and Number2 are not equal\n";

    return 0;
}

/*��
������� 1.
�������� ����� ������ Numbers. ���� ����� ������ �����: ��� �������� ����������-����� ���� double; 
����������� (� ��������� �� ���������) � ����������; �������� ����� � ������ setValues(), 
������� �������� ������������� �� ��������;    �������� ����� � ������ print(), 
������� ����� �������� ������ ������ Numbers; � ������� isEqual() ��������������� ���������� �������� �������������:

if (Number1.isEqual(Number2))
    cout << "Number1 and Number2 are equal\n";
else
    cout << "Number1 and Number2 are not equal\n";

*/


