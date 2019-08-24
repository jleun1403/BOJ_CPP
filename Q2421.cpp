#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
bool isPrime[1000001];
int dp[1000][1000];
int n;

void start() {
    isPrime[0] = false;
    isPrime[1] = false;
    for (long long i = 2LL; i <= 1000000 ; i++) {
        if (isPrime[i]) {
            for (long long j = i*i ; j <= 1000000 ; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int go(int x, int y) {
    if (x > n || y > n)
        return 0;
    if (x == n && y == n) {
        if (isPrime[stoi(to_string(x) + to_string(y))]) {
            return 1;
        }
        else return 0;
    }
    if (dp[x][y] != -1)
        return dp[x][y];
    int ans = 0;
    if (isPrime[stoi(to_string(x) + to_string(y))])
        ans = 1;
    return dp[x][y] = ans + max(go(x, y+1), go(x+1, y));

}


int main() {
    memset(isPrime, true, sizeof(isPrime));
    start();
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    printf("%d", go(1, 1) - 1);
















  return 0;
}
