#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int dp[10001][101];

int gcd(int x, int y) {
    if (x % y == 0) return y;
    else return gcd(y, x % y);
}

int go (int x, int y) {
    if (x == y) return 1;
    if (dp[x][y] != 0) return dp[x][y];
    if (x % y == 0) return x / y;
    if (y % x == 0) return y / x;
    //if (gcd(x, y) != 1) return go(x / gcd(x, y), y / gcd(x, y));

    int ans = inf;
    if (x > y*3) {
        return 1 +go(x - y, y);
    }
    if (y > x*3) {
        return  1 + go(x , y - x);
    }
    for (int i = 1 ; i< x ; i++) {
        ans = min(ans, go(i, y) + go(x - i, y));
    }
    for (int i = 1 ; i < y ; i++){
        ans = min(ans, go(x, y - i) + go(x , i));
    }
    return dp[x][y] = ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", go(n, m));
















  return 0;
}
