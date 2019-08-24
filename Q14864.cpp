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
int n, m;
int ath[100001];
int bth[100001];
int ansfront[100001];
int ansback[100001];

long long tree[400009];

void init(int node, int left, int right) {
    if (left == right)
        tree[node] = 1;
    else {
        init(node*2, left, (left+right) / 2);
        init(node*2+1, (left+right)/2 + 1, right);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void update(int node, int nodeleft, int noderight, int i, int val) {
    if (i < nodeleft ||i > noderight)
        return;
    else {
        tree[node] += val;
        if (nodeleft != noderight) {
            update(node*2, nodeleft, (nodeleft+noderight)/2, i, val);
            update(node*2+1, (nodeleft+noderight)/2+1, noderight, i, val);
        }
    }
}

int kth(int node, int nodeleft, int noderight, int k) {
    if (nodeleft == noderight)
        return nodeleft;
    else {
        if (tree[node*2] >= k)
            return kth(node*2, nodeleft, (nodeleft+noderight)/2, k);
        else
            return kth(node*2+1, (nodeleft+noderight)/2+1, noderight, k - tree[2*node]);
    }
}


int main() {
    scanf("%d %d", &n, &m);
    if ( (long long)m > (long long)(n-1)*n/2) {
        printf("-1");
        return 0;
    }
    for (int i = 0 ; i < m ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        ath[a]++;
        bth[b]++;
    }
    init(1, 1, n);

    for (int i = 1; i <= n ; i++) {
        int aa = kth(1, 1, n, ath[i] + 1);
        ansfront[i] = aa;
        update(1, 1, n, aa, -1);
    }
    init(1, 1, n);
    for (int i = n ; i > 0 ; i--) {
        bth[i] = (i-1) - bth[i];
        int bb = kth(1, 1, n, bth[i] + 1);
        ansback[i] = bb;
        update(1, 1, n, bb, -1);
        if (ansback[i] != ansfront[i]) {
            printf("-1");
            return 0;
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        printf("%d ", ansfront[i]);
    }
















  return 0;
}
