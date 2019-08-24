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
map<int, int> order;
int a[500001];
int tree[2000040];

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = 1;
    }
    else {
        init(node*2, left, (left+right)/2);
        init(node*2+1, (left+right)/2+1, right);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

int query(int node, int nodeleft, int noderight, int left, int right) {
    if (noderight < left || right < nodeleft)
        return 0;
    else if (left <= nodeleft && noderight <= right) {
        return tree[node];
    }
    else {
        int m1 = query(node*2, nodeleft, (nodeleft+noderight)/2 , left, right);
        int m2 = query(node*2+1, (nodeleft+noderight)/2+1, noderight, left, right);
        return m1 + m2;
    }

}

void update(int node, int left, int right, int i, int value) {
    if (i < left || i > right)
        return;
    tree[node] += value;
    if (left != right) {
        update(node*2, left, (left+right)/2, i, value);
        update(node*2+1, (left+right)/2+1, right, i, value);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i<= n ; i++) {
        int k;
        scanf("%d" ,&k);
        order[k] = i;
    }
    for (int i = 1; i <= n ; i++) {
        int k;
        scanf("%d", &k);
        k = order[k];
        a[i] = k;
    }
    long long ans = 0LL;
    init(1, 1, n);
    for (int i = 1 ; i <= n ; i++) {
        ans += query(1, 1, n, 1, a[i] - 1);
        update(1, 1, n, a[i], -1);
    }
    printf("%lld", ans);


















  return 0;
}
