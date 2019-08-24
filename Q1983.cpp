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

int a[401];
int b[401];
int t,n,m;
int dp[401][401][802];
vector<int> aa, bb;

int go(int i, int j, int c1, int c2) {
    if(i == n || j == m)
        return 0;
    if(dp[i][j][c1+c2] != inf)
        return dp[i][j][c1+c2];
    int ans = -inf;

    if (c1 > 0) {
        ans = max(ans, go(i, j+1, c1-1, c2));
    }
    if (c2 > 0) {
        ans = max(ans, go(i+1, j, c1, c2-1));
    }
    ans = max(ans, go(i+1, j+1, c1, c2) + aa[i]*bb[j]);

    return dp[i][j][c1+c2] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> t;

    for (int i = 0 ; i < t ; i++) {
        cin >> a[i];
        if (a[i] != 0) {
            n++;
            aa.push_back(a[i]);
        }
    }
    for (int i = 0 ; i < t ; i++) {
        cin >> b[i];
        if (b[i] != 0) {
            m++;
            bb.push_back(b[i]);
        }
    }
    for (int i = 0 ; i <= 400 ; i++){
        for (int j = 0 ; j <=400 ; j++) {
            for (int k = 0 ; k <=801 ; k++) {
                dp[i][j][k] = inf;
            }
        }
    }
    int c1 = t - n;
    int c2 = t - m;
    cout << go(0, 0, c1, c2);
















  return 0;
}
