#include <bits/stdc++.h>
using namespace std;
int d[1001];
int n, m ,k;
vector <pair<int,int>> v[1001];
int go(int start, int end){
    int dist[1001];
    for(int i=1; i<=n; i++){
        dist[i] = 987654321;
    }
    dist[start] = 0;
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,start));
    while(!q.empty()){
        int x = q.top().second;
        int y = -q.top().first;
        q.pop();
        for(int i=0; i<v[x].size(); i++){
            int nx = v[x][i].first;
            int ny = v[x][i].second;
            if(dist[nx]> y + ny) {
                dist[nx] = y + ny;
                q.push(make_pair(-(y + ny), nx));
            }
        }
    }
    return dist[end];
}
int main(){
   
    cin >> n>> m>> k;
    for(int i=0; i<m; i++){
        int a, b,c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
    }
    for(int i=1; i<=n; i++){
        d[i] = go(i,k) + go(k,i);
    }
    int maxnum = 0;
    for(int i = 1; i<=n; i++){
        maxnum = max(maxnum, d[i]);
    }
    cout << maxnum << '\n';
    return 0;
}