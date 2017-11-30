//
//  main.cpp
//  2016_FinalExam
//
//  Created by Kim Il Sik on 29/11/2017.
//  Copyright © 2017 Kim Il Sik. All rights reserved.
//

#include <iostream>
#include <typeinfo>
#include "ArrayData.h"
#include "LectureManager.hpp"
using namespace std;

template <typename TYPE>
bool print(TYPE data) {
    cout << typeid(data).name() << endl;
    cout << data << endl;
    return true;
}

//class Student {
//private:
//    string name;
//    int score;
//public:
//    Student(string n = "noname", int sc = 0)
//    : name(n), score(sc)
//    {}
//    ostream & operator<<(ostream & os) {
//        return os << this->name << " " << this->score << endl;
//    }
//    friend ostream & operator<<(ostream & os, Student & st) {
//        return st << os;
//    }
//    bool operator==(const Student & st) const {
//        if (this->name == st.name && this->score == st.score) return true;
//        return false;
//    }
//    bool operator==(const string & name) const {
//        if (this->name == name) return true;
//        return false;
//    }
//};





template <typename T1, typename T2>
bool search(T1 * arr, const int & size, const T2 & data, int & index) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == data) {
            index = i;
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
//    int arr[5] = { 5, 4, 3, 2, 1 };
//    int index;
//
//    if (search(arr, 5, 3, index)) {
//        cout << arr[index] << endl;
//    }
//
//
//    string sarr[5] = {"123", "456", "234", "765", "abc"};
//    if (search(sarr, 5, "abc", index)) {
//        cout << sarr[index] << endl;
//    }
//
//    Student stuArr[3] = {
//        Student("kim1", 1),
//        Student("kim2", 2),
//        Student("kim3", 3),
//    };
//
//    if (search(stuArr, 5, Student("kim2", 2), index)) {
//        cout << stuArr[index] << endl;
//    }
    LectureManager lm;
    lm.start();
//    ArrayData<int> ad;
//
//    ad.addElement(10);
//    ad.addElement(20);
//    ad.addElement(40);
//    cout << ad << endl;
//    print(10);
//    print(10.4);
//    print("str");
//    cout << endl;
//    //print(Student("kim1", 10));
//    print(CollegeStudent());
//    print(CommuterStudent());
    
    return 0;
}
