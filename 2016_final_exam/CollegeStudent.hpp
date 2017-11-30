//
//  CollegeStudent.hpp
//  2016_FinalExam
//
//  Created by Kim Il Sik on 29/11/2017.
//  Copyright © 2017 Kim Il Sik. All rights reserved.
//

#ifndef CollegeStudent_hpp
#define CollegeStudent_hpp

#include "Student.hpp"

class CollegeStudent : public Student {
private:
    string schoolName;
    string major;
    int year;
public:
    CollegeStudent(int id = 0, string name = "noname", const string & sn="noschool",
                   const string & mj = "nomaj", int y = 0)
    : Student(id, name), schoolName(sn), major(mj), year(y) {}
    ostream & operator<<(ostream & os) {
        return Student::operator<<(os) << " " << this->schoolName << " " << this->major << " " << this->year << " ";
    }
//    friend ostream & operator<<(ostream & os, CollegeStudent & cs) {
//        return cs << os;
//    }
//    friend ostream & operator<<(ostream & os, CollegeStudent * cs) {
//        return *cs << os;
//    }
};

#endif /* CollegeStudent_hpp */
