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
#define MAX 65536

using namespace std;

int tree[1000050];
int a[250001];

void init(int node, int left, int right) {
    if (left == right)
        tree[node] = 1;
    else {
        init(node*2, left, (left+right)/2);
        init(node*2+1, (left+right)/2+1, right);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

int kth(int node, int left, int right, int k) {
    if (left == right) {
        return left;
    }
    else {
        if (k <= tree[node*2]) {
            return kth(node*2, left, (left+right)/2, k);
        }
        else {
            return kth(node*2+1, (left+right)/2+1, right, k - tree[node*2]);
        }
    }
}

void update(int node, int nodeleft, int noderight, int i, int val) {
    if (i < nodeleft || i > noderight)
        return;
    tree[node] += val;
    if (nodeleft != noderight){
        update(node*2, nodeleft, (nodeleft+noderight)/2, i, val);
        update(node*2+1, (nodeleft+noderight)/2+1, noderight, i, val);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1 ; i<= n ; i++) {
        scanf("%d", &a[i]);
    }

    long long ans = 0LL;

    int mid = (k+1)/2;

    for (int i = 1; i <= k ; i++) {
        update(1, 0, MAX, a[i], 1);
    }
    ans += kth(1, 0, MAX, mid);

    int oldest = 1;
    for (int i = k+1; i <= n ; i++){
        update(1, 0, MAX, a[oldest] , -1);
        update(1, 0, MAX, a[i], 1);
        ans += (long long)kth(1, 0, MAX, mid);
        oldest++;
    }
    printf("%lld", ans);
















  return 0;
}
