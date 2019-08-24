#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int parent[1000];

struct Edge {
    double dist;
    int a;
    int b;
    Edge(int x, int y, double z) : a(x), b(y), dist(z) {};
    bool operator< (Edge &e1) {
        return this->dist < e1.dist;
    }
};

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(((long long)x1-x2)*((long long)x1-x2) + ((long long)y1-y2) * ((long long)y1-y2));
}

int Find(int x){
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}
bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        parent[x] = y;
        return true;
    }
    return false;
}


vector<pair<int, int>> v;
vector<Edge> edge;


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i <n ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, b));
        parent[i] = i;
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = i+1 ; j < n ; j++) {
            edge.push_back(Edge(i, j, dist(v[i].first, v[i].second, v[j].first, v[j].second)));
        }
    }
    sort(edge.begin(), edge.end());
    for (int i = 0 ; i < m ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a -= 1; b -= 1;
        Union(a, b);
    }
    double ans = 0.0;
    for (int i = 0 ; i < edge.size() ; i++) {
        if (Union(edge[i].a, edge[i].b)) {
            ans += edge[i].dist;
        }
    }
    printf("%.2lf", ans);













  return 0;
}
