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
#define inf 987654321

using namespace std;
int n, m;
// 0source 1~1000number 2001drain
// 1~1000 : incoming
// 1001 ~ 2000 : outgoing
const int source = 0;
const int drain = 2001;
int cost[2002][2002];
int flow[2002][2002];
int cap[2002][2002];
vector<vector<int>> v;
int pre[2002];
bool inque[2002];
int dist[2002];

int main() {

    while(scanf("%d %d", &n, &m) == 2) {
    v.resize(2002);
    memset(cost, 0, sizeof(cost));
    memset(flow, 0, sizeof(flow));
    memset(cap, 0, sizeof(cap));
    for (int k = 0 ; k < m ; k++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        v[from+1000].push_back(to);
        v[to].push_back(from+1000);
        cap[from+1000][to] = 1;
        cost[from+1000][to] = weight;
        cost[to][from+1000] = -weight;
    }

    for (int i = 1 ; i <= n ; i++) {
        v[i].push_back(i+1000);
        v[i+1000].push_back(i);
        cap[i][i+1000] = 1;
    }
    cap[1][1001] = 2;
    cap[n][n+1000] = 2;

    cap[source][1] = 2;
    v[source].push_back(1);
    v[1].push_back(source);
    cap[n+1000][drain] = 2;
    v[drain].push_back(n+1000);
    v[n+1000].push_back(drain);

    int ans = 0;
    while(true) {
        memset(pre, -1, sizeof(pre));
        memset(inque, false, sizeof(inque));
        fill(dist, dist+2002, inf);
        queue<int> q;
        q.push(source);
        dist[source] = 0;
        inque[source] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            inque[cur] = false;
            for (int i = 0 ; i < v[cur].size() ; i++) {
                int next = v[cur][i];
                if (cap[cur][next] > flow[cur][next] && dist[next] > dist[cur] + cost[cur][next]) {
                    dist[next] = dist[cur] + cost[cur][next];
                    pre[next] = cur;
                    if (inque[next] == false) {
                        inque[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        if (pre[drain] == -1)
            break;
        int f = inf;
        for (int i = drain ; i!= source ; i = pre[i]) {
            f= min(f, cap[pre[i]][i] - flow[pre[i]][i]);
        }
        for (int i = drain ; i != source ; i = pre[i]) {
            flow[pre[i]][i] += f;
            flow[i][pre[i]] -= f;
            ans += (cost[pre[i]][i] * f);
        }
    }
    printf("%d\n", ans);
    v.clear();
    }














  return 0;
}
