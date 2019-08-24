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
int c[402][402];
int f[402][402];
int previous[402];

int main() {
    scanf("%d %d", &n, &m);
    vector<vector<int>> v;
    int source = 0;
    int sink = 401;
    v.resize(402);
    for (int i = 1 ; i <= n ; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0 ; j < k ; j++) {
            int room;
            scanf("%d", &room);
            room = room + 200;
            c[i][room] = 1;
            v[i].push_back(room);
            v[room].push_back(i);
        }
    }
    for (int i = 1; i <= n ; i++) {
        v[i].push_back(0);
        v[0].push_back(i);
        c[0][i] = 1;
    }
    for (int i = 1; i <= m ; i++) {
        v[200+i].push_back(401);
        v[401].push_back(200+i);
        c[200+i][401] = 1;
    }
    int ans = 0;
    while(true) {
        memset(previous, -1, sizeof(previous));
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0 ; i < v[cur].size(); i++) {
                int next = v[cur][i];
                if (f[cur][next] < c[cur][next] && previous[next] == -1) {
                    previous[next] = cur;
                    q.push(next);
                }
            }
        }
        if (previous[401] == -1)
            break;
        int flow = inf;
        for (int i = 401 ; i != 0 ; i = previous[i]) {
            flow = min(flow, c[previous[i]][i] - f[previous[i]][i]);
        }
        for (int i = 401 ; i != 0 ; i = previous[i]) {
            f[previous[i]][i] += flow;
            f[i][previous[i]] -= flow;
        }
        ans += flow;
    }
    printf("%d", ans);
















  return 0;
}
