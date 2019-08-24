#include <bits/stdc++.h>
using namespace std;
string s [51];
bool a[26];
bool check[26];
int n, m;
int answer;
vector<pair<int ,char>> v;
vector <int> op;
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
        if(ok == false) cnt +=1;
    }
    answer = max(answer, cnt);
}
int main(){
    cin >> n >> m;
    int cnt=0;
    for(int i=0; i<n; i++){
        cin >> s[i] ;
        for(int j=4; j<s[i].size()-4; j++){
            if(a[s[i][j]-'a'] == false){
                a[s[i][j]-'a'] = true;
                v.push_back(make_pair(cnt++,s[i][j]));
            }
        }
    }
    for(int i=0; i<m; i++) op.push_back(1);
    for(int i=0; i<v.size()-m; i++) op.push_back(0);
    sort(op.begin(), op.end());
    do{
        memset(check, false, sizeof(check));
        for(int i=0; i<op.size(); i++){
            if(op[i] == 1) check[v[i].second-'a'] = true;
        }
        solve();
    }while(next_permutation(op.begin(), op.end()));
    cout << answer << '\n';
    return 0;

}