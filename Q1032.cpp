#include <bits/stdc++.h>
using namespace std;
char a[51][51];
int main(){
    int n;
    cin >> n;
    string s;
    string answer="";
    int length = 0;
    for(int i=0; i<n; i++){
        cin >> s;
        length = s.size();
        for(int j=0; j<s.size(); j++){
            a[i][j] = s[j];
        }
    }
    for(int i=0; i<length; i++){
        bool ok = false;
        for(int j=0; j<n-1; j++){
            if(a[j][i] != a[j+1][i]){
                ok = true;
                break;
            }
            else continue;
        }
        if(ok == true){
           answer+='?';
        }
        else answer += a[0][i];
    }
    //cout << length << '\n';
    int alen = answer.size();
    for(int i=0; i<length-alen; i++){
        answer += '?';
    }
        cout << answer << '\n';
        return 0;
}