
#include <iostream>
using namespace std;
#include <cassert>

void printNumber(int * p)
{
    assert(p != nullptr);
    cout << *p << endl;
}

int main()
{
    cin.sync_with_stdio(false);
    
    int a = 10;
    
    int * b = nullptr;
    int * c = nullptr;
    
    b = &a;
    
    printNumber(b);
    printNumber(c);
    
    return 0;
}
