#include <bits/stdc++.h>
#define inf 1000000007

using namespace std;
long long dp[1001][1001];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= m ; i++){
        dp[1][i] = 1;
    }
    for (int i = 1; i <= n ; i++) {
        dp[i][1] = 1;
    }
    for (int i = 2 ; i <= n ; i++) {
        for (int j = 2 ; j <= m ; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1]) % inf;
        }
    }
    printf("%lld", dp[n][m]);
















  return 0;
}
