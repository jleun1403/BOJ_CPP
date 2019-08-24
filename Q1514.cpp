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

int turn[10] = {0, 1, 1, 1, 2, 2, 2, 1, 1, 1};

int dp[100][10][10];
int a[100];
int b[100];
int n;

int go(int i, int j, int k) {
    if (i == n)
        return 0;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    int original = a[i] + j;
    int to = b[i];
    int ans = inf;
    for (int two = 0 ; two < 10 ; two++){
        for(int three = 0 ; three < 10 ; three++) {
            int one = to - two - three - original;
            if (one < 0)
                one += 10;
            int cost = turn[one] + turn[two] + turn[three];
            ans = min(ans, go(i+1, (k + two + three) % 10 , three) +cost);
        }
    }
    return dp[i][j][k] = ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%1d", &a[i]);
    }
    for (int i = 0 ; i < n ;i++) {
        scanf("%1d", &b[i]);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d", go(0, 0, 0));














  return 0;
}
