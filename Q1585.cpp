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
int n, t, f;
const int source = 0;
const int drain = 101;
int cap[102][102];
int flow[102][102];
int cost[102][102];
vector<vector<int>> v(102);
int pre[102];
int dist[102];
bool inque[102];
int a[102];
int b[102];

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ;i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1 ; i <= n ;i++) {
        scanf("%d", &b[i]);
    }
    scanf("%d %d", &t, &f);
    int cnt = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 51 ; j <= 50 + n ; j++) {
            int from, to;
            from = a[i];
            to = b[j-50];
            if (from + 1<= to) {
                cnt++;
                v[i].push_back(j);
                v[j].push_back(i);
                cap[i][j] = 1;
                if (to - from < t) {
                    cost[i][j] = min((t- to +from)*(t - to + from), f);
                    cost[j][i] = -cost[i][j];
                }
            }

        }
        v[i].push_back(source);
        v[source].push_back(i);
        cap[source][i] = 1;
    }

    for (int j = 51 ; j <= 50 + n ; j++){
        v[j].push_back(drain);
        v[drain].push_back(j);
        cap[j][drain] = 1;
    }
    int minans = 0;
    int flownum = 0;
    while(true) {
        memset(pre, -1, sizeof(pre));
        memset(inque, false, sizeof(inque));
        fill(dist, dist+102, inf);
        queue<int> q;
        q.push(source);
        inque[source] = true;
        dist[source] = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            inque[cur] = false;
            for (int i = 0 ; i < v[cur].size(); i++) {
                int next = v[cur][i];
                if (cap[cur][next] > flow[cur][next] && dist[next] >dist[cur] + cost[cur][next]) {
                    dist[next] = dist[cur] +cost[cur][next];
                    pre[next] = cur;
                    if (inque[next] == false){
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
            minans += cost[pre[i]][i];
        }
        flownum++;
    }
    if (flownum != n) {
        printf("-1");
        return 0;
    }
    printf("%d ", minans);
    memset(flow, 0, sizeof(flow));
    for (int i = 1 ; i <= n; i++){
        for (int j = 51 ; j <= 50 + n; j++) {
            cost[i][j] = -cost[i][j];
            cost[j][i] = -cost[i][j];
        }
    }
    int maxans = 0;
    while(true) {
        memset(pre, -1, sizeof(pre));
        memset(inque, false, sizeof(inque));
        fill(dist, dist+102, inf);
        queue<int> q;
        q.push(source);
        inque[source] = true;
        dist[source] = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            inque[cur] = false;
            for (int i = 0 ; i < v[cur].size(); i++) {
                int next = v[cur][i];
                if (cap[cur][next] > flow[cur][next] && dist[next] >dist[cur] + cost[cur][next]) {
                    dist[next] = dist[cur] +cost[cur][next];
                    pre[next] = cur;
                    if (inque[next] == false){
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
            maxans += -cost[pre[i]][i];
        }
    }
    printf("%d", maxans);














  return 0;
}
