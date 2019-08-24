#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string answer = "";
    for(int i=0; i<s.size(); i++){
        if(s[i]>='D'){
            s[i]-=3;
            answer += s[i];
        }
        else {
            s[i]+=23;
            answer +=s[i];
        }
    }
    cout << answer << '\n';
    return 0;
}