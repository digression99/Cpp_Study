#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Dummy {
public:
    int a;
    string name;
    static int id;
    int nowId;
    // int * arr;
    // int len;
    
    Dummy() : a(0), name("noname"), nowId(id++) {
        
        cout << "default constructor," << this->name << ", " << this->nowId << endl;
        // this->len = 1;
        // this->arr = new int[len];
    }
    Dummy(int a, string n) : a(a), name(n), nowId(id++) {
        cout << "constructor with args, " << this->name << ", " << this->nowId << endl;
    }
    Dummy(const Dummy & dm) : a(dm.a), name(dm.name), nowId(id++) {
        // cout << &dm.arr << endl; // 주소를 체크하라.
        cout << "copy constructor, " << this->name << ", " << this->nowId << endl;
    }
    ~Dummy() {
        cout << "destructor, " << this->name << ", " << this->nowId << endl;
    }
    Dummy operator+(const Dummy & dm) {
        cout << "add operator" << endl;
        if (this == &dm) return *this;
        this->a = dm.a;
        return *this;
    }
};

int Dummy::id = 0;

Dummy callByValue(Dummy dm) {
    cout << "call by value, dm.a : " << dm.a << endl;
    return dm;
}

Dummy & callByReference(Dummy & dm) {
    cout << "call by reference, dm.a : " << dm.a << endl;
    return dm;
}

Dummy * callByPointer(Dummy * dm) {
    cout << "call by pointer, dm.a : " << dm->a << endl;
    return dm;
}

int main() {
    Dummy dm1(10, "dummy1");
    cout << "Call by value." << endl;
    Dummy dm2 = callByValue(dm1);
    dm2.a = 100;
    cout << "dm1 : " << dm1.a << endl;
    cout << "dm2 : " << dm2.a << endl;
    
//    Dummy dm1(20, "dummy2");
//    cout << "call by reference" << endl;
//    //Dummy dm2 = callByReference(dm1); // 복사됨. Dummy & dm2 가 아니기 때문.
//    Dummy & dm2 = callByReference(dm1); // 복사안되고 dm2 = dm1이 됨.
//    dm2.a = 100;
//    cout << "dm1 : " << dm1.a << endl;
//    cout << "dm2 : " << dm2.a << endl;
    
//    Dummy dm1(10, "dummy1");
//    cout << "Call by pointer." << endl;
//    Dummy * dm2 = callByPointer(&dm1);
//    dm2->a = 100;
//    cout << "dm1 : " << dm1.a << endl;
//    cout << "dm2 : " << dm2->a << endl;
    
    return 0;
}
