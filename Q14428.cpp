#include <bits/stdc++.h>
#define inf 1500000000

using namespace std;
int tree[400040][2];
int a[100001];
int treesize;

void init(int node, int left, int right) {
    if (left == right) {
        tree[node][0] = a[left];
        tree[node][1] = left;
    }
    else {
        init(node*2, left, (left+right)/2);
        init(node*2 +1, (left+right)/2+1, right);
        if (tree[node*2][0] <= tree[node*2+1][0]) {
            tree[node][0] = tree[node*2][0];
            tree[node][1] = tree[node*2][1];
        }
        else {
            tree[node][0] = tree[node*2+1][0];
            tree[node][1] = tree[node*2+1][1];
        }
    }
}

void update(int i, int value) {
    i += treesize - 1;
    tree[i][0] = value;
    while(i > 1) {
        i /= 2;
        if (tree[i*2][0] <= tree[i*2+1][0]) {
            tree[i][0] = tree[i*2][0];
            tree[i][1] = tree[i*2][1];
        }
        else {
            tree[i][0] = tree[i*2+1][0];
            tree[i][1] = tree[i*2+1][1];
        }
    }
}
pair<int , int> query(int node, int left, int right, int nodeleft, int noderight) {
    if (right < nodeleft || left > noderight){
        return make_pair(inf, 0);
    }
    else if (left <= nodeleft && noderight <= right) {
        return make_pair(tree[node][0], tree[node][1]);
    }
    else {
        auto p1 = query(node*2, left, right, nodeleft , (nodeleft+noderight)/2);
        auto p2 = query(node*2+1, left, right, (nodeleft+noderight)/2+1, noderight);
        if (p1.first <= p2.first) {
            return p1;
        }
        else {
            return p2;
        }
    }
}

int main() {
    int n;
    for (int i = 0 ; i <= 100000 ; i++) {
        a[i] = inf;
    }
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
    }
    treesize = 1;
    while(treesize < n) {
        treesize *= 2;
    }
    init(1, 1, treesize);

    int m;
    scanf("%d", &m);

    for (int i = 0 ; i < m ; i++){
        int w, p, q;
        scanf("%d %d %d", &w, &p, &q);
        if (w == 1) {
            update(p, q);
        }
        else {
            printf("%d\n", query(1, p, q, 1, treesize).second);
        }
    }
















  return 0;
}
