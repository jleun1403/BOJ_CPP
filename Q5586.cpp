#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int num1 = 0, num2= 0;
    for(int i=0; i<s.size()-2; i++){
        if(s[i] == 'J'){
            if(s[i+1] == 'O' && s[i+2] == 'I') num1 +=1;
        }
        else if(s[i] == 'I'){
            if(s[i+1] == 'O' && s[i+2] == 'I') num2+=1;
        }
    }
    cout <<num1 << '\n';
    cout << num2 << '\n';
    return 0;
}