#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Client;
class Admin;

class Account {
	friend class Admin;
	friend class Client;
	float money = 0;
public:
	Account() {
		money = 0;
	}

	Account(float m) {
		money = m;
	}
};

class Admin {
	friend class Client;
	friend class Account;

public:

	void check(int m, Client& person1, Client& person2);
};

class Client {
	friend class Admin;
	friend class Account;

	string name;
	Account ac;

public:

	Client() {
		name = "";
	}

	Client(string name, Account& ac) {
		this->name = name;
		this->ac = ac;

	}

	float moneyTransform(Client& person) {
		float m=0;
		cout << name << endl;
		cout << "На вашем счету: " << ac.money << endl;
		cout << "Какую сумму хотите перевести? " << endl;
		cin >> m;
		cout << endl;
		return m;
	}

	void printf() {
		cout << "Имя: " << name << "\t" << "суммау на счету: " << ac.money<< endl;
	}
};

void Admin::check(int m, Client& person1, Client& person2) {
	if (m > person1.ac.money) cout << "На вашем ситу недостаточно средств" << endl;
	else {
		person1.ac.money -= m;
		person2.ac.money += m;
	}
}


int client() {

	setlocale(LC_ALL, "Rus");

	Account a(1000), b;
	Client client1("Петя", a), client2("Вова", b);
	Admin admin;

	client1.printf();
	client2.printf();
	admin.check(client1.moneyTransform(client2), client1, client2);
	client1.printf();
	client2.printf();

	return 0;
}
