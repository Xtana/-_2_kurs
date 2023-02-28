#include <stdio.h> 
#include <math.h>
#include <locale.h> // ���������� ��� �������� ������� (������������ ���������)
#include <stdlib.h>


class Summa {
private:
	int x;
	int y;

public:
	// �����������
	Summa(int X, int Y) {
		x = X;
		y = Y;
	}

	int GetX_4() {
		return x;
	}

	void SetX_4(int valueX) {
		x = valueX;
	}

	int GetY_4() {
		return y;
	}

	void SetY_4(int valueX) {
		y = valueX;
	}


	void Calculate() {
		int number, result;
		result = x + y;
		printf("%i + %i = %i\n", x, y, result);
		while (printf("���� ��� �������? "), scanf_s("%i", &number)) {
			printf("%i + %i = ", result, number);
			result = result + number;
			printf("%i\n", result);
		}
	}
};

int Exemple_4() {
	setlocale(LC_ALL, "Rus");

	Summa a(5, 6);

	printf("�������� ��������:   X = %i  Y = %i\n", a.GetX_4(), a.GetY_4());
	a.SetX_4(1);
	a.SetY_4(2);
	printf("���������� ��������: X = %i  Y = %i\n", a.GetX_4(), a.GetY_4());

	a.Calculate();
	return 0;
}

/*���������� 4.
������������� ��������� �� ���������� 3 ����� �������, ���:
-�������� x � y ���������� private
- ��� ��������� �� �������� ������������ ������� set_x � set_y, ��� �� ��������� get_x � get_y
���������������� �������� ��������� �� �������.*/
