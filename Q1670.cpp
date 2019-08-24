#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
long long dp[10001];

int main() {
    int n;
    scanf("%d", &n);
    dp[0] = 1LL;
    dp[2] = 1LL;
    dp[4] = 2LL;
    for (int i = 6 ; i <= 10000 ; i = i+ 2) {
        for (int j = 2 ; j <= i ; j = j + 2) {
            dp[i] += (dp[j-2]*dp[i-j])%inf;
            dp[i] = dp[i] % inf;
        }
    }
    printf("%lld", dp[n]);















  return 0;
}
