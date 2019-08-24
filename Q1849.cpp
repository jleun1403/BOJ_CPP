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
int ans[1000001];
int tree[400050];

void init(int node, int left, int right) {
    if (left == right)
        tree[node] = 1;
    else {
        init(node*2, left, (left+right)/2);
        init(node*2+1, (left+right)/2+1, right);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void update(int node, int left, int right, int i, int value){
    if (i < left || i > right)
        return;
    tree[node] += value;
    if (left != right) {
        update(node*2, left, (left+right)/2, i, value);
        update(node*2+1, (left+right)/2+1, right, i, value);
    }
}

int kth(int node, int left, int right, int k) {
    if (left == right) {
        return left;
    }
    else {
        if (tree[node*2] >= k) {
            return kth(node*2, left, (left+right)/2, k);
        }
        else {
            return kth(node*2+1, (left+right)/2+1, right, k - tree[node*2]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    init(1, 1, n);
    for (int i = 1; i <= n ;i++) {
        int a;
        scanf("%d", &a);
        int k = kth(1, 1, n, a+1);
        update(1, 1, n, k, -1);
        ans[k] = i;
    }
    for (int i = 1 ; i<= n ;i++)
        printf("%d\n", ans[i]);
















  return 0;
}
