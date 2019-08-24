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
int n, m;
int dp[1000][1000][3];
int a[1000][1000];

int go(int x, int y, int dir) {
    if (x == n-1 && y == m-1)
        return a[n-1][m-1];
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return -inf;
    }
    if (dp[x][y][dir] != -1) {
        return dp[x][y][dir];
    }
    int ans;
    if (dir == 0) {
        ans = go(x+1, y, 0);
        ans = max(ans, go(x, y-1, 2));
        ans = max(ans, go(x, y+1, 1));
    }
    if (dir == 1) {
        ans = max(go(x+1, y, 0), go(x, y+1, 1));
    }
    if (dir == 2) {
        ans = max(go(x+1, y, 0) ,go(x, y-1, 2));
    }
    ans += a[x][y];
    return dp[x][y][dir] = ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0, 0);
















  return 0;
}
