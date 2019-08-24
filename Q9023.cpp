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
int C, D, d;
int testcase;
int xday, yday;
vector<int> px;
vector<int> py;
int dp[200][100][100][2][2];

int go(int n, int x, int y, int rx, int ry) {
    if (x == xday && y == yday)
        return 0;
    else if (x > xday || y > yday)
        return inf;
    if (dp[n][x][y][rx][ry] != -1)
        return dp[n][x][y][rx][ry];
    int ans = inf;
    //both practice
    if (px[x] == py[y])
        ans = go(n+1, x+1, y+1, 0, 0) + C;
    else
        ans = go(n+1, x+1, y+1, 0, 0) + 2*C;
    // x rest y practice
    if (rx == 0)
        ans = min(ans, go(n+1, x, y+1, 1, 0) + C + D + d);
    else
        ans = min(ans, go(n+1, x, y+1, 1, 0) + C + d);
    // y rest x practice
    if (ry == 0)
        ans = min(ans, go(n+1, x+1, y, 0, 1) + C + D + d);
    else
        ans = min(ans, go(n+1, x+1, y, 0, 1) + C + d);
    return dp[n][x][y][rx][ry] = ans;
}

int main() {
    scanf("%d", &testcase);
    while(testcase--) {
        memset(dp, -1, sizeof(dp));
        scanf("%d %d %d", &C, &D, &d);
        int k;
        scanf("%d", &k);
        while(k != 0) {
            px.push_back(k);
            scanf("%d", &k);
        }
        scanf("%d", &k);
        while(k != 0) {
            py.push_back(k);
            scanf("%d", &k);
        }
        xday = px.size();
        yday = py.size();
        printf("%d\n", go(0, 0 ,0 ,0 ,0));
        px.clear();
        py.clear();
    }

















  return 0;
}
