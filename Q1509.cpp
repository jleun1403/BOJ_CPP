#include <bits/stdc++.h>
using namespace std;
bool d[2501][2501];
int ans[2501];
int main(){
    string s;
    cin >> s;
    int n= s.size();
    s = " " +s;
    for(int i=1; i<=n; i++){
        d[i][i] = true;
    }
    for(int i=1; i<=n-1; i++){
        if(s[i] == s[i+1]) d[i][i+1] = true;
    }
    for(int k=2; k<n; k++){
        for(int i=1; i<=n-k; i++){
            int j = i+k;
            if(s[i] == s[j] && d[i+1][j-1]) d[i][j] = true;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(d[j][i] == true){
                if(ans[i] == 0 || ans[i] > ans[j-1] +1){
                    ans[i] = ans[j-1] +1;
                }
            }
        }
    }
    cout << ans[n] << '\n';
    return 0;
}