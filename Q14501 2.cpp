#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
vector<pair<int ,int>> v(16);
int n;
int dp[16];

int go(int i) {
    if (i == n+1)
        return 0;
    if (i > n+1)
        return -inf;
    if (dp[i] != -1)
        return dp[i];
    return dp[i] = max(go(i+1), go(i+v[i].first) + v[i].second);
}

int main() {
      scanf("%d", &n);
      memset(dp, -1, sizeof(dp));
      for (int i = 1 ; i <= n ; i++) {
        scanf("%d %d", &v[i].first, &v[i].second);
      }
      printf("%d", go(1));















  return 0;
}
