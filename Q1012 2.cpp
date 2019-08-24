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
int m, n, k;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int a[50][50];
int c[50][50];

void BFS(int x, int y) {
    c[x][y] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()) {
        auto p = q.front();
        int cx = p.first;
        int cy = p.second;
        q.pop();
        for (int i = 0 ; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (c[nx][ny] == 0 && a[nx][ny] == 1) {
                    c[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        memset(c, 0, sizeof(c));
        memset(a, 0, sizeof(a));
        scanf("%d %d %d", &m, &n, &k);
        for (int i = 0 ; i < k ;i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            a[y][x] = 1;
        }
        int cnt = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (a[i][j] == 1 && c[i][j] == 0) {
                    BFS(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
















  return 0;
}
