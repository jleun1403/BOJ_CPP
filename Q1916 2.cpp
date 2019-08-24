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



int main() {
    scanf("%d %d", &n, &m);
    vector<vector<pair<int, int>>> v;
    v.resize(n+1);
    for (int i = 0 ; i < m ; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        v[from].push_back(make_pair(to, weight));
    }
    int start, end;
    scanf("%d %d", &start, &end);
    for (int i = 1 ; i <= n ; i++)
        dist[i] = inf;
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
    cout << dist[end];









  return 0;
}
