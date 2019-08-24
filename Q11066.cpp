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
#define inf 1000000000

using namespace std;
int testcase, k;
int page[501];
int dp[501][501];


int go(int left, int right) {
    if (dp[left][right] != inf)
        return dp[left][right];
    if (left == right)
        return dp[left][right] = 0;
    else {
        int sum = 0;
        for (int i = left ; i <= right ; i++) {
            sum += page[i];
        }
        for (int i = left ; i <= right ; i++) {
            dp[left][right] = min(dp[left][right], go(left, i) + go(i+1, right) + sum);
        }
        return dp[left][right];
    }
}

int main() {
    scanf("%d", &testcase);
    while (testcase--) {
        scanf("%d", &k);
        for (int i = 1; i <= k ;i++) {
            scanf("%d", &page[i]);
        }
        for (int i = 0 ; i <= k ; i++){
            for (int j = 0 ; j<= k ; j++)
                dp[i][j] = inf;
        }
        printf("%d\n", go(1, k));
    }
















  return 0;
}
