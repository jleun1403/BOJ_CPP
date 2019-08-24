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
int a[1000][1000];
int n, m;
int hx, hy;
int ex, ey;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[1000][1000][2];
int dist[1000][1000][2];

struct p{
    int x;
    int y;
    int c;
    p(int a, int b, int cc) : x(a), y(b), c(cc) {}
};

void BFS(int x, int y) {
    queue<p> q;
    q.push(p(x, y, 0));
    visited[x][y][0] = true;
    dist[x][y][0] = 0;
    while(!q.empty()) {
        auto pp = q.front();
        q.pop();
        int cx = pp.x;
        int cy = pp.y;
        int ch = pp.c;
        for (int i = 0 ; i < 4 ; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (visited[nx][ny][ch] == false) {
                    if (ch == 0) {
                        if (a[nx][ny] == 0) {
                            visited[nx][ny][ch] = true;
                            dist[nx][ny][ch] = dist[cx][cy][ch] +1;
                            q.push(p(nx, ny, 0));
                        }
                        else {
                            visited[nx][ny][1] = true;
                            dist[nx][ny][1] = dist[cx][cy][ch] +1;
                            q.push(p(nx, ny, 1));
                        }
                    }
                    else {
                        if (a[nx][ny] == 0) {
                            visited[nx][ny][1] = true;
                            dist[nx][ny][1] = dist[cx][cy][1] +1;
                            q.push(p(nx, ny, 1));
                        }
                    }
                }
            }
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> hx >> hy >> ex >> ey;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++) {
            cin >> a[i][j];
        }
    }
    BFS(hx-1, hy-1);
    int ans = min(dist[ex-1][ey-1][0], dist[ex-1][ey-1][1]);
    if (ans == 0)
        printf("-1");
    else
        printf("%d", ans);

















  return 0;
}
