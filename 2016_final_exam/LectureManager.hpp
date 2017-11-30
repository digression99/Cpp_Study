//
//  LectureManager.hpp
//  2016_FinalExam
//
//  Created by Kim Il Sik on 29/11/2017.
//  Copyright © 2017 Kim Il Sik. All rights reserved.
//

#ifndef LectureManager_hpp
#define LectureManager_hpp

#include "Lecture.hpp"
#include "CollegeStudent.hpp"
#include "CommuterStudent.hpp"

class LectureManager {
private:
    const static int LECLEN = 3;
    const static int STLEN = 5;
    Student ** studentList;
    Lecture * lectureList[3]; // 그냥 object로 해도 되지만, 개념상.
public:
    LectureManager() {
        this->studentList = new Student*[STLEN];
        this->lectureList[0] = new Lecture(0, "lecture1", "prof1", 2);
        this->lectureList[1] = new Lecture(1, "lecture2", "prof2", 2);
        this->lectureList[2] = new Lecture(2, "lecture3", "prof3", 1);
        
        this->studentList[0] = new CollegeStudent(1, "kim1", "school1", "major1", 1);
        this->studentList[1] = new CommuterStudent(2, "kim2", "company1", "pos1");
        this->studentList[2] = new CollegeStudent(3, "kim3", "school2", "major2", 2);
        this->studentList[3] = new CommuterStudent(4, "kim4", "company2", "pos2");
        this->studentList[4] = new CollegeStudent(5, "kim5", "school3", "major3", 4);
    }
    ~LectureManager() {
        for (int i = 0; i < STLEN; ++i)
            delete this->studentList[i];
        for (int i = 0; i < LECLEN; ++i)
            delete this->lectureList[i];
        delete[] studentList;
    }
    int getStudentIndexById(int id) {
        for (int i = 0; i < this->STLEN; ++i) {
            if (id == this->studentList[i]->getId())
                return i;
        }
        return -1;
    }
    int getLectureIndexById(int id) {
        for (int i = 0; i < this->LECLEN; ++i) {
            if (id == this->lectureList[i]->getId())
                return i;
        }
        return -1;
    }
    Student * getStudentById(int id) {
        // 이걸 인덱스로 해서, -1 이면 없는것, 있으면 그것을 그냥 참고하게끔 해도 되지 않을까.
        for (int i = 0; i < this->STLEN; ++i) {
            if (id == this->studentList[i]->getId())
                return this->studentList[i];
        }
        return nullptr;
    }
    Lecture * getLectureById(int id) {
        for (int i = 0; i < this->LECLEN; ++i) {
            if (id == this->lectureList[i]->getId())
                return this->lectureList[i];
        }
        return nullptr;
    }
    void start() {
        int selectNum = 0, applyNum = 0;
        while (selectNum != 4) {
            cout << "1. 수강신청 2. 성적입력 3. 과목조회 4. 종료 :";
            cin >> selectNum;
            
            if (selectNum >= 1 && selectNum <= 3) {
                cout << "과목 선택 : ";
                cin >> applyNum;
                Lecture * lec = this->getLectureById(applyNum);
                if (lec != nullptr) {
                    if (selectNum == 1) this->apply(lec);
                    else if (selectNum == 2) lec->inputScore();
                    else if (selectNum == 3) cout << lec << endl;
                } else {
                    cout << "과목이 없습니다." << endl;
                }
            } else if (selectNum == 4) break;
        }
    }
    bool apply(Lecture * lec) { // 이거를 lecture 클래스 안에 넣는게 어떨까.
        // 그럴 수가 없다. student를 검색해야 하기 때문.
        int stNum = 0;
        cout << "학생번호 입력 : ";
        cin >> stNum;
        
        Student * st = this->getStudentById(stNum);
        if (st != nullptr) {
            if (lec->addStudent(st)) {
                cout << "성공적으로 등록." << endl;
                return true;
            }
        }
        cout << "수강신청에 실패" << endl;
        return false;
    }
};


#endif /* LectureManager_hpp */
