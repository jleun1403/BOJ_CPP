    #include <bits/stdc++.h>
    #define inf 1234567

    using namespace std;
    long long dp[1001][10];

    int main() {
        ios_base::sync_with_stdio(false);
        for (int i = 0 ; i < 10 ; i++)
            dp[1][i] = 1;
        for (int i = 2 ; i <= 1000 ; i++){
            dp[i][1] = (dp[i-1][4] + dp[i-1][2]) % inf;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3] + dp[i-1][5]) % inf;
            dp[i][3] = (dp[i-1][2] + dp[i-1][6]) % inf;
            dp[i][4] = (dp[i-1][1] + dp[i-1][5] + dp[i-1][7]) % inf;
            dp[i][5] = (dp[i-1][2] + dp[i-1][4] + dp[i-1][6] + dp[i-1][8]) % inf;
            dp[i][6] = (dp[i-1][3] + dp[i-1][5] + dp[i-1][9]) % inf;
            dp[i][7] = (dp[i-1][4] + dp[i-1][8] + dp[i-1][0]) % inf;
            dp[i][8] = (dp[i-1][5] + dp[i-1][7] + dp[i-1][9]) % inf;
            dp[i][9] = (dp[i-1][6] + dp[i-1][8]) % inf;
            dp[i][0] = (dp[i-1][7]) % inf;

        }
        int n;
        cin >> n;
        for (int i = 0 ; i < n ; i++){
            int a;
            cin >> a;
            long long sum = 0;
            for (int j = 0 ; j < 10 ; j ++) {
                sum += dp[a][j];
            }
            sum %= inf;
            cout << sum << '\n';
        }
















      return 0;
    }
