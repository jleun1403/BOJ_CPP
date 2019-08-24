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
#define inf 987654321

using namespace std;
int n;
short a[100001][3];
short s[100001][3];
short b[100001][3];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i++) {
        scanf("%hd %hd %hd", &a[i][0], &a[i][1], &a[i][2]);
    }
    b[1][0] = max(a[1][0], a[1][1]);
    b[1][1] = max(a[1][0], max(a[1][1], a[1][2]));
    b[1][2] = max(a[1][1], a[1][2]);
    s[1][0] = min(a[1][0], a[1][1]);
    s[1][1] = min(a[1][0], min(a[1][1], a[1][2]));
    s[1][2] = min(a[1][1], a[1][2]);

    for (int i = 2; i <= n ; i++) {
        s[i][0] = min(s[i-1][0], s[i-1][1]) + a[i][0];
        s[i][1] = min(s[i-1][0], min(s[i-1][1], s[i-1][2])) + a[i][1];
        s[i][2] = min(s[i-1][1], s[i-1][2]) + a[i][2];
        b[i][0] = max(b[i-1][0], b[i-1][1]) + a[i][0];
        b[i][1] = max(b[i-1][0], max(b[i-1][1], b[i-1][2])) + a[i][1];
        b[i][2] = max(b[i-1][1], b[i-1][2]) + a[i][2];
    }
    printf("%d %d", max(b[n][0], max(b[n][1], b[n][2])), min(s[n][0], min(s[n][1], s[n][2])));
















  return 0;
}
