#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
pair<long long ,long long > dp[41];
int main() {
    int testcase;
    scanf("%d", &testcase);

    dp[0].first = 1 ; dp[0].second = 0;
    dp[1].first = 0 ; dp[1].second = 1;

    for (int i = 2 ; i<=40 ; i++) {
        dp[i].first += dp[i-1].first + dp[i-2].first;
        dp[i].second += dp[i-1].second + dp[i-2].second;
    }


    while(testcase--) {
        int a;
        scanf("%d", &a);
        printf("%lld %lld\n", dp[a].first, dp[a].second);
    }
















  return 0;
}
