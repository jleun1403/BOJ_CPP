#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int dp[301][301];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            int a;
            scanf("%d", &a);
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + a - dp[i-1][j-1];
        }
    }
    int k;
    scanf("%d", &k);
    for (int i = 0 ; i < k ; i++) {
        int a, b , c , d;
        scanf("%d %d %d %d", &a, &b,&c, &d);
        printf("%d\n", dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1]);
    }















  return 0;
}
