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
int tree[400040];
long long ans[100001];

pair<int, int> a[100001];

void init(int node, int nodeleft, int noderight) {
    if (nodeleft == noderight) {
        tree[node] = 1;
    }
    else {
        init(node*2, nodeleft, (nodeleft+noderight)/2);
        init(node*2+1, (nodeleft+noderight)/2+1, noderight);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

int query(int node, int nodeleft, int noderight, int left, int right){
    if (noderight < left || right < nodeleft)
        return 0;
    else if (left <= nodeleft && noderight <= right) {
        return tree[node];
    }
    else {
        int m1 = query(node*2, nodeleft, (nodeleft+noderight) / 2, left, right);
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
        int k;
        scanf("%d", &k);
        a[i] = {k, i};
    }


    sort(a+1, a+n+1);

    init(1, 1, n);
    long long total = 0;
    int task = n;
    for (int i = 1 ; i <= n ; i++) {
        int lapse = a[i].first - a[i-1].first;
        total += (long long)task*lapse;
        int q = query(1, 1, n, a[i].second+1, n);
        ans[a[i].second] = total - q;
        update(1, 1, n, a[i].second , -1);
        task--;
    }
    for (int i = 1 ; i<= n ; i++) {
        printf("%lld\n", ans[i]);
    }
















  return 0;
}
