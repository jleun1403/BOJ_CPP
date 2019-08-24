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
class s{
public:

    int x;
    int y;
    int chance;
    s(int _x, int _y, int _chance) {
        x = _x; y = _y; chance = _chance;
    }
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
vector<vector<int>> a;
int dist[1000][1000][2];
int c[1000][1000][2];
void BFS (int x, int y, int chance) {
    c[x][y][chance] = 1;
    queue<s> q;
    q.push(s(x, y, chance));
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int cx = p.x;
        int cy = p.y;
        int ch = p.chance;
        for (int i = 0 ; i < 4 ; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
               if (ch == 0) {
                    if (c[nx][ny][0] == 0) {
                        if (a[nx][ny] == 1) {
                            c[nx][ny][1] = 1;
                            dist[nx][ny][1] = dist[cx][cy][0] + 1;
                            q.push(s(nx, ny, 1));
                        }
                        else {
                            c[nx][ny][0] = 1;
                            dist[nx][ny][0] = dist[cx][cy][0] + 1;
                            q.push(s(nx, ny, 0));
                        }
                    }
               }
               else {
                    if (c[nx][ny][1] == 0) {
                        if (a[nx][ny] == 0) {
                            c[nx][ny][1] = 1;
                            dist[nx][ny][1] = dist[cx][cy][1] + 1;
                            q.push(s(nx, ny, 1));
                        }
                    }
               }
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    a.resize(n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            int k;
            scanf("%1d", &k);
            a[i].push_back(k);
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            dist[i][j][0] = inf;
            dist[i][j][1] = inf;
        }
    }
    dist[0][0][0] = 1;
    BFS(0, 0, 0);


    if (c[n-1][m-1] == 0 || min(dist[n-1][m-1][0], dist[n-1][m-1][1]) == inf)
        printf("-1");
    else
        printf("%d", min(dist[n-1][m-1][0], dist[n-1][m-1][1]));


















  return 0;
}
