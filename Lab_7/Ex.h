//#include <stdio.h>
//#include <locale.h>
//#include <string>������
//
//using namespace std;
//
//class Pet {
//	string name;
//	string person;
//public:
//	Pet(string pName = "Nameless", string mName = "Nemo") : name(pName), person(mName) {}
//
//	string getName() { return name; }
//	void setName(string s) { name = s; }
//	virtual void voice() = 0;
//
//};
//
//class Cat : public Pet {
//public:
//	Cat(string pName, string mName) : Pet(pName, mName) {}
//	int mouseCatched;
//	void toMouse() {
//		printf("��� ����!\n");
//	};
//	void voice() {
//		printf("���! ���!\n");
//
//	}
//};
//
//
//class Dog : public Pet {
//public:
//	Dog(string pName, string mName) : Pet(pName, mName) {}
//	void preserve() {
//		printf("�������!\n");
//	};
//	void voice() {
//		printf("���! ���!\n");
//	}
//};
//
//
//class Cow : public Pet {
//public:
//	Cow(string pName, string mName) : Pet(pName, mName) {}
//	void giveMilk() {
//		printf("������ ������ ������!\n");
//	};
//	void voice() {
//		printf("My-y-y!\n");
//	}
//};
//
//
//int Ex() {
//
//	setlocale(LC_ALL, "Rus");
//
//	//	Pet pet;
//	//	pet.voice();
//
//	Cat murka("�����", "�������");
//	murka.voice();
//
//	Dog tuzik("�����", "������");
//	tuzik.voice();
//
//	Cow nochka("������", "��������");
//	nochka.voice();
//
//	return 0;
//}
