#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int dp[101][10001];
vector<pair<int, int>> v;

int main() {
    int t, k;
    scanf("%d %d", &t, &k);
    for (int i = 0 ; i < k ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, b));
    }
    dp[0][0] = 1;

    for (int i = 1 ; i <= k ; i++) {
        for (int price = 0 ; price <= t; price++) {
            for (int j = 0 ; j <= v[i-1].second ; j++) {
                if (price - v[i-1].first*j < 0)
                    break;
                dp[i][price] += dp[i-1][price - v[i-1].first*j];
            }
        }
    }
    printf("%d\n", dp[k][t]);














  return 0;
}
