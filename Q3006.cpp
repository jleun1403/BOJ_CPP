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

int tree[400400];
int a[100001];
int position[100001];

void init(int node, int nodeleft, int noderight) {
    if (nodeleft == noderight) {
        tree[node] = 1;
    }
    else {
        init(node*2, nodeleft, (nodeleft + noderight)/2);
        init(node*2+1, (nodeleft+noderight)/2+1, noderight);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

int query(int node, int nodeleft, int noderight, int left, int right) {
    if (noderight < left || right < nodeleft) {
        return 0;
    }
    else if (left <= nodeleft && noderight <= right) {
        return tree[node];
    }
    else {
        int m1 = query(node*2, nodeleft, (nodeleft+noderight)/2, left, right);
        int m2 = query(node*2+1, (nodeleft+noderight)/2+1, noderight, left, right);
        return m1+m2;
    }
}

void update(int node, int nodeleft, int noderight, int i, int value) {
    if (i < nodeleft || i > noderight)
        return;
    tree[node] += value;
    if (nodeleft != noderight) {
        update(node*2, nodeleft, (nodeleft+noderight)/2 ,i , value);
        update(node*2+1, (nodeleft+noderight)/2+1, noderight, i, value);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1 ; i<= n ;i++) {
        scanf("%d", &a[i]);
        position[a[i]] = i;
    }
    init(1, 1, n);
    int left = 1;
    int right = n;
    for (int i = 1; i<= n; i++) {
        if (i % 2) {
            int ans = query(1, 1, n, 1, position[left] - 1);
            printf("%d\n", ans);
            update(1, 1, n, position[left], -1);
            left++;
        }
        else {
            int ans = query(1, 1, n, position[right]+1, n);
            printf("%d\n", ans);
            update(1, 1, n, position[right], -1);
            right--;
        }
    }
















  return 0;
}
