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
int n, m;
int parent[50001];
int level[50001];
int c[50001];
vector<vector<int>> v;

int LCA(int x, int y) {
    while(level[x] != level[y]) {
        if (level[x] > level[y])
            x = parent[x];
        else
            y = parent[y];
    }
    while (x != y) {
        x = parent[x];
        y = parent[y];
    }
    return x;

}

void DFS(int x) {
    c[x] = 1;
    for (int i = 0 ; i < v[x].size() ; i++) {
        if (c[v[x][i]] == 0) {
            level[v[x][i]] = level[x] +1;
            parent[v[x][i]] = x;
            DFS(v[x][i]);
        }
    }
}

int main() {
    scanf("%d", &n);
    v.resize(n+1);
    for (int i = 0 ; i < n - 1 ; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        v[from].push_back(to);
        v[to].push_back(from);
    }
    level[1] = 0;
    parent[1] = 0;
    DFS(1);
    scanf("%d", &m);
    for (int i = 0 ; i < m ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        cout << LCA(a, b) << '\n';
    }
















  return 0;
}
