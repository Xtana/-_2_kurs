#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

template <typename T>
void Sum_all(vector<T> V) {
	T sum_of_elems = 0;

	for (int i = 0; i < V.size(); i++) {
		cout << V[i] << endl;
		sum_of_elems += V[i];
	}
	cout << sum_of_elems << endl;
}

template <typename T>
void Sum_all(T item) {
	cout << item << endl;
}

template <>
void Sum_all<char>(vector<char> V) {
	string sum_of_elems = "";
	for (int i = 0; i < V.size(); i++) {
		cout << V[i] << endl;
		sum_of_elems += V[i];
	}
	cout << sum_of_elems << endl;
}


int sum_all() {

	vector<int> v1 = {1, 2, 3};
	vector<double> v2 = {1, 2, 3};
	vector<string> v3 = {"as", "er", "1"};
	vector<char> v4 = {'a', 'b', 'c'};

	Sum_all(v4);

	return 0;
}