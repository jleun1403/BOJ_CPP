#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    bool ok= false;
    string a, b;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] != ' ' && ok == false){
            a += s[i];
        }
        else if(s[i] == ' ') ok = true;
        else if(s[i] != ' ' && ok == true){
            b += s[i];
        }
    }
    
    int answer = max(stoi(a), stoi(b));
    cout << answer << '\n';
    return 0;
}