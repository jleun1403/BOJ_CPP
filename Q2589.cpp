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
char a[51][51];
int c[51][51];
int d[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;

void BFS(int x, int y) {
    c[x][y] = 1;
    d[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()) {
        int nowx = q.front().first;
        int nowy = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4; i++) {
            int nx = nowx + dx[i];
            int ny = nowy + dy[i];
            if (0 < nx && nx <= n && 0 < ny && ny <= m) {
                if (c[nx][ny] == 0 && a[nx][ny] == 'L') {
                    c[nx][ny] = 1;
                    d[nx][ny] = d[nowx][nowy] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            scanf(" %1c" ,&a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (a[i][j] == 'L' && c[i][j] == 0) {
                BFS(i, j);
                for (int k = 1 ; k <= n ; k++) {
                    for (int l = 1; l <=m ; l++) {
                        if (d[l][k] > ans)
                            ans = d[l][k];
                    }
                }
            }
            memset(c, 0, sizeof(c));
        }

    }
    cout << ans;







  return 0;
}
