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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int a[501][501];
int d[501][501];
int n;

int DFS(int x, int y) {
    if (d[x][y] != 0) {
        return d[x][y];
    }
    int ans = 0;
    for (int i = 0 ; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 < nx && nx <= n && 0 < ny && ny <= n) {
            if (a[x][y] < a[nx][ny]) {
                int p = DFS(nx, ny);
                ans = max(p, ans);
            }
        }
    }
    return d[x][y] = ans+1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ;i++) {
        for (int j = 1; j <= n ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n ;i++) {
        for (int j = 1; j <= n ;j++) {
            if (d[i][j] == 0) {
                DFS(i, j);
            }
            ans = max(ans, d[i][j]);
        }
    }
    printf("%d", ans);

















  return 0;
}
