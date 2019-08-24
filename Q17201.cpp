#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = false;
    for(int i=0; i<s.size()-1; i++){
        if(s[i] == '1' && s[i+1] == '2') continue;
        else if ( s[i]=='2' && s[i+1] == '1') continue;
        else {
            ok = true;
            break;
        }
    }
    if(ok == true) printf("No\n");
    else printf("Yes\n");
    return 0;
}
