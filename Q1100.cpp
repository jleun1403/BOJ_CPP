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

using namespace std;
int testcase, n;
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
int c[301][301];
int dist[301][301];

void BFS(int x, int y){
    queue<pair<int ,int>> q;
    q.push(make_pair(x, y));
    c[x][y] = 1;
    dist[x][y] = 0;
    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0 ; i < 8 ; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 < nx && nx <= n && 0 < ny && ny <= n) {
                if (c[nx][ny] == 0) {
                    c[nx][ny] = 1;
                    dist[nx][ny] = dist[cx][cy] +1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d", &n);
        int a, b, x, y;
        scanf("%d %d %d %d", &a, &b, &x, &y);
        a += 1;
        b += 1;
        x += 1;
        y += 1;

        BFS(a, b);
        printf("%d\n", dist[x][y]);
        memset(c, 0, sizeof(c));
        memset(dist, 0, sizeof(dist));
    }
















  return 0;
}
