//
//  Student.hpp
//  2016_FinalExam
//
//  Created by Kim Il Sik on 29/11/2017.
//  Copyright © 2017 Kim Il Sik. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp
#include <string>
#include <iostream>
using namespace std;

class Student {
protected:
    int id;
    string name;
public:
    Student(int id = 0, const string & n = "noname") : id(id), name(n) {}
    virtual ostream & operator<<(ostream & os) { // 이거를 virtual로 만드는 게 중요하다.
        return os << this->id << " " << this->name << " ";
    }
//    friend ostream & operator<<(ostream & os, Student & st) {
//        return st << os;
//    }
    friend ostream & operator<<(ostream & os, Student * st) {
        return *st << os;
    }
    int getId() { return this->id; }
    string getName() { return this->name; }
};

#endif /* Student_hpp */
