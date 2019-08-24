#include <iostream>
#include <cstring>


using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dp[500][500];
int a[500][500];
int n, m;
int ans;

int DFS(int x, int y) {
    int ret = dp[x][y];
    if (ret != -1)
        return ret;
    dp[x][y] = 0;
    for (int i = 0 ; i < 4 ; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] < a[x][y]) {
            dp[x][y] += DFS(nx, ny);
        }
    }
    return dp[x][y];

}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[n-1][m-1] = 1;
    printf("%d", DFS(0, 0));








  return 0;
}
