#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;
int a[1001][1001];
int d[1001][1001];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    d[1][1] = a[1][1];
    for (int i = 2 ; i <= n ; i++) {
        d[i][1] = a[i][1] + d[i-1][1];
    }
    for (int i = 2 ; i <= m ; i++) {
        d[1][i] = a[1][i] + d[1][i-1];
    }
    for (int i = 2 ; i <= n ; i++) {
        for (int j = 2 ; j <= m ; j++) {
            d[i][j] = max(max(d[i-1][j], d[i][j-1]) , d[i-1][j-1]) + a[i][j];
        }
    }
    cout << d[n][m];







  return 0;
}
