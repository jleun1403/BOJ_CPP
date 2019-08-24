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

long long tree[400050];
int a[100001];

void init(int node, int left, int right) {
    if (left == right) {
        if (a[left] < 0)
            tree[node] = 1LL;
        else if (a[left] > 0)
            tree[node] = 0LL;
        else
            tree[node] = (long long)inf;
    }
    else {
        init(node*2, left, (left+right)/2);
        init(node*2+1, (left+right)/2+1, right);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

long long query(int node, int nodeleft, int noderight, int left, int right) {
    if (noderight < left || right < nodeleft) {
        return 0;
    }
    else if (left <= nodeleft && noderight <= right) {
        return tree[node];
    }
    else {
        long long m1 = query(node*2, nodeleft, (nodeleft+noderight)/2, left, right);
        long long m2 = query(node*2+1, (nodeleft+noderight)/2+1, noderight, left, right);
        return m1 + m2;
    }
}

void update(int node, int nodeleft, int noderight, int i, int val) {
    if (i < nodeleft || i > noderight)
        return;
    tree[node] += val;
    if (nodeleft != noderight) {
        update(node*2, nodeleft, (nodeleft+noderight)/2, i, val);
        update(node*2+1, (nodeleft+noderight)/2+1, noderight, i, val);
    }
}

int main() {
    int n, k;
    while(~scanf("%d %d", &n, &k)){
        memset(tree, 0, sizeof(tree));
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n ; i++) {
            scanf("%d", &a[i]);
        }
        init(1, 1, n);
        for (int i = 1; i <= k ; i++) {
            char task;
            scanf(" %c", &task);
            if (task == 'C') {
                int index, val;
                scanf("%d %d", &index, &val);
                if (a[index] * val > 0) {
                    continue;
                }
                else if (a[index] > 0 &&  val < 0) {
                    update(1, 1, n, index, 1);
                }
                else if (a[index] < 0 && val > 0) {
                    update(1, 1, n, index, -1);
                }
                else if (a[index] == 0 && val < 0) {
                    update(1, 1, n, index, -inf+1);
                }
                else if (a[index] == 0 && val > 0) {
                    update(1, 1, n, index, -inf);
                }
                else if (a[index] > 0 && val == 0) {
                    update(1, 1, n, index, inf);
                }
                else if (a[index] < 0 && val == 0) {
                    update(1, 1, n, index, inf);
                }
                a[index] = val;
            }
            else if (task == 'P') {
                int left, right;
                scanf("%d %d", &left, &right);
                long long q = query(1, 1, n, left, right);
                if (q >= (long long)inf) {
                    printf("0");
                }
                else if (q % 2LL) {
                    printf("-");
                }
                else {
                    printf("+");
                }
            }
        }
        printf("\n");
    }
















  return 0;
}
