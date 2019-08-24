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
long long dp[1000000];

long long go(long long x, int p, int q) {
    if (x == 0) return 1;
    if (x < 1000000) {
        if (dp[x] != 0)
            return dp[x];
    }
    long long ans = go(x/p, p, q) + go(x/q, p, q);
    if (x < 1000000LL)
        dp[x] = ans;
    return ans;
}

int main() {
    long long n;
    int p, q;
    scanf("%lld %d %d", &n, &p, &q);
    printf("%lld", go((long long)n, p, q));
















  return 0;
}
