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
int n;
long long dp[1001][3];
long long a[1001][3];

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++) {
        int r, g, b;
        scanf("%lld %lld %lld", &a[i][0], &a[i][1], &a[i][2]);
    }
    for (int i = 1; i <= n ; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + a[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + a[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + a[i][2];
    }
    printf("%lld", min(dp[n][0], min(dp[n][1], dp[n][2])));
















  return 0;
}
