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
int d[501][501];
int a[501][2];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1 ; i<= n ; i++)
        scanf("%d %d", &a[i][0], &a[i][1]);
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (i!=j)
                d[i][j] = 2147483647;
        }
    }
    for (int i = 1; i < n ; i++) {
        d[i][i+1] = a[i][0] * a[i][1] * a[i+1][1];
    }
    for (int k = 2; k < n ; k++) {
        for (int j = 1; j <=n - k ; j++) {
            for (int i = j ; i < j+k ; i++) {
                d[j][j+k] = min(d[j][j+k], d[j][i] + d[i+1][j+k] + a[j][0] * a[i][1] * a[j+k][1]);
            }
        }
    }
    printf("%d", d[1][n]);








  return 0;
}
