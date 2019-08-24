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
#define int_min -2100000000

using namespace std;
int a[101];
int d[101][51]; //d[i][j] -> ith added and j subgroups
int c[101][51];
int s[101];

int go(int n, int m) {
    if (m == 0) return 0;
    if (n <= 0) return int_min;
    if (c[n][m] == 1) return d[n][m];
    c[n][m] = 1;
    int ans = go(n-1, m);
    for (int i = 1 ; i <= n ; i++) {
        int temp = go(i-2, m-1) + s[n] - s[i-1];
        if (temp > ans)
            ans = temp;
    }
    return d[n][m] = ans;

}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ;i++) {
        scanf("%d", &a[i]);
    }
    s[1] = a[1];
    for (int i = 2 ; i <= n ; i++)
        s[i] = s[i-1] + a[i];
    cout << go(n, m);







  return 0;
}
