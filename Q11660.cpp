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

using namespace std;
int n, m;
int a[1025][1025];
int s[1025][1025];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            scanf("%d", &a[i][j]);
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
    }
    for (int i = 0 ; i < m ; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int ans;
        ans = s[c][d] - s[a-1][d] - s[c][b-1] + s[a-1][b-1];
        printf("%d\n", ans);
    }

















  return 0;
}
