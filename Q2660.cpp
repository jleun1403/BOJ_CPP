#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int dist[51][51];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1 ;i <= 50 ; i++) {
        for (int j = 1 ; j <= 50 ; j++) {
            dist[i][j] = inf;
        }
    }
    while(true) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == -1 && b == -1)
            break;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    int ans = inf;
    for (int k = 1 ; k <= n ; k++) {
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= n ; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int v[51];
    for (int i = 1 ; i <= n ; i++) {
        int k = 0;
        for (int j = 1 ; j <= n ; j++) {
            k = max(k, dist[i][j]);
        }
        v[i] = k;
    }
    for (int i = 1 ; i <= n ; i++){
        ans = min(ans, v[i]);
    }
    vector<int> vv;
    for (int i = 1; i <= n ; i++) {
        if (v[i] == ans) {
            vv.push_back(i);
        }
    }
    printf("%d %d\n", ans, vv.size());
    for (int i = 0 ; i < vv.size() ; i++) {
        printf("%d ", vv[i]);
    }
















  return 0;
}
