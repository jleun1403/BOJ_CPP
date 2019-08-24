#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, f;
    int answer = 0;
    getline(cin, s);
    getline(cin, f);
    int len = f.size();
    for(int i=0; i<s.size()-len+1; i++){
        string temp = s.substr(i,len);
        if(temp == f){
            answer+=1;
            i+=len-1;    
        }
    }
    cout << answer << '\n';
    return 0;
}