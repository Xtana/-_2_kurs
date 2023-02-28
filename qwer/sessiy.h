#include <iostream>
#include <stdio.h> 
#include <math.h>
#include <locale.h> // ���������� ��� �������� ������� (������������ ���������)
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
		cout << "�����������\n";
	}

	Student(string name, string sername, string grup) {
		this->name = name;
		this->sername = sername;
		this->grup = grup;
		this->grads = (int*)malloc(sizeof(int) * 5);
		for (int i = 0; i < 5; i++) {
			grads[i] = 0;
		}
		cout << "�����������\n";
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
				cout << "������������� " <<  name << " "<< sername << " ������ ������ �������� (" << stud.name << " " << stud.sername << " " << stud.grup << ")" << endl;
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
			cout << "������� (" << stud.name <<" " << stud.sername<< " "<< stud.grup << ") ��������" << endl;
		}
	}
};

int Sessey() {
	setlocale(LC_ALL, "Rus");

	srand(time(0));

	Student a("����", "������", "�_1");
	Student b("����", "������", "�_1");
	Student c("����", "������", "�_1");
	Student d("����", "������", "�_1");
	Student e("����", "������", "�_1");

	Teacher A("�������", "�������");
	Teacher B("�������", "�������");
	Teacher C("������", "�������");
	Teacher D("������", "�������");
	Teacher E("������", "��������");

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
