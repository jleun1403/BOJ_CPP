#include <bits/stdc++.h>
using namespace std;
int sum;
int main(){
    string s;
    cin >> s;
    int num = s.size();
    for(int i=0; i<s.size(); i++){
        if(s[i] >='A' && s[i] <='C') sum+=2;
        else if(s[i] >='D' && s[i] <='F') sum+=3;
        else if(s[i] >='G' && s[i] <='I') sum+=4;
        else if(s[i] >='J' && s[i] <='L') sum+=5;
        else if(s[i] >='M' && s[i] <='O') sum+=6;
        else if(s[i] >='P' && s[i] <='S') sum+=7;
        else if(s[i] >='T' && s[i] <='V') sum+=8;
        else if(s[i] >='W' && s[i] <='Z') sum+=9;
    }
    cout << sum+num << '\n';
    return 0;
}