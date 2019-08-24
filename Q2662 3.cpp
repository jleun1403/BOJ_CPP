#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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
int a[301][21];
int dp[301][21];
int amount[301][21];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i++) {
        for (int j = 0 ; j <= m ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            dp[i][j] = dp[i][j-1];
            amount[i][j] = 0;
            if (a[i][j] > dp[i][j]) {
                dp[i][j] = a[i][j];
                amount[i][j] = i;
            }
            for (int k = 1 ; k <= i ; k++) {
                if (dp[i-k][j-1] + a[k][j] > dp[i][j]) {
                    dp[i][j] = dp[i-k][j-1] + a[k][j];
                    amount[i][j] = k;
                }
            }
        }
    }
    printf("%d\n", dp[n][m]);
    stack<int> s;
    int x = m;
    int y = n;
    for (int i = 1; i <= m ; i++) {
        s.push(amount[y][x]);
        y -= amount[y][x];
        x--;
    }
    for (int i = 1 ; i <= m ; i++) {
        printf("%d ", s.top());
        s.pop();
    }















  return 0;
}
