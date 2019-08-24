#include <bits/stdc++.h>
using namespace std;

int main(){
    int answer = 0;
    string s;
    bool ok;
    bool found = false;
    for(int i=1; i<=5; i++){
        ok = false;
        cin >> s;
        for(int j=0; j<s.size()-2; j++){
            if(s[j] == 'F' && s[j+1] == 'B' && s[j+2] == 'I') {
                found = true;
                ok = true;
                break;
            }
        }
        if(ok == true) printf("%d ", i);
    }
    if(found == false) printf("HE GOT AWAY!\n");
    return 0;
}