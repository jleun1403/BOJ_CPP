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
int dist[401][401];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++)
            dist[i][j] = inf;
    }
    for (int i = 0 ; i < m ; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        dist[from][to] = weight;
    }
    for (int k = 1;  k <= n ; k++) {
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1; j <=n ; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    int ans = inf;
    for (int i = 1 ; i <= n ; i++) {
        if (dist[i][i] < ans)
            ans = dist[i][i];
    }
    if (ans == inf)
        printf("-1");
    else
        printf("%d", ans);















  return 0;
}
