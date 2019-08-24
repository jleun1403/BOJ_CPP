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
int n, m;
int dp[200][1<<14];

int go(int x, int s) {
    if (x == m*n && s == 0)
        return 1;
    else if (x == m*n)
        return 0;
    if (dp[x][s] != -1)
        return dp[x][s];
    int ans = 0;
    if (s&1) {
        ans = go(x+1, s>>1);
    }
    else {
        ans = go(x+1,  (s>>1)|(1<< (m-1)));
        if (((s & (1<<1)) == 0)  && (x % m != m-1)){
            ans += go(x+2, s>>2);
        }
    }
    return dp[x][s] = ans % 9901;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &n, &m);
    printf("%d", go(0, 0));
















  return 0;
}
