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
int n;
int tree[4000011];
int a[1000001];

int query(int node, int nodeleft, int noderight, int left, int right) {
    if (noderight < left || right < nodeleft) {
        return -inf;
    }
    if (left <= nodeleft && noderight <= right)
        return tree[node];
    else {
        int m1 = query(node*2, nodeleft, (nodeleft+noderight)/2 , left, right);
        int m2 = query(node*2+1, (nodeleft+noderight)/2+1, noderight, left, right);
        return max(m1, m2);
    }
}

void update(int node, int left, int right, int i, int value) {
    if (i < left || i > right) return;
    tree[node] = max(tree[node], value);
    if (left != right) {
        update(node*2, left, (left+right)/2, i, value);
        update(node*2+1, (left+right)/2 +1, right, i, value);
    }

}

int main() {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n ; i++) {
        scanf("%d", &a[i]);
        int c = query(1, 1, 1000000, 1, a[i]-1);
        if (ans < c+1) {
            ans = c+1;
        }
        update(1, 1, 1000000, a[i], c+1);
    }
    printf("%d", ans);
















  return 0;
}
