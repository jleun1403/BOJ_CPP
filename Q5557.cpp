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
int n;
long long d[101][21];
int a[101];

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
    }
    if (a[1] < 0 || a[1] > 20) {
        cout << 0;
        return 0;
    }
    d[1][a[1]] = 1LL;
    for (int i = 2;  i <= n-1 ; i++) {
        for (int j = 0 ; j <= 20 ; j++) {
            if (d[i-1][j] != 0) {
                if (a[i] + j <= 20) {
                    d[i][a[i] + j] += d[i-1][j];
                }
                if (j - a[i] >= 0) {
                    d[i][j-a[i]] += d[i-1][j];
                }
            }
        }
    }
    printf("%lld", d[n-1][a[n]]);





  return 0;
}
