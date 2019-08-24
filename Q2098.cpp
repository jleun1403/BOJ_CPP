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
int d[1<<16][16];
int a[16][16];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <n ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1 ; i < (1<<16) ; i++) {
        for (int j = 0 ; j < 16 ; j++)
            d[i][j] = inf;
    }
    d[1][0] = 0;
    for (int s = 1 ; s < (1<<n) ; s++) {
        for (int i = 0 ; i < n ; i++) {
            if (s & (1<<i)) {
                for (int j = 1 ; j < n ; j++) {
                    if (j != i && ((s & (1 << j)) == 0) && a[i][j] != 0) {
                        d[s|(1<<j)][j] = min(d[s][i] + a[i][j], d[s|(1<<j)][j]);
                    }
                }
            }
        }
    }
    int ans = inf;
    for (int i = 1 ; i < n ; i++) {
        if (a[i][0] != 0) {
            ans = min(ans, d[(1<<n) -1][i] + a[i][0]);
        }
    }
    printf("%d", ans);













  return 0;
}
