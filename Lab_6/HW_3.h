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
//	static const int nf = 10;
//	int ni = 0;
//	int nfi = 0;
//	string name;
//	Thing backpack[n];
//	Hero* friends[nf];
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
//		cout << endl;
//	}
//
//	void use() {
//		string answer;
//		cout << name << "\n";
//		cout << "Воспользоваться своими предметами или предметами друга?\nсвоими - 0, друга - 1" << endl;
//		int k = 0;
//		cin >> k;
//		if (k == 0){
//			if (ni == 0)
//				cout << "Рюкзак пуст\n" << endl;
//			else {
//				cout << "Хотите использовать последний предмет из рюкзака?\n(yes)/(no)" << endl;
//				cin >> answer;
//				cout << endl;
//				if (answer == "yes") {
//					backpack[ni-1].name = "";
//					backpack[ni-1].weight = 0;
//					backpack[ni-1].price = 0;
//					cout << backpack[ni-1].useThing<< "\n" << endl;
//					backpack[ni-1].useThing = "";
//					ni--;
//				}
//			}
//		}
//		else if (k == 1) {
//			int numFriend = 0;
//			if (nfi == 0) cout << "У вас нет друзей\n" << endl;
//			else {
//				cout << "Предметами какого друга хотите воспользоваться" << endl;
//				for (int i = 0; i < nfi; i++) {
//					cout << i + 1 << ") " << friends[i]->name << endl;
//				}
//				cin >> numFriend;
//				cout << endl;
//				numFriend--;
//				if (friends[numFriend]->ni == 0)
//					cout << "Рюкзак пуст\n" << endl;
//				else {
//					cout << "Хотите использовать последний предмет из рюкзака друга " << friends[numFriend]->name << "?\n(yes)/(no)" << endl;
//					cin >> answer;
//					if (answer == "yes") {
//						friends[numFriend]->backpack[friends[numFriend]->ni-1].name = "";
//						friends[numFriend]->backpack[friends[numFriend]->ni-1].weight = 0;
//						friends[numFriend]->backpack[friends[numFriend]->ni-1].price = 0;
//						cout << friends[numFriend]->backpack[friends[numFriend]->ni-1].useThing << "\n" << endl;
//						friends[numFriend]->backpack[friends[numFriend]->ni-1].useThing = "";
//						friends[numFriend]->ni--;
//					}
//				}
//			}
//
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
//	void adFfriend(Hero* Friend) {
//		cout << name << "\n";
//		if (nfi == nf) cout << "Список друзей переполнен\n";
//		else {
//			friends[nfi] = Friend;
//			nfi++;
//			cout << name << " добавил друга " << Friend->name << "\n" << endl;
//		}
//	}
//
//};
//
//void HW_3() {
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
//	Hero tema("Tema");
//
//	roma.take(th1);
//	roma.take(th2);
//	roma.take(th3);
//	roma.take(th4);
//	liza.take(th1);
//	liza.take(th2);
//	liza.take(th3);
//	liza.take(th4);
//	tema.adFfriend(&roma);
//	tema.adFfriend(&liza);
//
//	roma.sack();
//	liza.sack();
//
//	tema.use();
//
//	roma.sack();
//	liza.sack();
//}