//#include <stdio.h>
//#include <locale.h>
//#include <string>††††††
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
//		printf("”же бегу!\n");
//	};
//	void voice() {
//		printf("ћ€у! ћ€у!\n");
//
//	}
//};
//
//
//class Dog : public Pet {
//public:
//	Dog(string pName, string mName) : Pet(pName, mName) {}
//	void preserve() {
//		printf("ќхран€ю!\n");
//	};
//	void voice() {
//		printf("√ав! √ав!\n");
//	}
//};
//
//
//class Cow : public Pet {
//public:
//	Cow(string pName, string mName) : Pet(pName, mName) {}
//	void giveMilk() {
//		printf("—вежее молоко подано!\n");
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
//	Cat murka("ћурка", "»ванова");
//	murka.voice();
//
//	Dog tuzik("Ўарик", "ѕетров");
//	tuzik.voice();
//
//	Cow nochka("ЅурЄнка", "—идорова");
//	nochka.voice();
//
//	return 0;
//}
