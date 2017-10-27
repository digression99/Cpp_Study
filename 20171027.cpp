/*
 - what containers can be dealt with for_each and lambda function?
 -> vector for sure. how about maps?
 
 
 
 
 
 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <set>
#include <string>
#include <functional>
using namespace std;

void func(int dat) {
    //cout << "normal function!" << endl;
    cout << dat << " " << endl;
}

class BigObject {
public:
    string id;
    explicit BigObject(const string& s) : id(s) {}
    bool operator< (const BigObject& other) const
    {
        return this->id < other.id;
    }
    
    // Other members....
};

inline bool operator<(const string& otherId, const BigObject& obj)
{
    return otherId < obj.id;
}

inline bool operator<(const BigObject& obj, const string& otherId)
{
    return obj.id < otherId;
}


//Output: myNewSet element = 62F



int main() {
    
    cout << "vector." << endl;
    
    vector<int> v;
    
    v.push_back(10);
    v.push_back(200);
    v.push_back(3);
    
    // using normal function.
    for_each(v.begin(), v.end(), func);
    
    // using lambda function.
    for_each(v.begin(), v.end(), [](int dat) {
        //cout << "lambda function!" << endl;
        cout << dat << " " << endl;
    });
    
    cout << "unordered_map." << endl;
    
    unordered_map<int, int> hash;
    
    hash[3] = 10;
    hash[10] = 20;
    hash[23] = 31;
    
    for_each(hash.begin(), hash.end(), [](pair<int, int> dat) { // you can't use reference here. (pair<int, int> & dat) { ...
        cout << dat.first << " " << dat.second << endl;
    });
    
    cout << "unordered_set." << endl;
    
    unordered_set<int> set;
    
    set.insert(10);
    set.insert(31);
    set.insert(98);
    
    for_each(set.begin(), set.end(), [](int dat) {
        cout << dat << " " << endl;
    });
    
    
    cout << "list. " << endl;
    
    list<int> lis;
    
    lis.push_back(10);
    lis.push_front(20);
    lis.push_back(13);
    lis.push_front(245);
    
    for_each(lis.begin(), lis.end(), [](int dat) {
        cout << dat << " " << endl;
    });
    
    // Use C++14 brace-init syntax to invoke BigObject(string).
    // The s suffix invokes string ctor. It is a C++14 user-defined
    // literal defined in <string>
    BigObject b1{"42F"};//b1{ "42F"s };
    BigObject b2{ "52F" };
    BigObject b3{ "62F" };
    
    std::set<BigObject, less<BigObject> > myNewSet; // C++14 // why should I put std in front of the def?
    
    myNewSet.insert(b1);
    myNewSet.insert(b2);
    myNewSet.insert(b3);
    
    BigObject b4{"62F"};
    
    auto it = myNewSet.find(b4);//string("62F"));
    if (it != myNewSet.end())
        cout << "myNewSet element = " << it->id << endl;
    else
        cout << "element not found " << endl;
    
    // Keep console open in debug mode:
    cout << endl << "Press Enter to exit.";
    string s;
    getline(cin, s);
    
    
    return 0;
}
