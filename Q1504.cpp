#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>
#define inf 1000000000

using namespace std;
int n, m;
int c[1001];
int dist[1001];
vector<vector<pair<int, int>>> v;

int dijkstra(int start, int to) {
    dist[start] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));
    while(!q.empty()) {
        auto p = q.top();
        q.pop();
        if (c[p.second] == 1)
            continue;
        c[p.second] = 1;
        for (int i = 0 ; i < v[p.second].size() ; i++) {
            int next = v[p.second][i].first;
            int d = v[p.second][i].second;
            if (dist[next] > dist[p.second] + d) {
                dist[next] = dist[p.second] + d;
                q.push(make_pair(dist[next]*-1, next));
            }
        }
    }
    int x = dist[to];
    for (int i = 1 ; i <= n ; i++)
        dist[i] = inf;
    memset(c, 0, sizeof(c));
    return x;
}



int main() {
    scanf("%d %d", &n, &m);
    v.resize(n+1);
    for (int i = 0 ; i < m ; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        v[from].push_back(make_pair(to, weight));
        v[to].push_back(make_pair(from, weight));
    }
    int p1, p2;
    scanf("%d %d", &p1, &p2);
    for (int i = 1 ; i <= n ; i++)
        dist[i] = inf;
    int ans11 = dijkstra(1, p1);
    int ans12 = dijkstra(p1, p2);
    int ans13 = dijkstra(p2, n);
    int ans21 = dijkstra(1, p2);
    int ans22 = dijkstra(p2, p1);
    int ans23 = dijkstra(p1, n);
    long long a1 = (long long)ans11 + ans12 + ans13;
    long long a2 = (long long)ans21 + ans22 + ans23;
    if (min (a1, a2) > inf)
        printf("-1");
    else
        printf("%lld", min(a1, a2));







  return 0;
}
