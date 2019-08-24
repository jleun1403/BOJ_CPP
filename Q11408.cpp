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
int cost[802][802];
int cap[802][802];
int flow[802][802];
int pre[802];
bool inque[802];
int dist[802];
vector<vector<int>> v(802);
const int source = 0;
const int drain = 801;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i++) {
        int number;
        scanf("%d", &number);
        for (int j = 0 ; j < number ; j++) {
            int job, money;
            scanf("%d %d", &job, &money);
            job += 400;
            cap[i][job] = 1;
            cost[i][job] = money;
            cost[job][i] = -money;
            v[i].push_back(job);
            v[job].push_back(i);
        }
        cap[source][i] = 1;
        v[i].push_back(source);
        v[source].push_back(i);
    }
    for (int i = 1 ; i <= m ; i++){
        int job = i + 400;
        cap[job][drain] = 1;
        v[job].push_back(drain);
        v[drain].push_back(job);
    }

    int ans = 0;
    int result = 0;
    while(true) {
        memset(pre, -1, sizeof(pre));
        memset(inque, false, sizeof(inque));
        fill(dist, dist+802, inf);
        queue<int> q;
        q.push(source);
        inque[source] = true;
        dist[source] = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            inque[cur] = false;
            for (int i = 0 ; i < v[cur].size() ; i++) {
                int next = v[cur][i];
                if (dist[next] > dist[cur] + cost[cur][next] && cap[cur][next] > flow[cur][next]) {
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
            flow[pre[i]][i] += f;
            flow[i][pre[i]] -= f;
            result += 1*cost[pre[i]][i];
        }
        ans += f;
    }
    printf("%d\n%d", ans, result);














  return 0;
}
