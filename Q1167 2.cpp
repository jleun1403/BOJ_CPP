#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int>> v[100001];
int d[100001];
queue<int> q;
void bfs(int start){
    memset(d, 0, sizeof(d));
    q.push(start);
    d[start] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++){
            int to = v[x][i].first;
            int cost = v[x][i].second;
            if ( d[to] == 0){
            d[to] =d[x] + cost;
            q.push(to);
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    int answer = 0;
    for(int i=1; i<=n; i++){
        int x;
        scanf("%d", &x);
        while(true){
            int a, b;
            scanf("%d", &a);
            if(a == -1) break;
            scanf("%d", &b);
            v[x].push_back(make_pair(a,b));
        }
    }
    bfs(1);
    int start = 1;
    for(int i=2; i<=n; i++){
        if(d[i] > d[start]) start = i;
    }
    bfs(start);
    for(int i=1; i<=n; i++){
        if(i == start) continue;
        else answer= max(answer, d[i]);
    }
    printf("%d\n", answer);
    return 0;
}