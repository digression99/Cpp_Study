//
// implement an algorithm to determine if a string has all unique characters.
// what if you cannot use additional data structures?
//
//
// (1) 다른 배열을 선언할 수 있는 경우
// 중복 문자를 담을 배열을 a부터 z까지 26개 방을 가진 배열을 선언하고 0으로 초기화한다.
// for문을 돌면서 배열에 숫자를 하나씩 증가시킨다. 이미 숫자가 1인 방이 있으면 not unique.
//
// *** 근데 character가 꼭 소문자를 의미하는 건 아니잖아...
//
// (2) 다른 배열을 선언할 수 없는 경우
// hash값을 이용한다. -> hash함수를 개발하여 a -> z까지 있다면 그 방을 참조하는 함수를 짠다.
//
//
//
//
//


#include <iostream>
using namespace std;

void solA()
{
    string str;
    bool isChecked = false;
    
    cin >> str;
    
    for (int i = 0; i < str.size() - 1; ++i)
    {
        for (int j = i + 1; j < str.size(); ++j)
        {
            if (str[i] == str[j])
            {
                cout << "not unique!" << endl;
                isChecked = true;
                break;
            }
        }
        if (isChecked) break;
    }
    
    if (!isChecked)
        cout << "unique!" << endl;
}

bool solB()
{
    string str;
    int cArr[26] = { 0, };// 이걸 그냥 bool로 사용할 수도 있다.
    
    cin >> str;
    
    for (int i = 0; i < str.size(); ++i)
    {
        if (cArr[str[i] - 'a']++ == 1)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    
    return 0;
}
