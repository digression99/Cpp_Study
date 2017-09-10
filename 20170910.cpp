#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <list>
#include <forward_list>
using namespace std;

void performOperation(std::function<void()> f) {
    int x = 200;
    f();
}

int main()
{
    srand((unsigned)time(nullptr));
    auto f = [](int a, int b) -> int { return a + b; }; // -> int : explicit.
    auto f2 = [](int a, int b) {return a + b; }; // implicit.
    //auto f2 = [] { return "Hello, lambda!"; };
    
    cout << f(10, 20) << endl;
    cout << []{return "hello, lambda!";}() << endl;
    cout << f2(30, 40) << endl;
    
    int i = 10;
    int g = 11;
    auto captureTest = [i, g](int a, int b) -> int {return (a + b) * i + g;}; // i, g is read only.
    auto captureTest2 = [&i, &g](int a, int b) -> int {
        i = 89;
        g += 20;
        return (a + b) * i + g;
    }; // i, g can be changed.
    auto captureTest3 = [=](int a, int b) -> int { // = : capture automatically.
        return (a - b) - i + g;
    };
    
    auto captureTest4 = [&](int a, int b) -> int { // & : capture by reference. can be changed.
        i = 89;
        g = 20;
        return (a - b) - i + g;
    };
    auto captureTest5 = [=, &i](int a, int b) -> int { // for stability.
        i = 89;
        //g = 20; // can't change.
        return (a - b) - i + g;
    };
    
    
    cout << captureTest2(10, 20) << endl;
    cout << "i : " << i << endl;
    cout << "g : " << g << endl;
    
    cout << captureTest2(30, 40) << endl;
    cout << captureTest3(30, 40) << endl;
    cout << captureTest4(30, 20) << endl;
    cout << captureTest5(34, 21) << endl;
    
    vector<int> arr = {1, 2, 3, 4, 5};
    double total = 0;
    
    for_each(begin(arr), end(arr), [&](int x) { total += x; });
    for_each(arr.begin(), arr.end(), [&](int x) {total += x; });
    //for_each(begin(arr), end(arr), plus<int>());
    
    cout << "Sum is : " << total << endl;
    
    class Point {
    public:
        int x, y;
        Point() {
            x = rand() % 10000 + 5000;
            y = rand() % 10000 + 5000;
        }
        void print() {
            cout << "X : " << x << " Y : " << y << endl;
        }
    };
    
    int count = 100;
    vector<Point> points;
    for (int i = 0; i < count; ++i) points.push_back(Point()); // use Constructor directly.
    
    cout << "Unsorted : " << endl;
    for (int i = 0; i < count; ++i) points[i].print();
    
    sort(points.begin(), points.end(), [](const Point & a, const Point & b) -> bool {
        return (a.x * a.x) + (a.y * a.y) < (b.x * b.x) + (b.y * b.y);
    });
    
    cout << "Sorted : " << endl;
    
    for (int i = 0; i < count; ++i) points[i].print();
    
    // using vector.
    vector<int> nums;
    for (int i = 0; i < 10; ++i) nums.push_back(rand() % 1000 + 1);
    
    for (int i = 0; i < 10; ++i) cout << nums[i] << " ";
    cout << endl;
    //sort(nums.begin(), nums.end(), greater<int>());
    sort(nums.begin(), nums.end(), less<int>());
    
    for (int i = 0; i < 10; ++i) cout << nums[i] << " ";
    
    //
    
    int x = 100;
    auto func = [&]() { x++; };
    
    performOperation(func);
    cout << "X : " << x << endl;
    
    // remove, replace
    
    vector<int> test = {10, 20, 30, 30, 20, 10, 30, 10, 90, 80};
    
    remove(test.begin(), test.end(), 30);
    
    for_each(test.begin(), test.end(), [](int x) {cout << x << endl;});
    
    replace(test.begin(), test.end(), 90, 80);
    
    for_each(test.begin(), test.end(), [](int x) {cout << x << endl;});
    
    // lists vs vectors
    
    vector<double> v = {1.1, 2.2, 3.3, 4.4, 5.5};
    double * d = v.data();
    
    //for (int i = 0 ;i < v.size(); ++i) cout << *d++ << endl;
    //while (d != v.end()) cout << *d++ << endl;
    
    for_each(v.begin(), v.end(), [](double x){cout << x << endl;});
    
    // size vs capacity -> size 는 벡터의 아이템의 개수. capacity 는 미리 많이 할당해놓은 진짜 사이즈.
    // v.shrink_to_fit() -> cap를 size와 맞춤.
    // v.clear() -> size만 0로.
    
    cout << "List " << endl;
    
    list<double> l = {1.1, 2.2, 3.3, 4.4, 5.5};
    l.push_back(6);
    l.push_front(0.5);
    
    for_each(begin(l), end(l), [](double x) {cout << x << endl;});
    
    cout << "after pop : " << endl;
    
    l.pop_back();
    l.pop_front();
    
    for_each(begin(l), end(l), [](double x) {cout << x << endl;});
    
    double & tt = l.front();
    
    tt += 10;

    cout << l.front() << endl; // data's reference.
    cout << l.back() << endl;
    
    // l[2]; // array operator로 접근 안된다.
    
    for(auto i = l.rbegin(); i != l.rend(); ++i) cout << *i << endl; // ++ 이다. --가 아니다.
    
    // l.clear();
    
    l.reverse(); // 리스트가 뒤집어짐.
    l.sort(); // 리스트를 소팅함.
    
    for_each(begin(l), end(l), [](double x) {cout << x << endl;});
    
    forward_list<int> fl = {1, 2, 3, 4, 5}; // this is singly linked list.
    
    for_each(begin(fl), end(fl), [](int x) {cout<<x<<endl;});
    // not backward.
    
    int testAss = 0;
    //asm("mov testAss, 100");
    
    
    cout << testAss << endl;
    
    
    
    
    
    
    
    
    
    
    return 0;
}
