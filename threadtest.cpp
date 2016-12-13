#include <iostream>
#include <thread>
#include <string>
using namespace std;

class MyPrint
{
public:
    MyPrint(const std::string & text)
    {
        myWord = text;
    }
    void operator()(const std::string & szText) const
    {
        cout << myWord << endl;
        cout << szText << endl;
    }
    void printFunc() const
    {
        cout << myWord << endl;
    }
private:
    string myWord;
};

void threadFunc(int nVal)
{
    cout << "nVal : " << nVal << endl;
}

int main()
{
//    thread th1(threadFunc, 100);
//    th1.join();
    
    auto th1 = std::thread(MyPrint("Hello, world!"), "Bye World!");
    th1.join();
    
    MyPrint c("c++11 thread");
    
    auto th2 = std::thread(&MyPrint::printFunc, c);
    th2.join();
    
    return 0;
}
