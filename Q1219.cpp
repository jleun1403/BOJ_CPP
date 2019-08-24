#include <bits/stdc++.h>
#define inf (1LL<<50)

using namespace std;

struct Edge{
    long long from;
    long long to;
    long long cost;
};
long long temp[100];
long long dist[100];

int main() {
    int n, start, finish, m;
    scanf("%d %d %d %d", &n, &start, &finish, &m);
    vector<Edge> v(m);
    for (int i = 0 ; i < m; i++) {
        long long from, to, d;
        scanf("%lld %lld %lld", &from, &to, &d);
        v[i].from = from;
        v[i].to = to;
        v[i].cost = d;
    }
    for (int i = 0 ; i < n ; i++) {
        scanf("%lld", &temp[i]);
    }
    for (int i = 0 ; i < m ; i++) {
        long long p = v[i].to;
        v[i].cost -= temp[p];
    }
    for (int i = 0 ; i < n ;i++) {
        dist[i] = inf;
    }
    bool negative_cycle = false;

    dist[start] = temp[start] * -1;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            long long x = v[j].from;
            long long y = v[j].to;
            long long z = v[j].cost;
            if (dist[x] != inf && dist[y] > dist[x] + z) {
                dist[y] = dist[x] +z;
                if ( i == n ) {
                    negative_cycle = true;
                }
            }
        }
    }
    if (negative_cycle && dist[finish] != inf) {
        printf("Gee");
    }
    else if (dist[finish] == inf) {
        printf("gg");
    }
    else {
        printf("%lld", -1 *dist[finish]);
    }

















  return 0;
}
