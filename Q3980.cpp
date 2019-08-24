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

//1~11 player 12~22 position 0 source 23 drain
using namespace std;
const int source = 0;
const int drain = 23;
int cap[24][24];
int flow[24][24];
int cost[24][24];
vector<vector<int>> v;
int pre[24];
int dist[24];
bool inque[24];


int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(cost, 0, sizeof(cost));
        v.resize(24);
        for (int i = 1 ; i <= 11; i++){
            for (int j = 12 ; j <= 22 ; j++) {
                scanf("%d", &cost[i][j]);
                cost[i][j] = -cost[i][j];
                cost[j][i] = -cost[i][j];
                if (cost[j][i] > 0) {
                    cap[i][j] = 1;
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
            cap[source][i] = 1;
            v[source].push_back(i);
            v[i].push_back(source);
        }
        for (int j = 12 ; j <= 22 ; j++) {
            v[j].push_back(drain);
            v[drain].push_back(j);
            cap[j][drain] = 1;
        }
        int ans = 0;
        while(true) {
            memset(pre, -1, sizeof(pre));
            fill(dist, dist+24, inf);
            memset(inque, false, sizeof(inque));
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
                    if (cap[cur][next] > flow[cur][next] && dist[next] > dist[cur] +cost[cur][next]) {
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
            for (int i = drain ; i != source ; i = pre[i]) {
                flow[pre[i]][i] += 1;
                flow[i][pre[i]] -= 1;
                ans += (-1)*cost[pre[i]][i];
            }
        }
        printf("%d\n", ans);
        v.clear();



    }

















  return 0;
}
