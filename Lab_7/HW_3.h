#include <malloc.h>
#include <iostream>
#include <stdio.h> 
#include <math.h>
#include <locale.h> // ���������� ��� �������� ������� (������������ ���������)
#include <stdlib.h>
#include <string>
#include <ctime>
using namespace std;

class Pet {
protected:
	string name;
	string person;

public:
	Pet() {
		name = "";
		person = "";
	}

	Pet(string pName, string mName) : name(pName), person(mName) {}
	string getName() { return name; }
	void setName(string s) { name = s; }
	virtual void voice() = 0;
};

class Cat : public Pet {
public:

	Cat() {
		name = "";
		person = "";
	}
	Cat(string pName, string mName) : Pet(pName, mName) {}
	int mouseCatched;
	void toMouse() {
		printf("��� ����!\n");
	};
	void voice() override {
		printf("���! ���!\n");

	}
};

class Dog : public Pet {
public:
	Dog() {
		name = "";
		person = "";
	}
	Dog(string pName, string mName) : Pet(pName, mName) {}
	void preserve() {
		printf("�������!\n");
	};
	void voice() override{
		printf("���! ���!\n");
	}
};

class Cow : public Pet {
public:

	Cow() {
		name = "";
		person = "";
	}
	Cow(string pName, string mName) : Pet(pName, mName) {}
	void giveMilk() {
		printf("������ ������ ������!\n");
	};
	void voice() override {
		printf("My-y-y!\n");
	}
};

class Fish : public Pet {
public:
	Fish() {
		name = "";
		person = "";
	}
	Fish(string pName, string mName) : Pet(pName, mName) {}
	void giveCavia() {
		printf("���� ������!\n");
	};
	void voice() override {
		printf("����-����-����!\n");
	}

};

class Crow : public Pet {
public:
	Crow() {
		name = "";
		person = "";
	}
	Crow(string pName, string mName) : Pet(pName, mName) {}
	void giveCavia() {
		printf("� ����!\n");
	};
	void voice() override {
		printf("���-���!\n");
	}
};

class CrowFish : public Pet, public Crow, public Fish {

public:
	
	CrowFish(string pName, string mName) : Pet(pName, mName) {}

	void CrowFish_() {
		printf("� ���� � �����!\n");
	};

	void voice() override {
		int a = rand() % 2;
		if (a == 0) Crow::voice();
		else Fish::voice();
	}

};

class CatDog : public Pet, public Cat, public Dog {

public:

	CatDog(string pName, string mName) : Pet(pName, mName) {}

	void CatDog_() {
		printf("� ��� � ���!\n");
	};

	void voice() override {
		int a = rand() % 2;
		if (a == 0) Cat::voice();
		else Dog::voice();
	}

};

int HW_3() {

	srand(time(0));

	setlocale(LC_ALL, "Rus");

	//	Pet pet;
	//	pet.voice();

	Cat cat("�����", "�������");
	cat.voice();

	Dog dog("�����", "������");
	dog.voice();

	Fish fish("����", "�������");
	fish.voice();

	Crow crow("����", "�������");
	crow.voice();

	CrowFish crowfish("���-��", "�������");
	crowfish.voice();

	CatDog catdog("�������", "��������");
	catdog.voice();

	return 0;
}

