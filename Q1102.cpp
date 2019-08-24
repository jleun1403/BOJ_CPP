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
int a[16][16];
int d[1<<16][16];
int n;
string s;
int p;

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    cin >> s;
    scanf("%d", &p);
    int start = 0;
    for (int i = 0 ; i < n ;i++) {
        if (s[i] == 'Y') {
            start += (1 << (i));
        }
    }
    if (start == 0 && p == 0) {
        printf("0");
        return 0;
    }
    for (int i = 0 ; i < (1 << 16) ; i++) {
        for (int j = 0 ; j < n; j++) {
            d[i][j] = inf;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        if (s[i] == 'Y')
            d[start][i] = 0;
    }
    for (int s = start ; s < (1<<n) ; s++) {
        for (int i = 0 ; i < n ; i++) {
            if (s & (1<<i)) {
                for (int j = 0 ;  j < n ; j++) {
                    if (i != j && ((s & (1 << j)) == 0) && (d[s][i] != inf)) {
                        d[s|(1<<j)][j] = d[s|(1<<j)][i] = min(d[s][i] + a[i][j] , d[s|(1<<j)][j]);
                        for (int k = 0 ; k < n ; k++) {
                            if (s&(1<<k))
                                d[s|(1<<j)][k] = d[s|(1<<j)][j];
                        }
                    }
                }
            }
        }
    }
    int pnum = 0;
    int ans = inf;
    for (int i = 1 ; i < (1<<n) ; i++) {
        pnum = 0;
        for (int k = 0 ; k < n ; k++) {
            if (i & (1<<k))
                pnum++;
        }
        if (pnum >= p) {
            for (int k = 0 ; k < n ; k++) {
                ans = min(ans, d[i][k]);
            }
        }
    }
    if (ans == inf)
        printf("-1");
    else
        printf("%d", ans);


















  return 0;
}
