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
#define inf 10000003

using namespace std;

int a[101];
int dp[101][100001];
int n;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int go(int i, int result) {
    if (i == n+1) {
        if (result == 1)
            return 1;
        else
            return 0;
    }
    if (dp[i][result] != -1)
        return dp[i][result];
    if (result == 0) {
        return dp[i][result] = (go(i+1, 0) % inf + go(i+1, a[i]) % inf) % inf;
    }
    else {
        return dp[i][result] = (go(i+1, result) % inf + go(i+1, gcd(result, a[i])) % inf) % inf;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d", go(1, 0));
















  return 0;
}
