//
// functor, array, typeinfo, iterator
// lambda return
//
// find, find_if, typeid(a).name()
//
//
//
//
//
//
//
//
#include <iostream>
#include <functional>
#include <array>
#include <string>
#include <vector>
#include <typeinfo>
#include <iterator>
using namespace std;

class Functor
{
public:
    void operator()(){
        cout << "Simple functor." << endl;
    }

};

struct Accumulator {
    Accumulator() {
        counter = 0;
    }
    int counter = 0; // struct 도 가능..
    int operator()(int i) {
        return counter += i;
    }
};


void testfunc(int(*p)[4][2])
{
    cout << "testfunc 주소 : " << &p << endl;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 2; ++j)
            cout << (*p)[i][j] << endl;
}

void testfunc2(int(*p)[2])
{
    cout << "testfunc2 주소 : " << &p << endl;
    
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 2; ++j)
            cout << p[i][j] << endl;
}

class EvenOddFunctor {
public:
    EvenOddFunctor() : evenSum(0), oddSum(0) {
    };
    void operator()(int x)
    {
        if (x % 2) oddSum += x;
        else evenSum += x;
    }
    int sumEven() { return this->evenSum; }
    int sumOdd() { return this->oddSum; }
private:
    int evenSum = 0;
    int oddSum = 0;
};

bool isOdd(int x) {return x % 2 == 1;}

class CIsOdd {
public:
    bool isOdd(int x) { return x % 2 == 1; }
};

#define _USE_FUNC_POINTER_


void testref(char(&arr)[3][2][10])
{
    for (int i = 0; i < 3; ++i)
        cout << arr[i][0] << " " << arr[i][1] << endl;
}

void testIntRef(int & a){
    cout << &a << endl;
    cout << a << endl;
}

void testIntPointer(int * a) {
    cout << &a << endl;
    cout << *a << endl;
};

void testIntVal(int a) {
    cout << &a << endl;
    cout << a << endl;
}

std::function<int (int)> retFunc1() {
    return [](int x) {
        cout << x << endl;
        return x;};
}

std::function<char (char)> retFunc2() {
    return [](char c) {
        cout << c << endl;
        return c + 1;
    };
};

int main()
{
    vector<string> a(100, "hello, world!");
    vector<string> b(a); // just copying the vector.
    //int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    //for_each(a.begin(), a.end(), [](string d){cout << d << endl;});
    
    copy(a.begin(), a.end(), back_inserter(b)); // push_back
    
    //for_each(b.begin(), b.end(), [](string d){cout << d << endl;});
    
    copy(b.begin(), b.end(), ostream_iterator<string>(cout, "\n"));
    
//    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int arr2[10] = { 0, };
//    
//    copy(begin(arr), end(arr), begin(arr2));
//    
//    for_each(begin(arr2), end(arr2), [](int d){cout << d << endl;});
//    
//    int dArr[2][2] = {0, 1, 2, 3 };
//    int dArr2[2][2] = { 0, };
//    
//    copy(begin(dArr), end(dArr), begin(dArr2));
    //for_each(begin(dArr2), end(dArr2), [](int d) {cout << d << endl;});
    
    
    
    
    //for_each(begin(arr), end(arr), ostream_iterator<int>(cout, "\n"));
        
//    vector<int> v;
//    
//    v.push_back(10);
//    v.push_back(20);
//    
    //std::copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n")); // ostream에 v를 카피한다..엄청 로우레벨..
    
    
    
    
    
//    array<int, 10> arr = { 3, 2, 1, 4, 9, 10, 7, 8, 4, 6 };
//    
//    auto showOriginalArray = [=]() {
//        std::for_each(arr.cbegin(), arr.cend(), [](int i) { // cbegin, cend : return const iterator.
//            cout << i << " ";
//        });
//        cout << endl;
//    }; // capture the array at the point and save it to the function scope tables.
//    
//    showOriginalArray();
//
//    sort(arr.begin(), arr.end(), less<int>());
//    
//    auto showSortedArray = [=]() {
//        for_each(arr.cbegin(), arr.cend(), [](int i) {
//            cout << i << " ";
//        });
//        cout << endl;
//    };
//    
//    showSortedArray();
//    showOriginalArray();
//    
    
    
    
    
    
    //int arr[5] = {1, 2, 3, 4, 5};
    
    //for_each(begin(arr), end(arr), [&](int & x) {cin >> x;});// begin, end : #include <iterator>
    //for_each(std::begin(arr), std::end(arr), [](int x) {cout << x << endl; });
    //cout << typeid(greater<int>()).name();
    
//    vector<int> v = {10, 2, 55, 30, 25};
//    
//    //auto it = find_if(v.begin(), v.end(), [](int i) -> bool { return (i % 2) == 1; }); // 새로 만든 컨테이너의 이터레이터 리턴.
//    //for_each(it, v.end(), [](int d) -> void { cout << d << endl; });
//    
//    int evenSum = 0, oddSum = 0;
//    
//    for_each(v.begin(), v.end(), [&](int n) -> void {
//        if (n % 2) oddSum += n;
//        else evenSum += n;
//    });
//    
//    cout << evenSum << " " << oddSum << endl;
//    
//    
//    [](){cout << "let's go!" << endl;}();
//    auto coutf = [](){cout << "let's go!" << endl;};
//    coutf();
//    
//    int a = 10;
//    
//    cout << typeid(a).name() << endl;
//    cout << typeid(coutf).name() << endl;
//    
//    auto f = retFunc();
//    
//    f(10);
    
    //cout << typeof(coutf);
    
    
    
    
    
    
    
    
    

    
    
    
//    string a = "123";
//    string b = "abcd";
//    bool testEqual = a == b;
//    bool testLessThan = a < b;
//    bool testBiggerThan = a > b;
//    
//    cout << a + b << endl;
//    
//    a += b;
//    
//    cout << a << endl;
//    cout << testEqual << endl;
//    cout << testLessThan << endl;
//    cout << testBiggerThan << endl;
    
    
    
//    char user[3][2][10] = {
//        {"casdf", "dqwe"},
//        {"lbd", "aas"},
//        {"awqwe", "Qweq"}
//    };
//
//    for (int i = 0; i < 3; ++i)
//        cout << user[i][0] << " " << user[i][1] << endl;
    
//    int a = 10;
//    cout << &a << endl;
//    
//    testIntVal(a);
//    testIntRef(a);
//    testIntPointer(&a);
    
    
//#ifdef _USE_FUNC_POINTER_
//
//    //auto it = find_if(v.begin(), v.end(), isOdd);
//    auto it = find_if(v.begin(), v.end(), &isOdd);
//
//#else
//    
//    CIsOdd cio;
//    
//    auto it = find_if(v.begin(), v.end(), cio);
//#endif
//
//    for_each(it, v.end(), [](int x){cout << x << endl;});
    
    //cout << *it << endl;
    
    //int p[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
//        , 9, 10,
//        11, 12, 13, 14, 15,
//        16 , 17, 18, 19, 20};
    
    //testfunc(&p);
    
    //cout << endl;
    
    //cout << "배열주소 : " << &p << endl;
    //testfunc2(p);
    
    //Functor func;
    //Accumulator acc;
    //func();
    
    //cout << acc(10) << endl;
    //cout << acc(10) << endl;
    
//    EvenOddFunctor func;
//    array<int, 10> lis = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    func = std::for_each(lis.begin(), lis.end(), func);
//    // func를 리턴받아야..
//    
//    cout << func.sumOdd() << endl;
//    cout << func.sumEven() << endl;
    
    
    return 0;
}
