#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int dp[1000001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2 ; i <= n ; i++) {
        dp[i] = dp[i-1] + 1;
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
    }
    printf("%d\n", dp[n]);
    while(n > 0) {
        printf("%d ", n);
        if (n == 1)
            break;
        if (dp[n] == dp[n-1] + 1) {
            n--;
            continue;
        }
        if (n % 2 == 0) {
            if (dp[n] == dp[n/2] + 1) {
                n /= 2;
                continue;
            }
        }
        if (n % 3 == 0) {
            if (dp[n] == dp[n/3] + 1) {
                n /= 3;
            }
        }
    }















  return 0;
}
