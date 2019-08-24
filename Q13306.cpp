#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int parent[200001];
int p[200001];
vector<pair<int, int>> q;
stack<int>s;

void Union(int x, int y) {
    p[x] = y;
}

int Find(int x) {
    if (p[x] == x) return x;
    return p[x] = Find(p[x]);
}

int main() {
    int n, t;
    scanf("%d %d", &n,&t);
    for (int i = 2 ; i <= n ; i++) {
        int a;
        scanf("%d", &a);
        parent[i] = a;
        p[i] = i;
    }
    p[1] = 1;
    for (int i = 0 ; i < n + t - 1; i++) {
        int x;
        scanf("%d", &x);
        if (x == 0) {
            int a;
            scanf("%d", &a);
            q.push_back(make_pair(0, a));
        }
        else if (x == 1) {
            int a, b;
            scanf("%d %d", &a, &b);
            q.push_back(make_pair(a, b));
        }
    }
    for (int i = n + t - 2; i >= 0 ; i--) {
        auto p = q[i];
        if (q[i].first == 0) {
            Union(q[i].second, parent[q[i].second]);
        }
        else {
            int a = Find(q[i].first);
            int b = Find(q[i].second);
            if (a == b) {
                s.push(1);
            }
            else
                s.push(0);
        }
    }
    while(!s.empty()) {
        if (s.top())
            printf("YES\n");
        else
            printf("NO\n");
        s.pop();
    }
















  return 0;
}
