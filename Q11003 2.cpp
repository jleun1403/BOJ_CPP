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
#define inf 987654321

using namespace std;
int n, m;
int mintree[20000050];
int a[5000001];
int treesize;

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



void init(int node, int start, int end) {
    if (start == end) {
        mintree[node] = 2*inf;
    }
    else {
        init(2*node, start, (start + end) / 2);
        init(2*node+1, (start+end)/2 +1, end);
        mintree[node] = min(mintree[2*node], mintree[2*node+1]);
    }
}

void update(int node, int left, int right, int i, int value) {
    i += treesize - 1;
    mintree[i] = value;
    i /= 2;
    while(i > 0) {
        mintree[i] = min(mintree[i*2] , mintree[i*2 +1]);
        i /= 2;
    }
}


int main() {
    scanf("%d %d", &n, &m);


    treesize = 1;

    while(treesize < m)
        treesize *= 2;

    init(1, 1, treesize);

    for (int i = 1 ; i <= m ; i++) {
        scanf("%d", &a[i]);
        update(1, 1, treesize, i, a[i]);
        printf("%d ", mintree[1]);
    }
    int oldest = 1;
    for (int i = m+1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
        update(1, 1, treesize, oldest++, a[i]);
        printf("%d ", mintree[1]);
        if (oldest > m)
            oldest = 1;
    }




















  return 0;
}
