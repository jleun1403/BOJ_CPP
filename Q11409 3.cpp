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
const int source = 0;
const int drain = 801;
int dist[802];
int cap[802][802];
int flow[802][802];
int cost[802][802];
bool inque[802];
int pre[802];
vector<vector<int>> v(802);

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        int number;
        scanf("%d", &number);
        for (int j = 0 ; j < number ; j++) {
            int job, wage;
            scanf("%d %d", &job, &wage);
            job += 400;
            cap[i][job] = 1;
            v[i].push_back(job);
            v[job].push_back(i);
            cost[i][job] = -wage;
            cost[job][i] = wage;
        }
    }
    for (int i = 1 ; i<= n ; i++) {
        cap[source][i] = 1;
        v[source].push_back(i);
        v[i].push_back(source);
    }
    for (int j = 401 ; j <= 400+m ; j++) {
        cap[j][drain] = 1;
        v[drain].push_back(j);
        v[j].push_back(drain);
    }
    int ans = 0;
    int result = 0;
    while(true) {
        memset(inque, false, sizeof(inque));
        fill(dist, dist+802, inf);
        memset(pre, -1, sizeof(pre));
        dist[0] = 0;
        inque[0] = true;
        queue<int> q;
        q.push(0);
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
                        q.push(next);
                        inque[next] = true;
                    }
                }
            }
        }
        if (pre[drain] == -1)
            break;
        int f = inf;
        for (int i = drain;  i!= source ; i = pre[i])
            f = min(f, cap[pre[i]][i] - flow[pre[i]][i]);
        for (int i = drain ; i != source ; i = pre[i]) {
            result += -f*cost[pre[i]][i];
            flow[pre[i]][i] += f;
            flow[i][pre[i]] -= f;
        }
        ans++;
    }

    printf("%d\n%d", ans, result);














  return 0;
}
