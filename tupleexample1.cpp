//
// tuple example
//
//
//

#include <tuple>
#include <iostream>
using namespace std;

typedef tuple<int, double, string> ids;

int main()
{
    ids a(5, 10.0, "myTuple");
    
    ids b(a);

    ids c = make_tuple(3, 6.5, "myTuple2");
    
    int first;
    double second;
    
    tie(first, second, ignore) = c;
    
    
    cout << get<0>(b) << endl;
    cout << get<1>(b) << endl;
    cout << get<2>(b) << endl;
    
    cout << (tie(a) < tie(c) ? "a win" : "b win") << endl;
    
    
    
    
    return 0;
}
