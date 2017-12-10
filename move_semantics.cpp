#include <ctime>
#include <vector>
#include <iostream>
using namespace std;

class MyClass {
public:
    int a;
};

class MyArray {
public:
    MyArray(int size) : pArr(new int[size]), size(size) {
        for (int i = 0; i < size; ++i)
            pArr[i] = i + 1;
    }
    ~MyArray() {
        cout << "destructor of my array." << endl;
    }
    int operator[](int idx) const {
        return pArr[idx];
    }
    
    MyArray(const MyArray & arr) : pArr(new int[arr.size]), size(arr.size) {
        // there's no delete[] for pArr. there could be a problem.
        for (int i = 0; i < arr.size; ++i)
            pArr[i] = arr[i];
    }
    
    MyArray(MyArray && arr) : pArr(arr.pArr), size(arr.size) {
        arr.pArr = nullptr;
    }
    
private:
    int * pArr;
    int size;
};

class X {
private:
    vector<int> vec;
public:
    X() : vec(100000)
    {
        for (int i = 0; i < 100000; ++i)
            vec[i] = i + 1;
    }
    
    // copy constructor
    X(const X & other) : vec(other.vec) {}
    
    // move constructor
    X(X && other) : vec(std::move(other.vec)) {}
    
    X & operator=(const X & other) {
        vec = other.vec;
        return *this;
    }
    
    X & operator=(X && other) {
        vec = move(other.vec);
        return *this;
    }
};

//typedef vector<MyClass> MyVec;

int & foo() {
    int a = 10;
    return a;
}

int main() {
    
    //int & foo();
    //foo() = 12;
    //cout << foo() << endl;
    
    int b = 10;
    int && rb = 20;
    cout << "Original l value b : " << b << ", r value rb  : " << rb << endl;
    rb = b;
    cout << "Modified l value b : " << b << ", r value rb  : " << rb << endl;
    
    
    //MyVec vec;
    
//    MyArray marr1(10000000);
//
//    //copy constructor
//    clock_t ct1 = clock();
//    MyArray myCopy(marr1);
//    clock_t ct2 = clock();
//    double msec1 = 1000.0 * (ct2 - ct1) / CLOCKS_PER_SEC;
//    cout << "Copy Time : " << msec1 << " msec" << endl;
//
//    clock_t mt1 = clock();
//    MyArray myMove(std::move(marr1));
//    clock_t mt2 = clock();
//    double msec2 = 1000.0 * (mt2 - mt1) / CLOCKS_PER_SEC;
//    cout << "Move Time : " << msec2 << " msec" << endl;
//
//    X x1;
//    // copy time
//    clock_t ct3 = clock();
//    X x2(x1);
//    clock_t ct4 = clock();
//    double msec3 = 1000.0 * (ct4 - ct3) / CLOCKS_PER_SEC;
//    cout << "Copy Time : " << msec3 << " msec" << endl;
//
//    // move time
//    clock_t mt3 = clock();
//    X x3(move(x1));
//    clock_t mt4 = clock();
//    double msec4 = 1000.0 * (mt4 - mt3) / CLOCKS_PER_SEC;
//    cout << "Move Time : " << msec4 << " msec" << endl;
    
    
    return 0;
}

