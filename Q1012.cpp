#include <bits/stdc++.h>
using namespace std;
int a[51][51];
int d[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m, k;
void dfs(int i, int j){
    int x = i;
    int y = j;
    d[x][y] = 1;
    for(int k=0; k<4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx >=0 && nx <n && ny >=0 && ny <m){
            if(a[nx][ny] == 1 && d[nx][ny] == 0){
                dfs(nx,ny);
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(a, 0, sizeof(a));
        memset(d, 0 , sizeof(d));
        scanf("%d %d %d", &m, &n, &k);
        int x, y;
        for(int i=0; i<k; i++){
            scanf("%d %d", &y, &x);
            a[x][y] = 1;
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == 1 && d[i][j] == 0){
                    cnt+=1;
                    dfs(i,j);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}