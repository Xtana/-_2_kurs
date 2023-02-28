#include <iostream>
#include <string>
using namespace std;

template <int a, typename T1 = int, typename T2 = int>
class Complex {
    template <int a, typename T1, typename T2>friend ostream& operator << (ostream& os, const Complex<a,T1,T2>& c);
    template <int a, typename T1, typename T2>friend istream& operator >> (istream& is, Complex<a,T1,T2>& c);

    T1 r; // x = Re + Im*i 
    T2 m;
public:
    Complex(T1 nr = 0, T2 nm = 0) : r(nr), m(nm) { }
    Complex<a,T1,T2> operator+= (const Complex<a,T1,T2>& c);
    Complex<a,T1,T2> operator+ (const Complex<a,T1,T2>& c);
    void operator== (Complex<a, T1, T2>& c);
    void eq(const Complex<a, T1, T2>& c);
    void noteq(const Complex<a, T1, T2>& c);
};

template<int a, typename T1, typename T2>
Complex<a,T1,T2> Complex<a,T1,T2>::operator+= (const Complex<a,T1,T2>& c) {
    r += c.r;
    m += c.m;
    return *this;
}

template<int a, typename T1, typename T2>
Complex<a,T1,T2> Complex<a,T1,T2>::operator+ (const Complex<a,T1,T2>& c) {
    return *this += c;
}

template<int a, typename T1, typename T2>
void Complex<a, T1, T2>::operator== (Complex<a, T1, T2>& c) {
    if (a == 0) eq(c);
    else if (a == 1) noteq(c);
}

template<int a, typename T1, typename T2>
void Complex<a, T1, T2>::eq(const Complex<a,T1,T2>& c) {
    if (r == c.r && m == c.m) {
        cout << "�����" << endl;
    }
    else {
        cout << "�� �����" << endl;
    }
}

template<int a, typename T1, typename T2>
void Complex<a, T1, T2>::noteq(const Complex<a, T1, T2>& c) {
    if (r != c.r && m != c.m) {
        cout << "�� �����" << endl;
    }
    else {
        cout << "�����" << endl;
    }
}

template<int a, typename T1, typename T2>
ostream& operator<< (ostream& os, const Complex<a,T1,T2>& c) {
    os << "x = " << c.r << " + " << c.m << "*i" << noshowpos << endl;
    return os;
}

template<int a, typename T1, typename T2>
istream& operator>> (istream& is, Complex<a,T1,T2>& c) {
    is >> c.r >> c.m;
    return is;
}

int Exemple_1() {

    setlocale(LC_ALL, "Rus");

    Complex<0, double, double> a(2, 2), b(2, 2);
    Complex<1, string, double> c("1", 5), d("-1", 2);
    Complex<1, int> e;

    cout << "double, double" << endl;
    cout << "a) " << a;
    cout << "b) " << b;
    a == b;
    cout << endl;
    cout << "string, double" << endl;
    cout << "c) " << c;
    cout << "d) " << d;
    c == d;
    cout << endl;

    Complex<0, double, double> r1 = a + b;
    Complex<1, string, double> r2 = c + d;

    cout << "a+b) ";
    cout << r1;
    cout << "c+d) ";
    cout << r2;

    cout << "\n���� � ����������: ";
    cin >> e;
    cout << e;

    return 0;
}


/*
�������� ����� ������� �������� ��������� ������ � ������� (��������) � ����������� ��� ������������� ������ �� ��� � �����������.


+ ���������� 1.1.
���������� ������� �� ������ ���������� ������� ����������� ����� � ��������������� � 
������ ������ ��������������� � ������� ����� � ��������� ������ (float, double) � �������� (char).
������� ��� ������������� � ���������� ���������� �������� ����������� ������. ��� ������������� �������� ������ ����������� ������������.


+ ���������� 1.2.
����������� ��� ������� �������� ����� � ������ ����� ������ >> � <<.


�������� ��������, ��� ��������� �������� �������� ���������� �����:
        template <������ ���������� ������� ������> class ���_�������_������ { ... };
����� ���������� ������� ����� �������� ����� �� ����� �������:
                ���_�������_������ <������ ����������� ���������� �������>

+ ���������� 1.3.
����������� ������ ����� �������, ����� ���� ������ r � m ���� ��������. � ����������� ��� ���� ������ ������ � ������� ������������� � ���������.


���������� 1.4.
����������� ��������� ����� �������, ����� ����� �� �������� ������� ���� ���������� ��������� ��������� ����������� �����.
�.�. ����� ����� ���� �������� �� ������ ���� ������, �� � ������ ��������� ���� ����������� �����.
*/

