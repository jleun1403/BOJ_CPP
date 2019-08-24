#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string answer;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'C'|| s[i] == 'A' || s[i] == 'M'|| s[i] == 'B'|| s[i] =='R' || s[i] == 'I' || s[i] =='D' || s[i] == 'G' || s[i] == 'E') continue;
        else answer +=s[i];
    }
    cout << answer << '\n';
    return 0;
}