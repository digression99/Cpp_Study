//
// string tokenizing.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

int main() {
//    vector<int> v1 = {1, 2, 3};
//    vector<int> v2;
//
//    v2.resize(3);
//    copy(v1.begin(), v1.end(), v2.begin());
//
//    for_each(v2.begin(), v2.end(), [](int d) {
//        cout << d << endl;
//    });
    
//    string str = "and I,feel fine...";
//    istringstream iss(str);
//    //copy(istream_iterator<string>(iss), istream_iterator<string>(), ostream_iterator<string>(cout, "\n"));
//
//    vector<string> tokens;
//    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
//    for (auto dat : tokens) cout << dat << endl;
//
//    vector<string> tokens2{istream_iterator<string>{iss}, istream_iterator<string>{}};
//    for(auto dat : tokens2) cout << dat << endl;
    
    vector<string> tokens;
    istringstream iss("denmark.sweden;india;us");
    string s;
    while (getline(iss, s, ';')) {
        //cout << s << endl;
        tokens.push_back(s);
    }
    
    for (auto dat : tokens) cout << dat << endl;
    
    
    
    return 0;
}

