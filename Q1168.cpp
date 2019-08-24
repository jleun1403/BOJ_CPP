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
    if (left == right)
        return left;
    else {
        if (tree[node*2] >= k)
            return kth(node*2, left, (left+right)/2, k);
        else
            return kth(node*2+1, (left+right)/2+1, right, k - tree[node*2]);
    }
}

void update(int node, int left, int right, int i, int value) {
    if (i <left || i > right)
        return;
    tree[node] += value;
    if (left != right) {
        update(node*2, left, (left+right)/2, i, value);
        update(node*2+1, (left+right)/2+1, right, i, value);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int first = m;
    init(1, 1, n);
    printf("<%d, ", m);
    update(1, 1, n, m, -1);
    int term = m-1;
    int remain = n-1;
    for (int i = 1 ; i < n-1 ; i++) {
        int next = m + term;
        if (next > remain) {
            if (next % remain == 0)
                next = remain;
            else
                next = next % remain;
        }
        int k = kth(1, 1, n, next);
        printf("%d, ", k);
        update(1, 1, n, k, -1);
        m = next;
        remain--;
    }
    printf("%d>", kth(1, 1, n, 1));














  return 0;
}
