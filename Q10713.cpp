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
int n, m;
int treesize;
int tree[4000010];
int lazy[4000010];

void update_lazy(int node, int nodeleft, int noderight) {
    if (lazy[node] != 0) {
        tree[node] += (noderight - nodeleft +1) * lazy[node];
        if (nodeleft != noderight) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(int node, int nodeleft, int noderight, int left, int right, int value) {
    update_lazy(node, nodeleft, noderight);
    if (noderight < left || right < nodeleft)
        return;
    if (left <= nodeleft && noderight <= right) {
        tree[node] += (noderight - nodeleft + 1) *value;
        if (nodeleft != noderight) {
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }
        return;
    }
    update_range(node*2, nodeleft, (nodeleft+noderight)/2, left, right, value);
    update_range(node*2+1, (nodeleft+noderight)/2+1, noderight, left, right, value);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    treesize = 1;

    while(treesize < n)
        treesize *= 2;

    vector<int> city;

    for (int i = 0 ; i < m ; i++) {
        int a;
        cin >> a;
        city.push_back(a);
    }
    for (int i = 1 ; i < m ; i++) {
        int a = city[i-1];
        int b = city[i];
        if (a > b)
            swap(a, b);
        b -= 1;
        update_range(1, 1, treesize, a, b, 1);
    }
    for (int i = 1 ; i <= n ; i++) {
        update_range(1, 1, treesize, i, i, 0);
    }
    long long ans = 0;
    vector<int> a, b, c;
    for (int i = 1 ; i < n ; i++) {
        int p, q, r;
        cin >> p >> q>> r;
        a.push_back(p);
        b.push_back(q);
        c.push_back(r);
    }
    for (int i = 1;  i< n ; i++) {
        ans += min((long long)a[i-1]*tree[treesize+i-1], (long long)c[i-1] + (long long)b[i-1]*tree[treesize+i-1]);
    }
    cout << ans;
















    return 0;
}
