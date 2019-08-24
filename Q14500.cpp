#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1 ,1, 0 ,0};
int dy[4] = {0, 0, -1, 1};
int n, m;
int a[501][501];
bool check[501][501];
int ans;
int sum;
int except;
void dfs(int x, int y, int cnt, int sum){

    if(cnt == 4){
        ans = max(ans, sum);
        return;
    }
    for(int k=0; k<4; k++){
        int nx = x +dx[k];  
        int ny = y + dy[k];
        if(nx >=0 && nx <n && ny >=0 && ny <m){
            if(check[nx][ny] == false){
                check[nx][ny] = true;
                dfs(nx,ny,cnt+1,sum+a[nx][ny]);
                check[nx][ny] = false;
            }
        }
    }
}
int go(int x, int y){
    int go1=0, go2 =0, go3 = 0, go4 =0, go5 = 0, go6 = 0, go7=0, go8=0;
        go1 = a[x][y] + a[x-1][y-1] + a[x][y-1] + a[x+1][y-1];

        go2 = a[x][y] + a[x-1][y-1] + a[x-1][y] + a[x-1][y+1];

        go3= a[x][y] + a[x-1][y+1] + a[x][y+1] + a[x+1][y+1];

        go4 = a[x][y] + a[x+1][y-1] + a[x+1][y] + a[x+1][y+1];

        go5 = a[x][y] + a[x-1][y] + a[x][y-1] + a[x][y+1];

        go6 = a[x][y] + a[x][y-1] + a[x-1][y] + a[x+1][y];

        go7 = a[x][y] + a[x-1][y] + a[x+1][y] + a[x][y+1];

        go8 = a[x][y] + a[x][y-1] + a[x][y+1] + a[x+1][y];
    return except = max(max(max(go1, go2), max(go3, go4)), max(max(go5,go6), max(go7,go8)));
}
int main(){
    int answer =0;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int except = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            sum =0;
            memset(check, false, sizeof(check));
            check[i][j] = true;
            dfs(i,j, 1, a[i][j]);
            //check[i][j] = false;

        }
    }

    for(int i=1; i<n-1; i++){
        for(int j=1; j<m-1 ; j++){
            ans = max(go(i,j),ans);
        }
    }
    cout << ans << '\n';
    return 0;
}