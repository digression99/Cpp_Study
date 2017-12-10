// lambda return in some function.
// function object. functor.
// good things about functor is
// it can contain state.
// https://github.com/Reactive-Extensions/RxCpp
// c++ callback function implementation.

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


// functor.

class add {
public:
    int x;
    add(int x = 0) : x(x) {}
    int operator()(int y) const {
        return x + y;
    }
    int operator()(int y, int z) const {
        return x + y + z;
    }
};

template <typename T, typename PROC>
void myMap(vector<T> & vec, PROC f) {
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = f(vec[i]);
    }
}

int main() {
    add addObj(30);
    int t = addObj(20, 40);
    //int t2 = add(40); // can't. first, you need to make an object for this.
    //int t = add(3)
    //cout << t << endl;
    
    vector<int> in{10, 20, 30};
    vector<int> out(in.size());
    
    // you can send functor.
    transform(in.begin(), in.end(), out.begin(), add(30));
    //for (auto d : out) cout << d << endl;
    
    // using lambda to find some val.
    
    vector<pair<int, string>> tempVec {
        {1, "kim1"},
        {2, "kim2"},
        {3, "kim3"}
    };
    string target = "kim2";
    auto it = find_if(tempVec.begin(), tempVec.end(), [&target](const pair<int, string> & dat) -> bool{
        return dat.second == target;
    });
//    if (it != tempVec.end())
//        cout << it->first << endl;
//    else
//        cout << "not found" << endl;
    
    function<int(int)> fp = [](int x) -> int {
        return x * 2;
    };
    
    //cout << fp(30) << endl;
    //cout << [](int x) -> int { return x * 2; }(30) << endl;
    
    // std bind.
    int a = 10, b = 20;
//    function<int()> boundFunc = bind([](int x, int y) -> int {
//        return x + y;
//    }, a, b);
    
    function<int()> boundFunc = bind([](int x, int y) -> int {
        return x + y;
    }, cref(a), cref(b));
    //cout << boundFunc() << endl;
    // bind doesn't check if there's change in variable's value.
    // using cref makes it possible. -> reactive.c
    a = 30, b = 40;
    //cout << boundFunc() << endl;
    
    // placeholders.
    function<int(int)> phFunc = bind([](int x, int y) -> int {
        return x * y;
    }, 10, placeholders::_1); // number means the position of args list.
    //cout << phFunc(40) << endl;
    
    function<int(int, int)> phFunc2 = bind([](int x, int y, int z) -> int {
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;
        cout << "z : " << z << endl;
        return x + y * z;
    }, 10, placeholders::_1, placeholders::_2);
    //cout << phFunc2(30, 40) << endl;
    
    // making myMap. // can you make lambda template?
    vector<int> testVec{10, 20, 30};
    function<int(int)> mapFunc = [](int num) {
        return num * 10;
    };
    myMap(testVec, mapFunc);
    for (auto dat : testVec) cout << dat << endl;
    
    return 0;
}

