#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int a[100001];
int dp[100001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1;  i <= n ; i++) {
        scanf("%d", &a[i]);
    }
    int ans = a[1];
    for (int i = 1; i <= n ; i++){
        dp[i] = max(dp[i-1] +v[i] , v[i]);
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
















  return 0;
}
