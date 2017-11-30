//
//  CommuterStudent.hpp
//  2016_FinalExam
//
//  Created by Kim Il Sik on 29/11/2017.
//  Copyright © 2017 Kim Il Sik. All rights reserved.
//

#ifndef CommuterStudent_hpp
#define CommuterStudent_hpp

#include "Student.hpp"

class CommuterStudent : public Student {
private:
    string companyName;
    string position;
public:
    CommuterStudent(int id = 0, string name = "noname", const string & cn = "nocompany", const string & pos = "nopos")
    : Student(id, name), companyName(cn), position(pos) {}
    ostream & operator<<(ostream & os) {
        return Student::operator<<(os) << " " << this->companyName << " " << this->position;
    }
//    friend ostream & operator<<(ostream & os, CommuterStudent & coms) {
//        return coms << os;
//    }
//    friend ostream & operator<<(ostream & os, CommuterStudent * coms) {
//        return *coms << os;
//    }
};

#endif /* CommuterStudent_hpp */
