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

int score[5][5] = {{10, 8, 7, 5, 1}, {8, 6, 4, 3, 1}, {7, 4, 3, 2 ,1}, {5, 3, 2, 2, 1}, {1, 1, 1, 1, 0}};
int a[15][15];
int n, m;
int dp[200][1<<14];

int go(int x, int s) {
    if (x >= m*n)
        return 0;
    if (dp[x][s] != -1)
        return dp[x][s];
    int ans = 0;
    // this block is covered already
    if (s & 1) {
        ans = go(x+1, s >>1);
    }
    else {
        // skip
        ans = go(x+1, s >>1);
        if (x/m != n-1)
            ans = max(ans, go(x+1, ((s>>1)|(1<<(m-1)))) + score[a[x/m][x%m]][a[x/m +1][x%m]]);
        if ((s&(1<<1)) == 0 && x % m != m-1) {
            ans = max(ans, go(x+2, s >> 2)+ score[a[x/m][x%m]][a[x/m][x%m + 1]]);
        }
    }
    return dp[x][s] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            char c;
            scanf(" %c", &c);
            if (c == 'F')
                c = 'E';
            a[i][j] = c - 'A';
        }
    }
    memset(dp, -1, sizeof(dp));
    printf("%d", go(0, 0));














  return 0;
}
