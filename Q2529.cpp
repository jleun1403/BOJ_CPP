#include <bits/stdc++.h>
using namespace std;
int n;
char a[10];
string maxnum, minnum;
bool c[10];
bool possible(int i, int j, char k){
    if(k == '<') return i<j;
    else if (k == '>') return i>j;
    return true;
}
void solve(int cnt, string s){
    if(cnt == n+1){
        if(minnum.size()!=0){
            minnum = s;
        }
        else maxnum = s;
        return ;
    }
    for( int i=0; i<10; i++){
        if(c[i]) continue;
        if(cnt ==0 || possible(s[cnt-1], i-'0', a[cnt-1])){
            c[i] = true;
            solve(cnt+1, s+to_string(i));
            c[i] = false;
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        scanf(" %c", &a[i]);
    }
    solve(0, "");
    cout << maxnum << '\n';
    cout << minnum << '\n';
    return 0;
}