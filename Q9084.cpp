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
int n, testcase, m;
int a[20];
int dp[10001];

int main() {
    scanf("%d", &testcase);
    while(testcase--) {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));

        scanf("%d", &n);
        for (int i = 0 ; i < n ;i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        dp[0] = 1;
        for (int i = 0 ; i <n ; i++) {
            for (int j = 0 ; j <= 10000 ; j++) {
                if (j >= a[i]) {
                    dp[j] += dp[j - a[i]];
                }
            }
        }
        printf("%d\n", dp[m]);

    }
















  return 0;
}
