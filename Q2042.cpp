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
int n, m, k;
int a[2000001];
long long sumtree[3000000];
int close;

int closest(int x) {
    int a = 0;
    for (int i = 0 ; i < 31 ; i++) {
        if ((1 << i) >= x)
            return (1 << i);
    }
}
void init(int node, int left, int right) {
    if (left == right){
        sumtree[node] = (long long)a[left];
    }
    else {
        init(node*2, left, (left+right)/2);
        init(node*2 +1, (left+right)/2+1, right);
        sumtree[node] = sumtree[node*2] + sumtree[node*2+1];
    }
}

void update(int p, int q) {
    p = p + close - 1;
    sumtree[p] = (long long)q;
    while(p > 1) {
        p /= 2;
        sumtree[p] = sumtree[p*2] + sumtree[p*2 + 1];
    }
}

long long query(int node, int l, int r, int nl, int nr) {
    if (nl > r || l > nr) {
        return 0LL;
    }
    else if (nl >= l && r >= nr) {
        return sumtree[node];
    }
    else {
        long long m1 = query(node*2, l, r, nl, (nl+nr)/2);
        long long m2 = query(node*2 +1, l, r, (nl+nr)/2 +1, nr);
        return m1 + m2;
    }

}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    close = closest(n);
    for (int i = 1; i <= n ; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n+1 ; i <= close ; i++) {
        a[i] = 0;
    }

    init(1, 1, close);
    for (int i = 0 ; i < m + k ; i++) {
        int task, p, q;
        scanf("%d %d %d", &task, &p, &q);
        if (task == 1) {
            update(p, q);
        }
        else {
            printf("%lld\n", query(1, p, q, 1, close));
        }
    }


















  return 0;
}
