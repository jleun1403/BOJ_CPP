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
int a, b, c;
string s1, s2;
int l1, l2;
int dp[3000][3000];

int go(int n, int m) {
    if (n == l1 && m == l2) {
        return 0;
    }
    else if (n == l1) {
        return b*(l2 - m);
    }
    else if (m == l2) {
        return b*(l1 - n);
    }
    if (dp[n][m] != inf)
        return dp[n][m];
    int ret;
    if (s1[n] == s2[m]) {
        ret = max(go(n+1, m+1) + a, max(go(n, m+1) + b, go(n+1, m) + b));
    }
    else {
        ret = max(go(n+1, m+1) + c, max(go(n, m+1) + b, go(n+1, m) + b));
    }
    return dp[n][m] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c >>s1 >> s2;
    l1 = s1.length();
    l2 = s2.length();
    for (int i = 0 ; i < 3000 ; i++) {
        for (int j = 0 ; j < 3000 ; j++) {
            dp[i][j] = inf;
        }
    }
    cout << go(0, 0);















  return 0;
}
