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
#define inf 2000000000

using namespace std;
int n, m;
int mintree[300001];
int maxtree[300001];
int a[100001];

int minquery(int node, int left, int right, int nl, int nr) {
    if (nr < left || right < nl) {
        return inf;
    }
    else if (left <= nl && nr <= right) {
        return mintree[node];
    }
    else {
        int m1 = minquery(node*2, left, right, nl, (nl+nr)/2);
        int m2 = minquery(node*2+1, left, right, (nl+nr)/2+1, nr);
        return min(m1, m2);
    }

}

int maxquery(int node, int left, int right, int nl, int nr) {
    if (nr < left || right < nl) {
        return -inf;
    }
    else if (left <= nl && nr <= right) {
        return maxtree[node];
    }
    else {
        int m1 = maxquery(node*2, left, right, nl, (nl+nr)/2);
        int m2 = maxquery(node*2+1, left, right, (nl+nr)/2+1, nr);
        return max(m1, m2);
    }

}


void init(int node, int start, int end) {
    if (start == end) {
        mintree[node] = a[start];
        maxtree[node] = a[start];
    }
    else {
        init(2*node, start, (start + end) / 2);
        init(2*node+1, (start+end)/2 +1, end);
        mintree[node] = min(mintree[2*node], mintree[2*node+1]);
        maxtree[node] = max(maxtree[2*node], maxtree[2*node+1]);
    }
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
    }
    init(1, 1, n);
    for (int i = 0 ; i < m ; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        printf("%d ", minquery(1, from, to, 1, n));
        printf("%d\n", maxquery(1, from, to, 1, n));
    }

















  return 0;
}
