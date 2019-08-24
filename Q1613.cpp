#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int dist[401][401];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n ; j++) {
            dist[i][j] = inf;
        }
    }
    for (int i = 0 ; i < k ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        dist[a][b] = 1;
    }
    for (int i = 1;  i<= n ; i++) {
        for (int j =  1 ; j <= n ; j++) {
            for (int k = 1; k <= n ; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] +dist[i][k]);
            }
        }
    }
    int s;
    scanf("%d", &s);
    for (int i = 0 ; i < s; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (dist[a][b] == inf && dist[b][a] == inf) {
            printf("%d\n", 0);
        }
        else if (dist[a][b] == inf) {
            printf("1\n");
        }
        else printf("-1\n");
    }















  return 0;
}
