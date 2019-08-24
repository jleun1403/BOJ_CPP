#include <bits/stdc++.h>
using namespace std;

struct planet{
    int x;
    int y;
    int z;
    int index;
};

struct edge {
    int start;
    int end;
    int dist;
};

int parent[100001];


int Find(int x) {
    if (parent[x] == -1)
        return x;
    return parent[x] = Find(parent[x]);
}

int getdist(planet &p1, planet &p2) {
    return min(min(abs(p1.x - p2.x), abs(p1.y - p2.y)), abs(p1.z- p2.z));
}

bool compare_planet_x(planet &p1, planet &p2) {
    return p1.x < p2.x;
}
bool compare_planet_y(planet &p1, planet &p2)  {
    return p1.y < p2.y;
}
bool compare_planet_z(planet &p1, planet &p2) {
    return p1.z < p2.z;
}

bool compare_edge(edge &e1, edge &e2) {
    return e1.dist < e2.dist;
}

vector<planet> v;
vector<edge> e;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        planet p;
        p.x = a;
        p.y = b;
        p.z = c;
        p.index = i;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), compare_planet_x);
    for (int i = 1 ; i < n ; i++) {
        edge ed;
        ed.start = v[i-1].index;
        ed.end = v[i].index;
        ed.dist = getdist(v[i-1], v[i]);
        e.push_back(ed);
    }
    sort(v.begin(), v.end(), compare_planet_y);
    for (int i = 1 ; i < n ; i++) {
        edge ed;
        ed.start = v[i-1].index;
        ed.end = v[i].index;
        ed.dist = getdist(v[i-1], v[i]);
        e.push_back(ed);
    }
    sort(v.begin(), v.end(), compare_planet_z);
    for (int i = 1 ; i < n ; i++) {
        edge ed;
        ed.start = v[i-1].index;
        ed.end = v[i].index;
        ed.dist = getdist(v[i-1], v[i]);
        e.push_back(ed);
    }
    sort(e.begin(), e.end(), compare_edge);
    memset(parent, -1, sizeof(parent));
    long long answer = 0LL;
    for (int i = 0 ; i < e.size() ; i++) {
        int x = e[i].start;
        int y = e[i].end;
        x = Find(x);
        y = Find(y);
        if (x == y)
            continue;
        answer += e[i].dist;
        parent[x] = y;
    }
    printf("%lld\n", answer);
    return 0;
}