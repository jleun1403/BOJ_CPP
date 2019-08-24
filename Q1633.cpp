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
int dp[1001][16][16];
int a[1001][2];
int n;
int go(int sum, int black, int white) {
    if (black == 15 && white == 15)
        return 0;
    if (sum > n)
        return -inf;
    if (black > 15 || white  > 15)
        return -inf;
    if (dp[sum][black][white] != -1)
        return dp[sum][black][white];
    int ans = -inf;
    ans = max(ans, go(sum +1, black, white));
    if (black < 15) {
        ans = max(ans, go(sum+1, black+1, white) + a[sum][0]);
    }
    if (white < 15) {
        ans = max(ans, go(sum+1, black, white+1) + a[sum][1]);
    }
    return dp[sum][black][white] = ans;
}

int main() {
    int p = 0;
    while(scanf("%d %d", &a[p][0], &a[p][1]) == 2) {
        p++;
    }
    n = p;
    memset(dp, -1, sizeof(dp));
    int ans = go(0, 0, 0);
    printf("%d", ans);















  return 0;
}
