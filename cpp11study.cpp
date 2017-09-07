#include <vector>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

class myVector {
    vector<int> vec;
    
public:
    
    myVector(const initializer_list<int> & v) {
        
        for (auto itr = v.begin(); itr != v.end(); ++itr)
        {
            vec.push_back(*itr);
        }
        
        // if it's single item,
        // data = *(v.begin());
    }
    
    vector<int>::iterator begin() {
        return this->vec.begin();
    }
    
    vector<int>::iterator end() {
        return this->vec.end();
    }
};

class Dog {
public:
    int age;
    string name;
    int legs;
    int initVal = 0;
    
    Dog() : age(0), name("noname") {
        if (initVal == 0)
        {
            initVal = 1;
            cout << "initVal was 0" << endl;
        }
    }
    
    // Dog() -> delegating constructor
    Dog(int age, string name) : Dog() { this->age = age; this->name = name;}
    
    Dog(int age, string name, int legs) : Dog(age, name) {
        this->legs = legs;
    }
    
    // pure virtual
    // virtual void D() = 0;
    
    //testing new keyword.
    // virtual function needs to be defined.
    virtual void A(int d) {cout << "I'm in parent, d : " << d << endl;}
    virtual void B() {cout << "I'm in parent, B()!" << endl;}
    void C(); // if you don't define all the function in the class, it won't compile.
};



void Dog::C() {

    cout << "C" << endl;
}

template<typename func>
void filter(func f, vector<int> arr) {
    for (auto i : arr) {
        if (f(i)) {
            cout << i << " ";
        }
    }
}

class RedDog : public Dog
{
public:
    RedDog() = default;
    RedDog(int age, string name) : Dog(age, name) {
        cout << "Red Dog constructor called." << endl;
    };
    
    //void A(float) override; // override 를 하면 A(float)가 없으므로 에러.
    void A(int t) override final
    {
        cout << t << endl;
    }
        
    void B() override {
        cout << "B" << endl;
    }
};

constexpr int cubed(int x) {return x * x * x; }

int main()
{
    static_assert(sizeof(int) == 4); // this will not be compiled if the size of int is not 4.
    
    myVector v{10, 20, 30, 40};
    Dog myDog = {10, "ma choo"};
    //Dog myDog2;
    RedDog rd = RedDog(20, "nsdfame");
    
    for (auto dat : v) cout << dat << endl;
    
    cout << myDog.age << " " << myDog.name << endl;
    cout << rd.age << " " << rd.name << endl;
    //cout << myDog2.age << " " << myDog2.name << endl;
    
    for (auto & dat : v) { // reference 로 값을 바꿀 수 있다.
        dat++;
        cout << dat << endl;
    }
    
    
    // enum class
    enum class apple {green, red};
    enum class orange{big, small};
    apple a = apple::green;
    orange b = orange::big;
    // compile fail 왜냐면 두 클래스 자체가 다르기 때문에.
    // 더 안전한 사용.
    
    //if (a == b) cout << "same" << endl;
    //else cout << "diff" << endl;
    
    
    // lambda

    cout << [](int x, int y) {
        cout << "I'm lambda!" << endl;
        return x + y;
    }(3, 4) << endl;
    
    auto f = [](int x, int y) {return x * y;};
    cout << f(3, 4) << endl;
    
    vector<int> v2 = {1, 2, 3, 4, 5, 6};
    filter([](int x) {
        return x > 3;
    }, v2);
    int y = 4;
    
    filter([&](int x) {
        return x > y;
    }, v2);

    return 0;
}



















