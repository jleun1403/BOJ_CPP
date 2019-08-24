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
#define inf 987654321

using namespace std;
const int source = 0;
const int drain = 801;
int n, m;
int cap[802][802];
int flow[802][802];
vector<vector<int>> v(802);
int pre[802];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 3 ; i <= n ; i++) {
        int from = i;
        int to = 400 + i;
        cap[from][to] = 1;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    cap[source][1] = inf;
    v[source].push_back(1);
    v[1].push_back(source);

    cap[1][401] = inf;
    v[1].push_back(401);
    v[401].push_back(1);

    cap[2][402] = inf;
    v[2].push_back(402);
    v[402].push_back(2);

    cap[402][drain] = inf;
    v[402].push_back(drain);
    v[drain].push_back(402);


    for (int i = 0 ; i < m ; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        int from1 = from + 400;
        cap[from1][to] = 1;
        v[from1].push_back(to);
        v[to].push_back(from1);
        int to1 = to + 400;
        cap[to1][from] = 1;
        v[to1].push_back(from);
        v[from].push_back(to1);
    }

    int ans = 0;
    while(true) {
        memset(pre, -1, sizeof(pre));
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0 ; i < v[cur].size(); i++) {
                int next = v[cur][i];
                if (pre[next] == -1 && cap[cur][next] > flow[cur][next]) {
                    pre[next] = cur;
                    q.push(next);
                    if (next == drain)
                        break;
                }
            }
        }
        if (pre[drain] == -1)
            break;
        for (int i = drain; i != source ; i = pre[i]) {
            flow[pre[i]][i] += 1;
            flow[i][pre[i]] -= 1;
        }
        ans++;
    }
    printf("%d", ans);
















  return 0;
}
