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
#define MAX 18

using namespace std;
int parent[100001][MAX];
int depth[100001];
int c[100001];
vector<vector<int>> v;
int n, m;

int LCA(int x, int y) {
    if (depth[x] < depth[y])
        swap(x, y);
    int diff = depth[x] - depth[y];
    for (int i = 0 ; diff ; i++) {
        if (diff % 2)
            x = parent[x][i];
        diff = diff / 2;
    }
    if (x == y)
        return x;
    for (int i = MAX-1 ; i >= 0 ; i--) {
        if (parent[x][i] != -1 && parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    return parent[x][0];
}


void DFS(int x) {
    c[x] = 1;
    for (int p : v[x]) {
        if (c[p] == 0) {
            parent[p][0] = x;
            depth[p] = depth[x] +1;
            DFS(p);
        }
    }
}

int main() {
    scanf("%d", &n);
    v.resize(n+1);
    for (int i = 0 ; i < n-1 ; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        v[from].push_back(to);
        v[to].push_back(from);
    }
    memset(parent, -1, sizeof(parent));
    memset(c, 0, sizeof(c));
    depth[1] = 0;
    DFS(1);
    for (int i = 0 ; i < MAX-1 ; i++) {
        for (int j = 2 ; j <= n ; j++) {
            if (parent[j][i] != -1)
                parent[j][i+1] = parent[parent[j][i]][i];
        }
    }
    scanf("%d", &m);
    for (int i = 0 ; i < m ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
















  return 0;
}
