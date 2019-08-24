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

int parent[100001];

int Find(int x) {
    if (parent[x] == x)
        return x;
    else return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        parent[y] = x;
        return true;
    }
    return false;
}

struct Edge {
    int a;
    int b;
    int cost;
    bool used;
    Edge(int p, int q, int r) : a(p), b(q), cost(r), used(false) {}
};

bool cmp(Edge &e1, Edge &e2) {
    return e1.cost < e2.cost;
}

vector<Edge> v;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        parent[i] = i;
    }
    for (int i = 0 ; i < m ; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v.push_back(Edge(a, b, c));
    }
    int ans = 0;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0 ; i < m ; i++) {
        if (Union(v[i].a, v[i].b)) {
            v[i].used = true;
            ans += v[i].cost;
        }
    }
    for (int i = m ; i >= 0 ; i--){
        if (v[i].used) {
            ans -= v[i].cost;
            break;
        }
    }
    printf("%d", ans);



















  return 0;
}
