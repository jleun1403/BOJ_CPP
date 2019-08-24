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
int dist[40001];
vector<vector<pair <int, int>>> v;

int LCA(int x, int y) {
    int ans = 0;
    while(level[x] != level[y]) {
        if (level[x] > level[y]) {
            ans += dist[x];
            x = parent[x];
        }
        else {
            ans += dist[y];
            y = parent[y];
        }
    }
    while (x != y) {
        ans += dist[x];
        ans += dist[y];
        x = parent[x];
        y = parent[y];
    }
    return ans;

}

void BFS(int x) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, 0));
    while(!q.empty()){
        int cn = q.front().first;
        int cd = q.front().second;
        q.pop();
        for (auto p : v[cn]) {
            if (c[p.first] == 0) {
                int nx = p.first;
                int nd = p.second;
                c[nx] = 1;
                level[nx] = level[cn] +1;
                parent[nx] = cn;
                dist[nx] = nd;
                q.push(make_pair(nx, nd));
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    v.resize(n+1);
    for (int i = 0 ; i < (n-1) ; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        v[from].push_back(make_pair(to, weight));
        v[to].push_back(make_pair(from, weight));
    }
    c[1] = 1;
    level[1] = 0;
    parent[1] = 0;
    dist[1] = 0;
    BFS(1);


    scanf("%d", &m);
    for (int i = 0 ; i < m ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        cout << LCA(a, b) << '\n';
    }
















  return 0;
}
