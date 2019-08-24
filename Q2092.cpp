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

int a[4001];
int dp[201][4001];
int num[201];

int main() {
    ios_base::sync_with_stdio(false);
    int T, A, S, B;
    cin >> T >> A >> S >> B;
    for (int i = 1 ; i <= A ; i++) {
        cin >> a[i];
        num[a[i]] += 1;
    }
    for (int i = 1 ; i <= T ; i++) {
        for (int k = 0 ; k <= num[i] ; k++) {
            dp[i][k] += 1;
        }

        for (int j = 1 ; j <= A ; j++) {
            dp[i][j] += dp[i-1][j];

            for (int k = 1 ; k <= num[i] ; k++) {
                if (j - k > 0)
                    dp[i][j] += dp[i-1][j-k];
            }
            dp[i][j] %= 1000000;
        }
    }

    int sum = 0;
    for (int i = S ; i <= B ; i++) {
        sum += dp[T][i];
    }
    cout << sum %1000000;















  return 0;
}
