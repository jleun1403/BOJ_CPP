#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int dp[1001][1001];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    for (int i = 1 ; i<= n ; i++) {
        for (int j = 1 ; j<= m ; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    int ans = dp[n][m];
    printf("%d\n", ans);
    stack<char> s;
    while(ans > 0) {
        if (s1[n-1] == s2[m-1]) {
            s.push(s1[n-1]);
            ans--;
            n--; m--;
        }
        else {
            if (dp[n][m] == dp[n-1][m]) {
                n--;
            }
            else m--;
        }
    }
    while(!s.empty()) {
        printf("%c", s.top());
        s.pop();
    }














  return 0;
}
