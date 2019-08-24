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

int a[1000001];
int tree[4000040];

void update(int node, int nodeleft, int noderight, int i, int value) {
    if (i < nodeleft || i > noderight) {
        return;
    }
    tree[node] += value;
    if (nodeleft != noderight) {
        update(node*2, nodeleft, (nodeleft+noderight)/2, i, value);
        update(node*2+1, (nodeleft+noderight)/2+1, noderight, i, value);
    }
}

int kth(int node, int nodeleft, int noderight, int k){
    if (nodeleft == noderight) {
        return nodeleft;
    }
    else {
        if (tree[node*2] >= k) {
            return kth(node*2, nodeleft, (nodeleft+noderight)/2, k);
        }
        else {
            return kth(node*2+1, (nodeleft+noderight)/2+1, noderight, k-tree[node*2]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i <n; i++) {
        int task;
        scanf("%d", &task);
        if (task == 1) {
            int target;
            scanf("%d", &target);
            int k = kth(1, 1, 1000000, target);
            update(1, 1, 1000000, k, -1);
            printf("%d\n", k);
        }
        else if (task == 2) {
            int target, number;
            scanf("%d %d", &target, &number);
            update(1, 1, 1000000, target, number);
        }
    }
















  return 0;
}
