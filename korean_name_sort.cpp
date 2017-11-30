#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    // 한글로 받은 이름을 소트한다.
    vector<string> strArr;
    ifstream ifs("./names.txt");
    int count;
    
    ifs >> count;
    
    for (int i = 0; i < count; ++i) {
        string temp;
        ifs >> temp;
        strArr.push_back(temp);
    }
    sort(strArr.begin(), strArr.end(), less<string>());
    
    for (int i = 0; i < strArr.size(); ++i)
        cout << strArr[i] << endl;
    
    ifs.close();
    
    return 0;
}
