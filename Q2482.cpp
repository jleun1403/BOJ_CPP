#include <bits/stdc++.h>
#define inf 1000000003

using namespace std;
int dp[1001][1001];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 2;
    for (int i = 3; i <= 1000 ; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i ; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) % inf;
        }
    }
    printf("%d", (dp[n-3][m-1] + dp[n-1][m]) % inf);
















  return 0;
}
