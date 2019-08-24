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
int n, m, start;
vector<vector<pair<int, int>>> v;
int dist[20001];
int c[20001];

int main() {
    scanf("%d %d %d", &n, &m, &start);
    v.resize(n+1);
    for (int i = 0 ; i < m ; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        v[from].push_back(make_pair(to, weight));
    }
    for (int i = 1 ; i <= n ;i++)
        dist[i] = inf;

    priority_queue<pair<int, int>> q;
    dist[start] = 0;
    q.push(make_pair(0, start));
    while(!q.empty()) {
        auto p = q.top();
        q.pop();
        if(c[p.second] == 1)
            continue;
        int cur = p.second;
        c[cur] = 1;
        for (int i = 0 ; i < v[cur].size() ; i++) {
            int next = v[cur][i].first;
            int d = v[cur][i].second;
            if (dist[next] > dist[cur] + d) {
                dist[next] = dist[cur] + d;
                q.push(make_pair(dist[next] * -1, next));
            }
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        if (dist[i] == inf)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }







  return 0;
}
