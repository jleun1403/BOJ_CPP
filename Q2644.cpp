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
int parent[101];
int dist[101];
vector<vector<int>> v(101);

int Find(int x) {
    if (parent[x] == -1)
        return x;
    return Find(parent[x]);
}

void BFS(int x) {
    dist[x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0 ; i < v[cur].size(); i++) {
            int next = v[cur][i];
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }
}

int LCA(int x, int y) {
    if (dist[y] > dist[x])
        swap(x, y);
    int distance = dist[x] - dist[y];
    for (int i = 0 ; i < distance ; i++) {
        x = parent[x];
    }
    if (x == y)
        return x;
    while(x != y) {
        x = parent[x];
        y = parent[y];
    }
    return x;
}


int main() {
    int n, a, b, m;
    scanf("%d %d %d %d", &n, &a, &b, &m);
    memset(parent, -1, sizeof(parent));
    for (int i = 0 ; i < m ; i++) {
        int p, c;
        scanf("%d %d", &p, &c);
        v[p].push_back(c);
        parent[c] = p;
    }

    if (Find(a) != Find(b)) {
        printf("-1");
        return 0;
    }
    if (a == b){
        printf("0");
        return 0;
    }

    for (int i = 0 ; i < n ; i++) {
        if (parent[i] == -1) {
            BFS(i);
        }
    }
    int lca = LCA(a, b);
    printf("%d", dist[a] + dist[b] - dist[lca] - dist[lca]);
















  return 0;
}
