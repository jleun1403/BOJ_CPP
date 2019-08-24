#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;
int n, m;
int a[100001];
long long tree[300001];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    }
    else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);
        tree[node] = (long long)tree[node*2] + tree[node*2+1];
    }
}

long long query(int node, int left, int right, int nodeleft, int noderight) {
    if (nodeleft > right || left > noderight) {
        return 0LL;
    }
    else if (nodeleft >= left && right >= noderight) {
        return tree[node];
    }
    else {
        long long m1 = query(node*2, left, right, nodeleft, (nodeleft + noderight)/2);
        long long m2 = query(node*2+1, left, right, (nodeleft+noderight)/2+1, noderight);
        return m1+m2;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++)
        scanf("%d", &a[i]);
    init(1, 1, n);
    for (int i = 0 ; i < m ;i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        printf("%lld\n", query(1, from, to, 1, n));
    }


















  return 0;
}
