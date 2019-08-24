#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>
#define inf 490000

using namespace std;
vector<vector<int>> v;
int n, m;
int start, finish;
int dist[500];

vector<int> adj;
void Rem();

void dijkstra1(int x) {
    fill(dist, dist+500, inf);

    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));
    dist[x] = 0;
    while(!q.empty()) {
        auto p = q.top();
        int cur_dist = p.first*-1;
        int cur = p.second;
        q.pop();
        for (int i = 0 ; i < n ; i++) {
            if (v[cur][i] > 0) {
                int next = i;
                int cost = v[cur][i];
                if (dist[next] > cur_dist + cost) {
                    dist[next] = cur_dist + cost;
                    q.push({dist[next]*-1, next});

                }
            }
        }
    }

    if (dist[finish] == inf)
        return;
    Rem();
}
void Rem() {
    queue<int> q;
    q.push(finish);
    while(!q.empty()) {
        int j = q.front();
        q.pop();
        for (int i = 0 ; i < n; i++) {
            if (v[i][j] > 0 && dist[j] == dist[i] + v[i][j]) {
                v[i][j] = inf;
                q.push(i);
            }
        }
    }
}

void dijkstra2(int x) {
    fill(dist, dist+500, inf);
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));
    dist[x] = 0;
    while(!q.empty()) {
        auto p = q.top();
        int cur_dist = p.first*-1;
        int cur = p.second;
        q.pop();
        for (int i = 0 ; i < n ; i++) {
            if (v[cur][i] > 0) {
                int next = i;
                int cost = v[cur][i];
                if (dist[next] > cur_dist + cost) {
                    dist[next] = cur_dist + cost;
                    q.push({dist[next]*-1, next});
                }
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    while(true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            return 0;
        v.resize(n, vector<int> (n, 0));
        cin >> start >> finish;
        for (int i = 0 ; i < m ; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            v[from][to] = cost;
        }
        int ans = 0;
        dijkstra1(start);

        if (dist[finish] == inf) {
            printf("-1\n");
            continue;
        }
        ans = dist[finish];

        dijkstra2(start);

        if (dist[finish] >= inf) {
            printf("-1\n");
        }
        else{
            printf("%d\n", dist[finish]);
        }
        v.clear();
        adj.clear();
    }
    return 0;
}
