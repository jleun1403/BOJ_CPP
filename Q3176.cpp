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
int dist[100001];
int qmin[100001][18];
int qmax[100001][18];
vector<vector<pair<int, int>>> v;
int n, m;

pair<int, int> LCA(int x, int y) {
    int rmin = 2000000000;
    int rmax = -2000000000;
    if (depth[x] < depth[y])
        swap(x, y);
    int diff = depth[x] - depth[y];
    for (int i = 0 ; diff ; i++) {
        if (diff % 2) {
            rmin = min(rmin, qmin[x][i]);
            rmax = max(rmax, qmax[x][i]);
            x = parent[x][i];
        }
        diff = diff / 2;
    }
    if (x == y)
        return make_pair(rmin, rmax);
    for (int i = MAX-1 ; i >= 0 ; i--) {
        if (parent[x][i] != -1 && parent[x][i] != parent[y][i]) {
            rmin = min(rmin, min(qmin[x][i], qmin[y][i]));
            rmax = max(rmax, max(qmax[x][i], qmax[y][i]));
            x = parent[x][i];
            y = parent[y][i];
        }
    }
    rmin = min(rmin, min(qmin[x][0], qmin[y][0]));
    rmax = max(rmax, max(qmax[x][0], qmax[y][0]));
    return make_pair(rmin, rmax);
}


void DFS(int x) {
    c[x] = 1;
    for (auto p : v[x]) {
        if (c[p.first] == 0) {
            parent[p.first][0] = x;
            depth[p.first] = depth[x] +1;
            qmin[p.first][0] = p.second;
            qmax[p.first][0] = p.second;
            DFS(p.first);
        }
    }
}

int main() {
    scanf("%d", &n);
    v.resize(n+1);
    for (int i = 0 ; i < n-1 ; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        v[from].push_back(make_pair(to, weight));
        v[to].push_back(make_pair(from, weight));
    }
    memset(parent, -1, sizeof(parent));
    memset(c, 0, sizeof(c));
    depth[1] = 0;
    dist[1] = 0;
    DFS(1);
    for (int i = 0 ; i < MAX-1 ; i++) {
        for (int j = 2 ; j <= n ; j++) {
            if (parent[j][i] != -1)
                parent[j][i+1] = parent[parent[j][i]][i];
                qmin[j][i+1] = min(qmin[j][i], qmin[parent[j][i]][i]);
                qmax[j][i+1] = max(qmax[j][i], qmax[parent[j][i]][i]);
        }
    }
    scanf("%d", &m);
    for (int i = 0 ; i < m ; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d %d\n", LCA(x, y).first, LCA(x, y).second);
    }
















  return 0;
}
