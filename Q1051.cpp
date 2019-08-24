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
int a[51][51];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++)
            scanf("%1d",&a[i][j]);
        }
    int k = min(n, m);
    while (k >= 1) {
        for (int i = 0 ; i <= n-k; i++) {
            for (int j = 0 ; j <= m-k ; j++) {
                if (a[i][j] == a[i][j+k-1] && a[i][j+k-1]== a[i+k-1][j+k-1]  && a[i+k-1][j]== a[i+k-1][j+k-1]) {
                    cout << k*k;
                    return 0;
                }
            }
        }
        k--;
    }







    return 0;
}
