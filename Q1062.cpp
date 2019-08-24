#include <bits/stdc++.h>
using namespace std;
string s [51];
bool check[27];
bool temp[27];
int n, m;
int answer;
vector <int> v;
void solve(){
    int cnt = 0;
    for(int i=0; i<n; i++){
        bool ok = false;
        for(int j=4; j<s[i].size()-4; j++){
            if(check[s[i][j]-'a'] == true) continue;
            else {
                ok = true;
                break;
            }
        }
        if(ok == false) cnt+=1;
    }
    answer= max(answer, cnt);
}
/*void go(int num){
    if(v.size() ==  m){
        solve();
        return;
    }
    for(int i=0; i<26; i++){
        v.push_back(num);
        go(num+1);
        v.pop_back();
    }
   
}*/
int main(){
    cin >> n>> m;
    int cnt = 0;
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=4; j<s[i].size()-4; j++){
            temp[s[i][j]-'a'] = true;
        }
    }
    for(int i=0; i<26; i++){
        if(temp[i] == true) cnt+=1;
    }
    for(int i=0; i<m; i++){
        v.push_back(1);
    }
    for(int i=0; i<cnt-m; i++){
        v.push_back(0);
    }
    sort(v.begin(), v.end());
    do{
        memset(check, false, sizeof(check));
        for(int i=0; i<v.size(); i++){
            if(v[i] == 1 && temp[i] == true){
                check[i] = true;
            }
        }
        solve();
    }while(next_permutation(v.begin(), v.end()));
    cout << answer << '\n';
    return 0;
}