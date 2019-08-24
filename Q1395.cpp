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
int n, m, close;
int sumtree[5000000];
bool lazy[5000000];

void update_lazy(int node, int left, int right) {
    if (lazy[node]) {
        sumtree[node] = (right -left +1) - sumtree[node];
        if (left != right) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        lazy[node] = false;
    }
}

void update_range(int node, int left, int right, int nl, int nr) {
    update_lazy(node, nl, nr);
    if (left > nr || nl > right) {
        return;
    }
    else if (nl >= left && right >= nr) {
        sumtree[node] = (nr - nl + 1) - sumtree[node];
        if (nl != nr) {
            lazy[2*node] = !lazy[2*node];
            lazy[2*node+1] = !lazy[2*node+1];
        }
    }
    else {
        int mid = (nl + nr)/2;
        update_range(node*2, left, right, nl, mid);
        update_range(node*2+1, left, right, mid+1, nr);
        sumtree[node] = sumtree[node*2] + sumtree[node*2+1];
    }
}

int query(int node, int left, int right, int nl, int nr) {
    update_lazy(node, nl, nr);
    if (left > nr || nl > right) {
        return 0;
    }
    else if (nl >= left && right >= nr) {
        return sumtree[node];
    }
    else {
        int mid = (nl + nr)/2;
        int m1 = query(node*2, left, right, nl, mid);
        int m2 = query(node*2+1, left, right, mid+1, nr);
        return m1+m2;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int temp = 1;
    while(temp < n){
        temp = temp*2;
    }
    close = temp;
    for (int i = 0 ; i < m ; i++) {
        int task, from, to;
        scanf("%d %d %d", &task, &from, &to);
        if (task == 0) {
            update_range(1, from, to, 1, close);
        }
        else {
            printf("%d\n", query(1, from, to, 1, close));
        }
    }



















  return 0;
}
