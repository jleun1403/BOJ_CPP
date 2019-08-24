#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int a[301][301];
int dp[301][301];
int n, m, t;

int main() {
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 0 ; i < t ; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        if (x > y) continue;
        a[x][y] = max(a[x][y], z);
    }
    for (int j = 1 ; j <= n ; j++) {
        dp[2][j] = a[1][j];
    }
    for (int i = 3 ; i <= m ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            for (int k = 1 ; k < j ; k++) {
                if (a[k][j] > 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + a[k][j]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 2 ; i <= m ; i++) {
        ans = max(ans, dp[i][n]);
    }
    printf("%d", ans);















  return 0;
}
