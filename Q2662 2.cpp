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
#define inf 987654321

using namespace std;
int n, m;
int a[301][31]; // [amount][company]
int dp[301][31];

int go(int total_profit, int total_invest, int amount , int company) {
    if (total_invest > n || company > m)
        return -inf;
    if (total_invest == n && company == m)
        return 0;
    if (dp[amount][company]) {
        return dp[amount][company];
    }
    else {
        int ans = 0;
        for (int i = 0 ; i <= n ; i++) {
            ans = max(ans, go(total_profit + a[i][company], total_invest+i, i, company + 1));
        }
        return dp[amount][company] = total_profit + ans;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        int t;
        scanf("%d", &t);
        for (int j = 1 ; j <= m ; j++) {
            int profit;
            scanf("%d", &profit);
            a[j][i] = profit;
        }
    }
    printf("%d\n", go(0,0, 1, 1));
    for (int i = 0 ; i <= n ; i++) {
        printf("%d ", dp[2][i]);
    }


















  return 0;
}
