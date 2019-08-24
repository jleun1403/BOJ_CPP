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
int position[200001];
int a[100001];
int tree[800010];
int testcase, n, m;

void init(int node, int left, int right) {
    if (left == right) {
        if (left > m)
            tree[node] = 1;
        else
            tree[node] = 0;
    } else {
        init(node*2, left, (left+right)/2);
        init(node*2+1, (left+right)/2+1, right);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

int query(int node, int nodeleft, int noderight, int left, int right) {
    if (noderight < left || right < nodeleft)
        return 0;
    else if (left <= nodeleft && noderight <= right) {
        return tree[node];
    } else {
        int m1 = query(node*2, nodeleft, (nodeleft+noderight)/2, left, right);
        int m2 = query(node*2+1, (nodeleft+noderight)/2+1, noderight, left, right);
        return m1 + m2;
    }
}

void update(int node, int nodeleft, int noderight, int i,int value) {
    if (i < nodeleft || i > noderight)
        return;
    else {
        tree[node] += value;
        if (nodeleft != noderight) {
            update(node*2, nodeleft, (nodeleft+noderight)/2, i, value);
            update(node*2+1, (nodeleft+noderight)/2+1, noderight, i, value);
        }
    }
}


int main() {
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n ; i++) {
            position[i] = m+i;
        }
        init(1, 1, n+m);
        for (int i = m ; i > 0 ; i--) {
            int movie;
            scanf("%d", &movie);
            int num = query(1, 1, n+m, 1, position[movie]-1);
            printf("%d ", num);
            update(1, 1, n+m, position[movie], -1);
            update(1, 1, n+m, i, 1);
            position[movie] = i;
        }
        printf("\n");
    }















    return 0;
}
