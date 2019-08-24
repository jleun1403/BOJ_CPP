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
int cap[202][202];
int flow[202][202];
vector<vector<int>> v(202);
int pre[202];
const int source = 0;
const int drain = 201;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i++) {
        scanf("%d", &cap[i+100][drain]);
        v[i+100].push_back(drain);
        v[drain].push_back(i+100);
    }
    for (int i = 1; i <= m ; i++) {
        scanf("%d", &cap[source][i]);
        v[source].push_back(i);
        v[i].push_back(source);
    }
    for (int i = 1 ; i <= m ;i++) {
        for (int j = 1; j <= n ; j++) {
            scanf("%d", &cap[i][j+100]);
            v[i].push_back(j+100);
            v[j+100].push_back(i);
        }
    }
    int ans = 0;
    while(true) {
        memset(pre, -1 ,sizeof(pre));
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0 ; i < v[cur].size() ; i++){
                int next = v[cur][i];
                if (cap[cur][next] > flow[cur][next] && pre[next] == -1) {
                    pre[next] = cur;
                    q.push(next);
                    if (next == drain)
                        break;
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
        }
        ans += f;
    }
    printf("%d", ans);















  return 0;
}
