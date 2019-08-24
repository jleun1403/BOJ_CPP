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
int k, n, m;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, 1, -1};
int d_x[4] = {-1, 1, 0, 0};
int d_y[4] = {0, 0, 1, -1};
int a[200][200];
int dist[200][200][31];
int visit[200][200][31];

struct s{
    int x;
    int y;
    int chance;
    s(int _x, int _y, int _chance): x(_x), y(_y), chance(_chance) {}

};

void BFS(int x, int y) {
    queue<s> q;
    dist[x][y][0] = 0;
    visit[x][y][0] = 0;
    q.push(s(x, y, 0));
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int cx = p.x;
        int cy = p.y;
        int cchance = p.chance;
        for (int i = 0 ; i < 4 ; i++) {
            int nx = cx + d_x[i];
            int ny = cy + d_y[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (visit[nx][ny][cchance] == 0 && a[nx][ny] != 1) {
                    visit[nx][ny][cchance] = 1;
                    dist[nx][ny][cchance] = dist[cx][cy][cchance] + 1;
                    q.push(s(nx, ny, cchance));
                }
            }
        }
        if (cchance < k) {
            for (int i = 0 ; i < 8 ; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if(visit[nx][ny][cchance+1] == 0 && a[nx][ny] != 1) {
                        visit[nx][ny][cchance+1] = 1;
                        dist[nx][ny][cchance +1] = dist[cx][cy][cchance] +1;
                        q.push(s(nx, ny, cchance+1));
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &k, &m, &n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    BFS(0, 0);
    int ans = inf;
    for (int i = 0 ; i <= k ; i++) {
        if (dist[n-1][m-1][i] != 0) {
            ans = min(ans, dist[n-1][m-1][i]);
        }
    }
    if (ans == inf)
        printf("-1");
    else
        printf("%d", ans);
















  return 0;
}
