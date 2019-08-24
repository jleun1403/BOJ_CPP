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
struct s {
    int x;
    int y;
    int z;
};

bool cmp(const s &a, const s &b) {
    return (a.x < b.x);
}

vector<s> v(500001);
int tree[2000050];
int treesize;

int query(int node, int nodeleft, int noderight, int left, int right) {
    if (noderight < left || right < nodeleft)
        return inf;
    else if (left <= nodeleft && noderight <= right) {
        return tree[node];
    }
    else {
        int m1 = query(node*2, nodeleft, (nodeleft+noderight)/2, left, right);
        int m2 = query(node*2+1, (nodeleft+noderight)/2+1, noderight, left, right);
        return min(m1, m2);
    }
}

void update(int node, int left, int right, int i, int val) {
    if (i < left || i > right)
        return;
    tree[node] = min(tree[node], val);
    if (left != right) {
        update(node*2, left, (left+right)/2, i, val);
        update(node*2+1, (left+right)/2+1, right, i, val);
    }
}


int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    treesize = 1;
    while(treesize < n ) {
        treesize *= 2;
    }

    for (int i = 1 ; i <= n ; i++) {
        int first;
        cin >> first;
        v[first].x = i;
    }
    for (int i = 1 ; i <= n ; i++) {
        int second;
        cin >> second;
        v[second].y = i;
    }
    for (int i = 1 ; i <= n ;i++) {
        int third;
        cin >> third;
        v[third].z = i;
    }

    for (int i = 0 ; i < 2000050 ; i++) {
        tree[i] = inf;
    }

    sort(v.begin(), v.begin() + n+1 , cmp);
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        int t = query(1, 1, n, 1, (v[i].y) -1);
        if (t > v[i].z) {
            ans++;
        }
        update(1, 1, n, v[i].y, v[i].z);
    }
    cout << ans;















  return 0;
}
