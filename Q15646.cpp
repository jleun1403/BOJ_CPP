#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int n, m, q;
long long tree[5005][5005];

void update(int x, int y, long long val) {
    for (int i = x ; i <= n ; i += i&-i) {
        for (int j = y ; j <= m ; j += j&-j) {
            tree[i][j] += val;
        }
    }
}

void update(int x1, int y1, int x2, int y2, long long val) {
    update(x1, y1, val);
    update(x1, y2+1, -val);
    update(x2+1, y1, -val);
    update(x2+1, y2+1, val);
}

long long query(int x, int y) {
    long long ans = 0LL;
    for (int i = x ; i > 0 ; i -= i&-i) {
        for (int j = y ; j > 0 ; j -= j&-j) {
            ans += tree[i][j];
        }
    }
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0 ; i < q ; i++) {
        int w;
        scanf("%d", &w);
        if (w == 1) {
            int x1, x2, y1, y2;
            long long d;
            scanf("%d %d %d %d %lld", &x1, &y1, &x2, &y2, &d);
            update(x1, y1, x2, y2, d);
        }
        else {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%lld\n", query(x, y));
        }
    }

















  return 0;
}
