#include <iostream>
#include <algorithm>
#include <vector>

#include <queue>
#define inf 1e15


// 1162 using dijkstra

using namespace std;
long long dist[10001][21]; // [number of city][number of paving]

long long n, m, k;

struct s {
    long long dist;
    long long city;
    long long chance;
    s(long long a, long long b, long long c) : dist(a), city(b), chance(c) {}
    bool operator<(const s &s2) const {
        return dist < s2.dist;
    }
};




vector<vector<pair<long long, long long>>> v(10001);

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (long long i = 0 ; i < m ; i++) {
        long long from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back(make_pair(to, cost));
        v[to].push_back(make_pair(from, cost));
    }
    for (long long i = 1; i <= n ; i++) {
        for (long long j = 0 ; j <= k ; j++) {
            dist[i][j] = inf;
        }
    }
    priority_queue<s> q;
    q.emplace(0, 1, 0);
    dist[1][0] = 0;
    while(!q.empty()) {
        auto p = q.top();
        long long cur = p.city;
        long long cur_dist = p.dist *-1;
        long long cur_chance = p.chance;
        q.pop();
        for (long long i = 0 ; i < v[cur].size() ; i++) {
            long long next = v[cur][i].first;
            long long cost = v[cur][i].second;
            if (dist[next][cur_chance] > dist[cur][cur_chance] + cost) {
                dist[next][cur_chance] = dist[cur][cur_chance] + cost;
                q.emplace(-dist[next][cur_chance], next, cur_chance);
            }
            if (cur_chance < k) {
                if (dist[next][cur_chance+1] > dist[cur][cur_chance]) {
                    dist[next][cur_chance+1] = dist[cur][cur_chance];
                    q.emplace(-dist[next][cur_chance+1], next, cur_chance+1);
                }
            }
        }
    }
    long long ans = inf;
    for (int i = 1 ; i <= k ; i++) {
        ans = min(ans, dist[n][i]);
    }
    cout << ans << '\n';

















  return 0;
}
