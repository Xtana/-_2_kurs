#include <iostream>
#include <string>
using namespace std;


class Average {

	friend ostream& operator << (ostream& os, const Average& p);

	int i = 0;
	float sum = 0;
	float aver = 0;

public:

	Average& operator+= (int item) {
		i++;
		sum += item;
		aver = sum / i;
		return *this;
	}

	Average& operator+= (const Average& aver) {
		i++;
		sum += aver.sum;
		this->aver = sum / i;
		return *this;
	}

	Average& operator+ (int item) {
		i++;
		sum += item;
		aver = sum / i;
		return *this;
	}

	Average& operator+ (const Average& aver) {
		i++;
		sum += aver.sum;
		this->aver = sum / i;
		return *this;
	}

};

ostream& operator << (ostream& os, const Average& p)
{
	return os << p.aver;
}

void HW_2() {
	Average avg1, avg2;

	avg1 += 5;
	cout << avg1 << '\n'; // 5
	avg1 += 9;
	cout << avg1 << '\n'; // 7
	avg1 += 19;
	cout << avg1 << '\n'; // 11
	avg1 += -9;
	cout << avg1 << '\n'; // 6
	(avg1 += 7) += 11;
	cout << avg1 << '\n'; // 7
	avg2 = avg1;
	cout << avg2 << '\n'; // 7
	avg2 = avg2 + avg1 + 20;
	cout << avg2 << '\n'; // 8
}


/*
�������� ����� Average, ������� ����� ������� ������� �������� ���� ����� �����,
� �������� �� ���������������. ����� ����������� ������ ����� ���������� ������� 
������ ������� ������ ������ ������� ������� ��������
(��� ����� �����) � ���������� ������������ ��������.

��� ���� ������ ����������� ��������� ���:

Average avg1, avg2;

avg1 += 5;

std::cout << avg1 << '\n'; // 5

avg1 += 9;

std::cout << avg1 << '\n'; // 7

avg1 += 19;

std::cout << avg1 << '\n'; // 11

avg1 += -9;

std::cout << avg1 << '\n'; // 6

(avg1 += 7) += 11;

std::cout << avg1 << '\n'; // 7

avg2 = avg1;

std::cout << avg2 << '\n'; // 7

avg2 = avg2 + avg1 + 20;

std::cout << avg2 << '\n'; // 8
*/