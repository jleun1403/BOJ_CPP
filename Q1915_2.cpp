#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int a[1001][1001];
int dp[1001][1001];


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n ; i++) {
        for (int j = 1 ;j <= m ; j++) {
            if (a[i][j] == 0)
                dp[i][j] = 0;
            else {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j] , dp[i][j-1])) + 1;
                ans = max(dp[i][j], ans);
            }
        }
    }
    printf("%d\n", ans * ans);















  return 0;
}
