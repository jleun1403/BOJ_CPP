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
// 1 ~ 1000 : teams. 1001 = roomA. 1002 =roomB. 0 = source. 1003 = drain
const int source = 0;
const int drain = 1003;
vector<vector<int>> v;
int cap[1004][1004];
int flow[1004][1004];
int cost[1004][1004];
int pre[1004];
bool inque[1004];
int dist[1004];
int n, a, b;

int main() {
    while(true) {
        scanf("%d %d %d", &n, &a, &b);
        if (n == 0 && a== 0 && b == 0)
            return 0;
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(cost, 0, sizeof(cost));
        v.resize(1004);
        cap[1001][drain] = a;
        cap[1002][drain] = b;
        v[1001].push_back(drain);
        v[drain].push_back(1001);
        v[1002].push_back(drain);
        v[drain].push_back(1002);
        for (int i = 1; i <= n ; i++) {
            int capacity, da, db;
            scanf("%d %d %d", &capacity, &da, &db);
            v[source].push_back(i);
            v[i].push_back(source);
            cap[source][i] = capacity;
            v[i].push_back(1001);
            v[1001].push_back(i);
            v[i].push_back(1002);
            v[1002].push_back(i);
            cost[i][1001] = da;
            cost[1001][i] = -da;
            cost[i][1002] = db;
            cost[1002][i] = -db;
            cap[i][1002] = inf;
            cap[i][1001] = inf;
        }
        int ans = 0;
        while(true) {
            memset(pre, -1, sizeof(pre));
            memset(inque, false, sizeof(inque));
            fill(dist, dist+1004, inf);
            queue<int> q;
            dist[source] = 0;
            inque[source] = true;
            q.push(source);
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                inque[cur] = false;
                for (int i = 0 ; i < v[cur].size() ; i++) {

                    int next = v[cur][i];
                    if (cap[cur][next] > flow[cur][next] && dist[next] > dist[cur] + cost[cur][next]) {
                        dist[next] = dist[cur] +cost[cur][next];
                        pre[next] = cur;
                        if (next == drain)
                            break;
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
                f = min(f, cap[pre[i]][i] - flow[pre[i]][i]);
            }
            for (int i = drain ; i != source ; i = pre[i]) {
                flow[pre[i]][i] += f;
                flow[i][pre[i]] -= f;
                ans += f*cost[pre[i]][i];
            }
        }
        printf("%d\n", ans);
        v.clear();






    }















  return 0;
}
