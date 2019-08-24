#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int n, m;
long long a[1025][1025];
long long tree[1025][1025];

void update(int x, int y, int val) {
    for (int i = x ; i <= n ; i += (i & -i)) {
        for (int j = y ; j <= n; j += (j & -j)) {
            tree[i][j] += val;
        }
    }
}

long long query(int x, int y) {
    long long q = 0LL;
    for (int i = x ; i > 0 ; i -= i&-i) {
        for (int j = y ; j > 0 ; j -= j&-j) {
            q += tree[i][j];
        }
    }
    return q;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1; j <= n ; j++) {
            long long k;
            scanf("%lld", &k);
            update(i, j, k);
            a[i][j] = k;
        }
    }
    for (int i = 0 ; i < m ; i++) {
        int w;
        scanf("%d", &w);
        if (w == 0) {
            int x, y, c;
            scanf("%d %d %d", &x, &y, &c);
            update(x, y, c - a[x][y]);
            a[x][y] = c;
        }
        else{
            int x1, x2, y1, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            printf("%lld\n", query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1-1, y1-1));
        }
    }

















  return 0;
}
