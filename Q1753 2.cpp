#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int to;
    int cost;
};
int dist[20001];
bool check[20001];
int MAX = 987654321;
vector <Edge> v[20001];
int main(){
    int n, m;
    cin >> n>> m;
    int start;
    cin >> start;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Edge e;
        e.to = b;
        e.cost = c;
        v[a].push_back(e);
    }
    for(int i=1; i<=n; i++){
        dist[i] = MAX;
    }
    dist[start] = 0;
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,start));
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        int x = p.second;
        if(check[x] == true) continue;
        for(int i=0; i<v[x].size(); i++){
            int y = v[x][i].to;
            if(dist[y] > dist[x] + v[x][i].cost){
                dist[y] = dist[x] + v[x][i].cost;
                q.push(make_pair(-dist[y], y));
            }
        }

    }
    for(int i=1; i<=n; i++){
        if(dist[i] >=MAX){
            printf("INF\n");
        }
        else
        {
            printf("%d\n", dist[i]);
        }
        
    }
    return 0;

}