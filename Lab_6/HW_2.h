//#include <iostream>
//#include <ctime>
//#include <string>
//
//
//using std::string;
//using std::rand;
//using std::cout;
//using std::cin;
//using std::endl;
//
//
//class Thing {
//
//	friend class Hero;
//
//	string name, useThing;
//	int weight, price;
//
//public:
//
//	Thing() {
//		this->useThing = "";
//		this->name = "";
//		this->price = 0;
//		this->weight = 0;
//	}
//
//	Thing(string name, int weight, int price, string useThing) {
//		this->name = name;
//		this->price = price;
//		this->weight = weight;
//		this->useThing = useThing;
//	}
//
//	Thing& operator= (Thing th) {
//		this->name = th.name;
//		this->price = th.price;
//		this->weight = th.weight;
//		this->useThing = th.useThing;
//		return *this;
//	}
//};
//
//class Hero {
//
//	friend class Thing;
//
//	static const int n = 7;
//	int ni = 0;
//	string name;
//	Thing backpack[n];
//
//	void delIElm(int i) {
//		int I = i;
//		for (int i = I; i < n - 1; i++) {
//			backpack[i].name = backpack[i + 1].name;
//			backpack[i].price = backpack[i + 1].price;
//			backpack[i].weight = backpack[i + 1].weight;
//			backpack[i].useThing = backpack[i + 1].useThing;
//		}
//		backpack[n - 1].name = "";
//		backpack[n - 1].price = 0;
//		backpack[n - 1].weight = 0;
//		backpack[n - 1].useThing = "";
//		ni--;
//	}
//
//public:
//
//	Hero(string name) {
//		this->name = name;
//	}
//
//	void take(Thing thing) {
//		if (ni == n) cout << "Рюкзак полон\n";
//		else {
//			backpack[ni] = thing;
//			ni++;
//		}
//	}
//
//	void sack() {
//		cout << name << "\n";
//		if (ni == 0)
//			cout << "Рюкзак пуст";
//		else
//			for (int i = 0; i < ni; i++) {
//				if (backpack[i].name != "") {
//					cout << i + 1 << ") " << backpack[i].name << "\t\t вес - " << backpack[i].weight << "\t\t цена - " << backpack[i].price << endl;
//				}
//			}
//	}
//
//	void use() {
//		string answer;
//		cout << name << "\n";
//		if (ni == 0)
//			cout << "Рюкзак пуст";
//		else {
//			cout << "Хотите использовать последний предмет из рюкзака?\n(yes)/(no)" << endl;
//			cin >> answer;
//			if (answer == "yes") {
//				backpack[ni].name = "";
//				backpack[ni].weight = 0;
//				backpack[ni].price = 0;
//				cout << backpack[ni].useThing << endl;
//				backpack[ni].useThing = "";
//				ni--;
//			}
//		}
//	}
//
//	Thing lose(string thingName) {
//
//		Thing emptuThing;
//		int k = 0;
//		for (int i = 0; i < ni; i++) {
//			if (backpack[i].name == thingName) {
//				emptuThing = backpack[i];
//				k++;
//				delIElm(i);
//			}
//		}
//		if (k == 0) cout << "Такого предмет не найден" << endl;
//		return emptuThing;
//	}
//
//	void printThing(string thingName) {
//		for (int i = 0; i < ni; i++) {
//			if (backpack[i].name == thingName) {
//				cout << backpack[i].name << "\t\t вес - " << backpack[i].weight << "\t\t цена - " << backpack[i].price << endl;
//			}
//		}
//	}
//
//};
//
//void HW_2() {
//
//	setlocale(LC_ALL, "Rus");
//
//	Thing th1("меч", 10, 10, "меч использован");
//	Thing th2("щит", 1, 1, "щит использован");
//	Thing th3("лук", 13, 13, "лук использован");
//	Thing th4("руна", 10, 10, "руна использована");
//	Thing th;
//	
//	Hero roma("Roma");
//	Hero liza("Liza");
//
//	roma.take(th1);
//	roma.take(th2);
//	liza.take(th3);
//	liza.take(th4);
//
//	roma.sack();
//	liza.sack();
//	cout << "\n";
//	th = roma.lose("меч");
//
//	liza.use();
//	liza.take(th);
//
//	roma.sack();
//	liza.sack();
//}