#include <bits/stdc++.h>
using namespace std;
int map[1025][1025];
int dist[1025][1025];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x;
            scanf("%d", &x);
            dist[i][j] = dist[i-1][j] + dist[i][j-1]-dist[i-1][j-1] + x;
        }
    }
    for(int i=0; i<m; i++){
        int a, b, c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("%d\n", dist[c][d]-dist[a-1][d] -dist[c][b-1] + dist[a-1][b-1]);
    }
    return 0;
}