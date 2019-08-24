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
int n;
int d[501][501];
int a[501][501];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= i ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    d[1][1] = a[1][1];
    for (int i = 2; i <= 500 ; i++) {
        for (int j = 1 ; j <= i ; j++) {
            d[i][j] = max(d[i-1][j], d[i-1][j-1]) +a[i][j];
        }
    }
    int ans = -inf;
    for (int i = 1 ; i <= n ; i++) {
        ans = max(ans, d[n][i]);
    }
    printf("%d", ans);

















  return 0;
}
