#include<iostream>
#include <string>
using namespace std;


class Substring {

	string str;
public: 

	Substring(string str) {
		this->str = str;
	}

	string operator() (char startStr, int lenSubstring) {
		string Substring = "";
		int lenString = str.size();									// длинна строки
		int tempI;
		for (int i = 0; i < lenString - 1; i++) {
			if (str[i] == startStr) {
				if (lenString - i < lenSubstring) {
					cout << "Длинна подстроки которую вы хотите вывести меньше чем длинна, которую вы указали" << endl;
					lenSubstring = 0;
					break;
				}
				for (int j = i; j < lenString - i; j++) {
					if (lenSubstring > 0) {
						Substring += str[j];
						lenSubstring--;
					}
					else break;
				}
			}
			if (lenSubstring == 0) break;
		}
		return Substring;
	}
};

int HW_1() {
	setlocale(LC_ALL, "Rus");

	Substring str("hello my friend");

	cout << str('e', 9);

	return 0;
}




/*Напишите класс, переменной - членом которого является строка.
Перегрузите оператор() для возврата подстроки, которая начинается с индекса, 
указанного в значении первого параметра. Второй параметр должен указывать требуемую длину подстроки.
Таким образом расширенный класс строк будет поддерживать операцию взятия среза.*/