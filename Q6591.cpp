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
#define inf ((1<<31)-1)

using namespace std;

long long dp[2001][2001];

int main() {
    int n, m;
    dp[1][0] = 1LL;
    dp[1][1] = 1LL;
    for (int i = 2 ; i <= 2000 ; i++) {
        dp[i][0] = 1LL;
        for (int j = 1 ; j < i ; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
        dp[i][i] = 1LL;
    }
    scanf("%d %d", &n, &m);
    while(n != 0 || m != 0) {
        if (n > 2000) {
            if (m == 0 || m == n)
                printf("1\n");
            else if (m == 1 || m == n-1)
                printf("%d\n", n);
            else {
                if (m > n/2)
                    m = (n-m);
                int k = m;
                long long sum = 1LL;
                for (int i = 0 ; i < k ; i++) {
                    sum *= (long long)(n - i);
                }
                for (int i = 0 ; i < k ; i++) {
                    sum /= (long long)(m - i);
                }
                printf("%lld\n", sum);
            }
        }
        else
            printf("%lld\n", dp[n][m]);
        scanf("%d %d", &n, &m);
    }
















  return 0;
}
