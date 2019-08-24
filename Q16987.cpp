#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int>> v;
int n;
int answer;
void solve(int cur, int cnt){
    if(cur == n) {
        answer = max(answer, cnt);
        return ;
    }
    if(v[cur].first <=0) return solve(cur+1, cnt);
    for(int i=0; i<n; i++){
        if(cur == i || v[i].first <=0) continue;
        v[cur].first -= v[i].second;
        v[i].first -= v[cur].second;
        int t = 0;
        if(v[cur].first <=0) t+=1;
        if(v[i].first <=0) t+=1;
        solve(cur+1, cnt +t);
        v[cur].first += v[i].second;
        v[i].first += v[cur].second;
    }
     answer = max(answer, cnt);
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    solve (0,0);
    cout << answer << '\n';
}