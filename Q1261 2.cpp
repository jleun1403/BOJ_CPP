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
#define inf 1000000000

using namespace std;
int n, m;
int a[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dist[101*101];
int c[101*101];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= m ; i++) {
        for (int j = 1; j<= n ; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n*m ; i++) {
        dist[i] = inf;
    }
    dist[1] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, 1));
    while(!q.empty()) {
        auto p = q.top();
        q.pop();
        int cur = p.second;
        if (c[cur] == 1)
            continue;
        c[cur] = 1;
        for (int i = 0 ; i < 4 ; i++) {
            int cx = (cur / n) + 1;
            int cy = (cur % n);
            if (cy == 0) {
                cx = cx -1;
                cy = n;
            }
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 < nx && nx <= m && 0 < ny && ny <= n) {
                int d = a[nx][ny];
                if (dist[(nx-1) * n + ny] > dist[(cx-1) * n + cy] + d) {
                    dist[(nx-1) * n + ny] = dist[(cx-1) * n + cy] + d;
                    q.push(make_pair(dist[(nx-1) * n + ny] * -1, (nx-1) * n + ny));
                }
            }
        }
    }
    cout << dist[m*n];

















  return 0;
}
