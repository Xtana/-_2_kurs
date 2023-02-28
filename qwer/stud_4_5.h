//#include <iostream>
//#include <array>
//#include <string>
//#include <algorithm>
//#include <vector>
//
//
//using namespace std;
//
//class Student {
//    template<typename T1, size_t size> friend void print(const array<T1, size>& st);
//    template<typename T1, size_t size> friend void sortt(const array<T1, size>& st);
//private:
//    string surname;
//    string NP;
//    int num_group;
//    int rating[5];
//    double avg;
//public:
//    Student() {
//        cout << "surname: ";
//        cin >> surname;
//        cout << "np: ";
//        cin >> NP;
//        cout << "group: ";
//        cin >> num_group;
//        for (int i = 0; i < 5; i++) {
//            rating[i] = 5;
//            avg += rating[i];
//        }
//        avg /= 5;
//    }
//};
//
//template<typename T1, size_t size>
//void print(const array<T1, size>& st) {
//    for (int i = 0; i < size; i++) {
//        int a = 0;
//        for (int j = 0; j < 5; j++) {
//            cout << st[i].rating[j] << "  ";
//            if (st[i].rating[j] < 4) {
//                a = 1;
//            }
//        }
//        cout << endl;
//        if (a == 1);
//        else cout << st[i].surname << "\t" << st[i].num_group << endl;
//    }
//}
////template<typename T1, size_t size>
////double* avg(const array<T1, size>& st) {
////    double avg1[size] = { 0 };
////    for (int i = 0; i < size; i++) {
////        avg1[i] = st[i].avg;
////    }
////    return avg1;
////}
//
//template<typename T1, size_t size>
//void sortt(const array<T1, size>& st) {
//    sort(st.begin(), st.end()) {
//        for (int i = 0; i < 5; i++) {
//            p
//        }
//    }
//}
//
//
//
//int stud_4_5() {
//
//    array <Student, 4> a;
//
//    print(a);
//
//
//    return 0;
//
//}