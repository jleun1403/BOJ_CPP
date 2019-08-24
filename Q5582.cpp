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

int dp[4001][4001];
int main() {
    ios_base::sync_with_stdio(false);
    string s1, s2;
    cin >> s1 >>s2;
    int n, m;
    n = s1.length();
    m = s2.length();
    s1 = " " + s1;
    s2 = " " + s2;
    int ans = 0;
    for (int i = 1; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > ans)
                    ans = dp[i][j];
            }
            else
                dp[i][j] = 0;
        }
    }

    printf("%d", ans);












  return 0;
}
