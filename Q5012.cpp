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
int pre[100001];
int pro[100001];
int a[100001];
int cnt[100001];

int tree[400050];

int query(int node, int nodeleft, int noderight, int left, int right) {
    if (noderight < left || right < nodeleft) {
        return 0;
    }
    if (left <= nodeleft && noderight <= right)
        return tree[node];
    else {
        int m1 = query(node*2, nodeleft, (nodeleft+noderight)/2, left, right);
        int m2 = query(node*2+1, (nodeleft+noderight)/2+1, noderight, left, right);
        return m1 + m2;
    }
}

void update(int node, int nodeleft, int noderight, int i, int value) {
    if (i < nodeleft || i > noderight)
        return;
    tree[node] += value;
    if (nodeleft != noderight) {
        update(node*2, nodeleft, (nodeleft+noderight)/2, i, value);
        update(node*2+1, (nodeleft+noderight)/2+1, noderight, i, value);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
        int q = query(1, 1, n, a[i]+1, n);
        pre[i] = q;
        update(1, 1, n, a[i], 1);
    }
    reverse(a+1, a+1+n);
    memset(tree, 0, sizeof(tree));
    for (int i = 1 ; i <= n ; i++) {
        int q = query(1, 1, n, 1, a[i]-1);
        pro[n+1-i] = q;
        update(1, 1, n, a[i], 1);
    }

    long long ans = 0LL;
    for (int i = 1; i <= n ; i++) {
        ans += ((long long)pre[i] * pro[i]);
    }
    printf("%lld", ans);
















  return 0;
}
