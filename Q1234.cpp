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

long long dp[11][101][101][101]; // dp[n][a][b][c] = filling nth floor using a, b, c's of RGBs.
long long last;
long long fact(long long n) {
    if (n == 1 || n == 0)
        return 1LL;
    return fact(n-1)*n;
}

long long go(int n, int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0)
        return 0;
    if (n == last + 1)
        return 1;
    if (dp[n][a][b][c] != -1)
        return dp[n][a][b][c];
    long long ret = 0;
    ret += go(n+1, a-n, b, c);
    ret += go(n+1, a, b-n, c);
    ret += go(n+1, a, b, c-n);
    if (n % 2 == 0){
        ret += go(n+1, a - n/2, b - n/2, c)*fact(n)/fact(n/2)/fact(n/2);
        ret += go(n+1, a - n/2, b, c - n/2)*fact(n)/fact(n/2)/fact(n/2);
        ret += go(n+1, a, b - n/2 , c- n/2)*fact(n)/fact(n/2)/fact(n/2);
    }
    if (n % 3 == 0){
        ret += go(n+1, a-n/3, b - n/3 , c - n/3)*fact(n)/fact(n/3)/fact(n/3)/fact(n/3);
    }
    return dp[n][a][b][c] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    long long a, b, c;
    cin >> last >>a >> b>>c;
    memset(dp, -1, sizeof(dp));
    cout <<go(1, a, b, c);
















  return 0;
}
