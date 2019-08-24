#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, cnt,answer;
    cin >> t;
    string s;
    while(t--){
        answer = 0;
        cnt =0;
        cin >> s;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'O'){
                cnt+=1;
                answer +=cnt;
            }
            else{
                cnt =0;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}