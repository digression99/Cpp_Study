//
//  Lecture.hpp
//  2016_FinalExam
//
//  Created by Kim Il Sik on 29/11/2017.
//  Copyright © 2017 Kim Il Sik. All rights reserved.
//

#ifndef Lecture_hpp
#define Lecture_hpp

#include "CollegeStudent.hpp"
#include "CommuterStudent.hpp"
#include <string>
using namespace std;

class Lecture {
protected:
    int id;
    string name;
    string prof;
    const int MAXN;
    Student ** sarr;
    int * scores;
    int len;
public:
    Lecture(int id = 0, const string & nm = "nolecturename",
            const string & pf = "noprof", int maxn = 0)
    : id(id), name(nm), prof(pf), MAXN(maxn), len(0) {
        this->sarr = new Student*[MAXN];
        this->scores = new int[MAXN];
    }
    ~Lecture() {
        // delete는 한곳에서만? 할당이 studentlist에서 되었기 때문에 여기서 해제할 필요는 없다.
        //for (int i = 0; i < this->len; ++i)
        //    delete this->sarr[i];
        delete[] this->sarr;
    }
    ostream & operator<<(ostream & os) {
        os << this->id << " " << this->name << " " << this->prof << " " << this->MAXN << endl;
        cout << "수강 학생 정보 리스트" << endl;
        this->sortStudent();
        for (int i = 0; i < len; ++i) {
            os << this->sarr[i] << " 성적 : " << this->scores[i] << endl;
        }
        return os;
    }
    friend ostream & operator<<(ostream & os, Lecture & lc) {
        return lc << os;
    }
    friend ostream & operator<<(ostream & os, Lecture * lc) {
        return *lc << os;
    }
    int getId() { return this->id; }
    
    void sortStudent() {
        for (int i = 0; i < this->len; ++i) {
            for (int j = 0; j < this->len; ++j) {
                if (this->sarr[i]->getId() > this->sarr[j]->getId()) {
                    // sarr 의 위치를 바꾼다.
                    Student * temp = this->sarr[i];
                    this->sarr[i] = this->sarr[j];
                    this->sarr[j] = temp;
                    // score 도 바꿔야 한다.
                    int tempsc = this->scores[i];
                    this->scores[i] = this->scores[j];
                    this->scores[j] = tempsc;
                }
            }
        }
    }
    bool checkStudentId(int stNum) {
        for (int i = 0; i < this->len; ++i) {
            if (stNum == this->sarr[i]->getId()) return false;
        }
        return true;
    }
    void inputScore() {
        if (this->len == 0) {
            cout << "학생이 없습니다." << endl;
        } else {
            for (int i = 0; i < this->len; ++i) {
                cout << this->sarr[i] << endl;
                cout << "성적입력 : ";
                cin >> scores[i];
            }
        }
    }
    bool addStudent(Student * st) {
        if (len == MAXN) {
            cout << "꽉 찼습니다." << endl;
            return false;
        }
        if (!checkStudentId(st->getId())) {
            cout << "이미 있습니다." << endl;
        } else {
            this->sarr[len++] = st;
            return true;
        }
        return false;
    }
};

#endif /* Lecture_hpp */
