#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Train {
	string name1;
	string name2;
	int tH_1, tM_1, tH_2, tM_2;

public: 

	Train() {
		string name1, name2;
		int tH_1, tM_1, tH_2, tM_2;

		printf("������� ����� ��������: \n");
		cin >> name1;
		this->name1 = name1;
		printf("������� ����� ��������: \n");
		cin >> name2;
		this->name2 = name2;
		printf("������� ��� �������� (24�):\n");
		scanf_s("%i", &tH_1);
		this->tH_1 = tH_1;
		printf("������� ������ �������� :\n");
		scanf_s("%i", &tM_1);
		this->tM_1 = tM_1;
		printf("������� ��� �������� (24�):\n");
		scanf_s("%i", &tH_2);
		this->tH_2 = tH_2;
		printf("������� ������ �������� :\n");
		scanf_s("%i", &tM_2);
		this->tM_2 = tM_2;
	}

	Train& sum(const Train b) {
		if ((name1 != b.name2) && (name2 == b.name1) && ((tH_2 < b.tH_1) || ((tH_2 == b.tH_1) && (tM_2 < b.tM_1)))) {
			cout << "\n����� ������������ �� " << name1 << " � ��������� � " << b.name2 << endl;
			printf("����� ������������ � %i:%i � ��������� � %i:%i", tH_1, tM_1, b.tH_2, b.tH_2);
		}
		else printf("���������� ������� ������");

		return *this;
	}
};

void HW_4() {

	setlocale(LC_ALL, "Rus");

	printf("������ �����\n");
	Train A;
	printf("\n������ �����\n");
	Train B;

	A.sum(B);


}



/*
�������� ��������� � ������ train, ���������� ����: �������� ������� ����������� � ����������, 
����� ����������� � ��������. ����������� �������� �������� - ��� ������ ����� �������, 
���� ����� ���������� ������� ��������� � ������� ����������� ������� � ����� �������� ������� ������, 
��� ����������� �������. ��� ����, ����� ����������� � �������� ������������ ��� ������������� ������ 
� �� ����� ������ ��������.
*/