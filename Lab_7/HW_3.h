#include <malloc.h>
#include <iostream>
#include <stdio.h> 
#include <math.h>
#include <locale.h> // Библиотека для указания локации (региональной кодировки)
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
		printf("Уже бегу!\n");
	};
	void voice() override {
		printf("Мяу! Мяу!\n");

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
		printf("Охраняю!\n");
	};
	void voice() override{
		printf("Гав! Гав!\n");
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
		printf("Свежее молоко подано!\n");
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
		printf("Икра подана!\n");
	};
	void voice() override {
		printf("буль-буль-буль!\n");
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
		printf("Я лучу!\n");
	};
	void voice() override {
		printf("Кар-кар!\n");
	}
};

class CrowFish : public Pet, public Crow, public Fish {

public:
	
	CrowFish(string pName, string mName) : Pet(pName, mName) {}

	void CrowFish_() {
		printf("Я лучу и плыву!\n");
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
		printf("я кот и пес!\n");
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

	Cat cat("Мурка", "Иванова");
	cat.voice();

	Dog dog("Шарик", "Петров");
	dog.voice();

	Fish fish("Немо", "Соболев");
	fish.voice();

	Crow crow("Немо", "Соболев");
	crow.voice();

	CrowFish crowfish("Что-то", "Михалев");
	crowfish.voice();

	CatDog catdog("Котопес", "Петрович");
	catdog.voice();

	return 0;
}

