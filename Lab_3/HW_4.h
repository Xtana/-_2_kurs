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

		printf("Введите пункт отправки: \n");
		cin >> name1;
		this->name1 = name1;
		printf("Введите пункт прибытия: \n");
		cin >> name2;
		this->name2 = name2;
		printf("Введите час отправки (24ч):\n");
		scanf_s("%i", &tH_1);
		this->tH_1 = tH_1;
		printf("Введите минуту отправки :\n");
		scanf_s("%i", &tM_1);
		this->tM_1 = tM_1;
		printf("Введите час прибытия (24ч):\n");
		scanf_s("%i", &tH_2);
		this->tH_2 = tH_2;
		printf("Введите минуту прибытия :\n");
		scanf_s("%i", &tM_2);
		this->tM_2 = tM_2;
	}

	Train& sum(const Train b) {
		if ((name1 != b.name2) && (name2 == b.name1) && ((tH_2 < b.tH_1) || ((tH_2 == b.tH_1) && (tM_2 < b.tM_1)))) {
			cout << "\nПоезд отправляется из " << name1 << " и прибывает в " << b.name2 << endl;
			printf("Поезд отправляется в %i:%i и прибывает в %i:%i", tH_1, tM_1, b.tH_2, b.tH_2);
		}
		else printf("Невозможно сложить поезда");

		return *this;
	}
};

void HW_4() {

	setlocale(LC_ALL, "Rus");

	printf("Первый поезд\n");
	Train A;
	printf("\nВторой поезд\n");
	Train B;

	A.sum(B);


}



/*
Создайте структуру с именем train, содержащую поля: название пунктов отправления и назначения, 
время отправления и прибытия. Перегрузить операцию сложения - два поезда можно сложить, 
если пункт назначения первого совпадает с пунктом отправления второго и время прибытия первого раньше, 
чем отправление второго. При этом, время отправления и прибытия определяется при инициализации поезда 
и не может больше меняться.
*/