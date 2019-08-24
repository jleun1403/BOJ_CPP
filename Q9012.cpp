#include <stack>
#include <iostream>

using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int temp = 0;
        string s;
        cin >>s;
        if (s[0] == ')'){
            cout <<"NO"<<'\n';
            continue;
        }
        for (int i = 0 ; i < s.length() ; i++){
            if (s[i] == '(')
                temp++;
            else
                temp--;
            if (temp < 0) {
                break;
            }
        }
        if (temp == 0)
            cout <<"YES"<<'\n';
        else
            cout <<"NO"<<'\n';
    }

}
