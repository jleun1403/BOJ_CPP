#include <bits/stdc++.h>
using namespace std;
vector<int> v[501];
int d[501];
int main(){
    int n, m;
    cin >> n>> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue <int> q;
    q.push(1);
    d[1] = 1;
    while(!q.empty()){
       int now= q.front(); 
       q.pop();
       for(int i=0; i<v[now].size(); i++){
           int y = v[now][i];
           if(d[y] == 0){
               d[y] = d[now] + 1;
               q.push(y);
           }
       }
    }
    int answer= 0;
    for(int i=1; i<=n; i++){
        if(d[i] ==2 || d[i] == 3){
            //cout << i << ' ';
            answer +=1;
        }
    }
    cout << answer << '\n';
    return 0;
}