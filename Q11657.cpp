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
#define inf 1000000000

using namespace std;
int n, m;


int main() {
    scanf("%d %d", &n, &m);
    vector<vector<pair<int, int>>> v;
    bool cycle = false;
    int dist[501];
    v.resize(n+1);
    for (int i = 1 ; i <= m ; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        v[from].push_back(make_pair(to, weight));
    }
    for (int i = 1 ; i <= n ; i++)
        dist[i] = inf;
    dist[1] = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++){
            for (int k = 0 ; k < v[j].size() ; k++) {
                int next = v[j][k].first;
                int d = v[j][k].second;
                if (dist[j] != inf && dist[next] > dist[j] + d) {
                    dist[next] = dist[j] + d;
                    if (i == n)
                        cycle = true;
                }
            }
        }
    }
    if (cycle)
        cout <<-1;
    else {
        for (int i = 2 ; i <= n ; i++) {
            if (dist[i] == inf)
                printf("-1\n");
            else
                printf("%d\n", dist[i]);
        }
    }









  return 0;
}
