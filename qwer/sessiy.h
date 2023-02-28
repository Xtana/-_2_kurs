#include <iostream>
#include <stdio.h> 
#include <math.h>
#include <locale.h> // Библиотека для указания локации (региональной кодировки)
#include <stdlib.h>
#include <string>
using namespace std;


class Student {
	friend class Teacher;
	friend class Decan;

protected:
	string name = "", sername = "", grup = "";
	int* grads;
	int ni = 0;
public:
	Student() {
		this->name = "";
		this->sername = "";
		this->grup = "";
		grads = (int*)malloc(sizeof(int) * 5);
		for (int i = 0; i < 5; i++) {
			grads[i] = 0;
		}
		cout << "Конструктор\n";
	}

	Student(string name, string sername, string grup) {
		this->name = name;
		this->sername = sername;
		this->grup = grup;
		this->grads = (int*)malloc(sizeof(int) * 5);
		for (int i = 0; i < 5; i++) {
			grads[i] = 0;
		}
		cout << "Конструктор\n";
	}

	void print() {
		cout << name << " " << sername << " " << grup << "              \t";
		for (int i = 0; i < 5; i++) {
			cout << grads[i] << "\t";
		}
		cout << endl;
	}

	~Student() {
		delete[] grads;
	}

};

class Teacher {
	string name = "", sername = "";
public:

	Teacher() {
		this->name = "";
		this->sername = "";
	}

	Teacher(string name, string sername) {
		this->name = name;
		this->sername = sername;
	}
	void setGrads(Student& stud) {
		for (int i = 0; i < 5; i++) {
			if (stud.grads[i] == 0) {
				int grad=0;
				cout << "Преподаватель " <<  name << " "<< sername << " ставит оценку студенту (" << stud.name << " " << stud.sername << " " << stud.grup << ")" << endl;
				/*cin >> grad;*/
				grad = rand()%4+2;
				stud.grads[i] = grad;
				break;
			}
		}
	}
};

class Decan {
public:
	void chekcGrads(Student& stud) {
		int k = 0;
		for (int i = 0; i < 5; i++) {
			if (stud.grads[i] == 2) k++;
		}
		if (k >= 2) {
			cout << "Студент (" << stud.name <<" " << stud.sername<< " "<< stud.grup << ") отчислен" << endl;
		}
	}
};

int Sessey() {
	setlocale(LC_ALL, "Rus");

	srand(time(0));

	Student a("Коля", "Пупкин", "И_1");
	Student b("Вася", "Пупкин", "И_1");
	Student c("Миша", "Пупкин", "И_1");
	Student d("Петя", "Пупкин", "И_1");
	Student e("Витя", "Пупкин", "И_1");

	Teacher A("Николай", "Михалев");
	Teacher B("Евгений", "Михалев");
	Teacher C("Мизаил", "Михалев");
	Teacher D("Виктор", "Михалев");
	Teacher E("Лариса", "Ивановна");

	Decan F;

	Student listStud[5] = { a, b, c, d, e};
	Teacher listTeach[5] = { A, B, C, D, E };

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			listTeach[i].setGrads(listStud[j]);
		}
	}
	cout << endl;

	for (int j = 0; j < 5; j++) {
		listStud[j].print();
	}

	cout << endl;

	for (int j = 0; j < 5; j++) {
		F.chekcGrads(listStud[j]);
	}

	return 0;
}
