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
int dist[202];
int cost[202][202];
int cap[202][202];
int flow[202][202];
int pre[202];
bool inque[202];
vector<vector<int>> v(202);
const int source = 0;
const int drain = 201;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i<= n ;i++){
        scanf("%d", &cap[i+100][drain]);
        v[i+100].push_back(drain);
        v[drain].push_back(i+100);
    }
    for (int i = 1 ; i <= m ; i++) {
        scanf("%d", &cap[source][i]);
        v[source].push_back(i);
        v[i].push_back(source);
    }
    for (int i = 1 ; i <= m ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            scanf("%d", &cap[i][j+100]);
            v[i].push_back(j+100);
            v[j+100].push_back(i);
        }
    }
    for (int i = 1; i <= m ; i++) {
        for (int j = 1; j <= n ; j++) {
            scanf("%d", &cost[i][j+100]);
            cost[j+100][i] = -cost[i][j+100];
        }
    }

    // SPFA
    int ans = 0;
    int result = 0;
    while(true) {
        memset(pre, -1, sizeof(pre));
        fill(dist, dist +202, inf);
        memset(inque, false, sizeof(inque));
        queue<int> q;
        inque[source] = true;
        dist[source] = 0;
        q.push(source);
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
        for (int i = drain ; i != source ; i = pre[i]) {
            f = min(f, cap[pre[i]][i] - flow[pre[i]][i]);
        }
        for (int i = drain ; i != source ; i = pre[i]) {
            result += f*cost[pre[i]][i];
            flow[pre[i]][i] += f;
            flow[i][pre[i]] -= f;
        }
        ans += f;
    }
    printf("%d\n%d", ans, result);














  return 0;
}
