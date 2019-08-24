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
int close;
int a[2000001];
long long sumtree[5000001];
long long lazy[5000001];
void update_lazy(int node, int nl, int nr);
void init(int node, int left, int right) {
    if (left == right) {
        sumtree[node] = (long long)a[left];
    }
    else {
        init(2*node, left, (left+right)/2);
        init(2*node+1, (left+right)/2+1, right);
        sumtree[node] = sumtree[node*2] + sumtree[node*2+1];
    }
}

long long query(int node, int left, int right, int nl, int nr) {
    update_lazy(node, nl, nr);
    if (nl > right || left > nr) {
        return 0LL;
    }
    else if (nl >= left && right >= nr) {
        return sumtree[node];
    }
    else {
        long long m1 = query(2*node, left, right, nl, (nl+nr)/2);
        long long m2 = query(2*node+1, left, right, (nl+nr)/2 +1, nr);
        return m1 + m2;
    }
}

void update_range(int node, int left, int right, int nl, int nr, int q) {
    update_lazy(node, nl, nr);
    if (nl > right || left > nr) {
        return;
    }
    else if (nl >= left && right >= nr) {
        sumtree[node] += (nr - nl + 1LL) * q;
        if (nl != nr) {
            lazy[2*node] += (long long)q;
            lazy[2*node+1] += (long long)q;
        }
    }
    else {
        update_range(2*node, left, right, nl, (nl+nr)/2, q);
        update_range(2*node+1, left, right, (nl+nr)/2+1, nr, q);
        sumtree[node] = sumtree[node*2] + sumtree[node*2+1];
    }
}

void update_lazy(int node, int nl, int nr){
    if (lazy[node] != 0) {
        sumtree[node] += (nr - nl +1LL) * lazy[node];
        if (nl != nr) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}


int main() {
    scanf("%d %d %d", &n, &m, &k);
    int temp = 1;
    while(temp < n) {
        temp = temp*2;
    }
    close = temp;


    for (int i = 1 ; i <= n ; i++)
        scanf("%d", &a[i]);
    for (int i = n+1; i <= close ; i++) {
        a[i] = 0;
    }

    init(1, 1, close);

    for (int i = 0 ; i < m + k ; i++) {
        int t1;
        scanf("%d", &t1);
        if (t1 ==1) {
            int from, to, diff;
            scanf("%d %d %d",&from, &to, &diff);
            update_range(1, from, to, 1, close, diff);
        }
        else {
            int from, to;
            scanf("%d %d", &from, &to);
            printf("%lld\n", query(1, from, to, 1, close));
        }
    }


















  return 0;
}
