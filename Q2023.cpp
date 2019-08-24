#include <bits/stdc++.h>
using namespace std;
int n;
bool isprime(int num){
    if (num==1) return false;
    for(int i=2; i*i<=num; i++){
        if(num % i ==0){
            return false;
        }
    }
    return true;
}
void dfs(string s, int cnt){
    if(cnt == n) {
        cout << s << '\n';
        return ;
    }
    for(int i=1; i<=9; i++){
        string temp = s+ to_string(i);
        if(isprime(stoi(temp)) == true){
            dfs(temp,cnt+1);
        }
    }
}
int main(){
    cin >> n;
    dfs("",0);
    return 0;
}