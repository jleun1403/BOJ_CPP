#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

struct edge {
    int start;
    int finish;
    int cost;
    int dist;
    edge(int a, int b, int c, int d) : start(a), finish(b), cost(c), dist(d) {};
    edge() : start(0), finish(0), cost(0), dist(0) {};
};
int testcase;
bool canGo[101][101];
int dist[101];
int cost[101];
int n, m, k;
int ans;
vector<vector<edge>> v;

void dijkstra(int x){
    priority_queue<pair<int , int >> q;
    q.push(make_pair(0, 1));
    while(!q.empty()) {
        auto p = q.top();
        q.pop();
        p.second = cur;
        if (cur == n) {
            ans = p.first;
            return;
        }
        for (int i = 0 ; i < v[cur].size() ; i++) {
            auto t = v[cur][i];
            if (cost[cur] + t.cost <= m) {
                canGo[cur][t] = true;
            }
        }
    }
}


int main() {
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d %d", &n, &m, &k);
        v.resize(n+1);
        ans = inf;
        for (int j = 0 ; j < k ; j++) {
            int start, finish, cost, dist;
            scanf("%d %d %d %d", &start, &finish, &cost, &dist);
            v[start].push_back(edge(start, finish, cost, dist));
        }
        visited[1] = true;
        DFS(1);
        if (ans == inf) {
            printf("Poor KCM\n");
        }
        else printf("%d\n", ans);
        v.clear();
    }
















  return 0;
}
