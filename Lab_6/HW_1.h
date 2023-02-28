//#include <iostream>
//#include <ctime>
//#include <string>
//
//using std::string;
//using std::rand;
//using std::cout;
//using std::cin;
//using std::endl;
//
//class Hero1 {
//
//	struct Thing1 {
//		friend Hero1;
//
//		string name;
//		int weight, price;
//
//	public:
//
//		Thing1() {
//			this->name = "";
//			this->price = 0;
//			this->weight = 0;
//		}
//
//		Thing1(string name, int weight, int price) {
//			this->name = name;
//			this->price = price;
//			this->weight = weight;
//		}
//
//	};
//
//	static const int n = 5;
//	int ni = 3;
//	string name;
//	Thing1 backpack[n]{
//		Thing1("меч", 10, 10),
//		Thing1("щит", 1, 1),
//		Thing1("лук", 13, 13),
//		Thing1(),
//		Thing1()
//	};
//
//public:
//
//	Hero1(string name) {
//		this->name = name;
//	}
//
//	void take() {
//		if (ni >= n) cout << "–юкзак полон";
//		else {
//			string name;
//			int weight, price;
//			cout << "¬ведите название" << endl;
//			cin >> name;
//			cout << "¬ведите вес" << endl;
//			cin >> weight;
//			cout << "¬ведите цену" << endl;
//			cin >> price;
//			this->backpack[ni].name = name;
//			this->backpack[ni].price = price;
//			this->backpack[ni].weight = weight;
//			ni++;
//		}
//	}
//
//	void printBackpack() {
//		if (ni == 0) 
//			cout << "–юкзак пуст";
//		else 
//			for (int i = 0; i < ni; i++) {
//				cout << i + 1 << ") " << backpack[i].name << "\t\t вес - " << backpack[i].weight << "\t\t цена - " << backpack[i].price << endl;
//		}
//	}
//
//};
//
//void HW_1() {
//
//	setlocale(LC_ALL, "Rus");
//
//	Hero1 Roma("Roma");
//	Roma.take();
//
//	Roma.printBackpack();
//
//}
