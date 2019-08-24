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
#define inf 1000000000

using namespace std;
int d[51][500001];
int a[51];
int n;
int go(int used, int diff) {
    if (used == n +1) {
        if (diff == 0)
            return 0;
        else
            return -inf;
    }
    if (diff > 500000)
        return -inf;
    if (d[used][diff] != -1)
        return d[used][diff];
    else {
        int ans = go(used+1, diff);
        ans = max(ans, go(used+1, diff + a[used]));
        if (a[used] >= diff)
            ans = max(ans, go(used+1, a[used] - diff) + diff);
        else
            ans = max(ans, go(used+1, diff - a[used]) + a[used]);
        return d[used][diff] = ans;
    }
}

int main() {
    scanf("%d", &n);
    memset(d, -1, sizeof(d));
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
    }
    if (go(0, 0) <= 0)
        printf("-1");
    else
        printf("%d", go(0, 0));
















  return 0;
}
