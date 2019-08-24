#include <bits/stdc++.h>

using namespace std;
long long dp[32][32];

long long binary(int n, int one) {
    long long &ret = dp[n][one];
    if (ret != -1)
        return ret;
    if (one == 0 || n == 0) return ret = 1;
    ret = binary(n-1, one);
    if (one > 0) ret += binary(n-1, one-1);
    return ret;
}

void answer(int n, int one, long long k) {
    if (n == 0) return;
    if (one == 0) {
        for (int i = 0 ; i < n; i++)
            printf("0");
        return;
    }
    if (binary(n-1, one) >= k) {
        printf("0");
        answer(n-1, one, k);
    }
    else {
        printf("1");
        answer(n-1, one-1, k - binary(n-1, one));
    }
}

int main() {
    int n, l; long long k;
    cin >> n >> l >> k;
    memset(dp, -1, sizeof(dp));
    answer(n, l, k);
    return 0;
}