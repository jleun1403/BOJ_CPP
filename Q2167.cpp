#include <bits/stdc++.h>
using namespace std;
int arr[301][301];
int dist[301][301];
int main(){
    int n, m;
    cin >> n>> m;
    int num = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &num);
            dist[i][j] = dist[i-1][j] + dist[i][j-1] + num - dist[i-1][j-1];
        }
    }
    int k;
    cin >> k;
    int a, b, c, d;
    int ans = 0;
    while(k--){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        ans =dist[c][d] -dist[a-1][d]-dist[c][b-1]+dist[a-1][b-1];
        printf("%d\n", ans);
    }
    return 0;
}