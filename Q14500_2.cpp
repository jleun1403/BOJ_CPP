#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool check[501][501];

int ans;
int sum;
void dfs(int x, int y, int cnt, int sum){
    if(cnt ==4) {
        ans = max(ans, sum);
        return ;
    }
    //check[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx <n && ny >=0 && ny <m){
            if(check[nx][ny] == false){
                check[nx][ny] = true;
                dfs(nx,ny,cnt+1, sum+a[nx][ny]);
                check[nx][ny] = false;
            }
        }
    }
//check[x][y] = false;
}
int go(int x, int y){
    int ret = 0;
    ret = a[x][y] + a[x-1][y-1] + a[x][y-1] + a[x+1][y-1];

    ret = max(ret, a[x][y] + a[x-1][y-1] + a[x-1][y] + a[x-1][y+1]);

    ret = max(ret,  a[x][y] + a[x-1][y+1] + a[x][y+1] + a[x+1][y+1]);

    ret = max( ret, a[x][y] + a[x+1][y-1] + a[x+1][y] + a[x+1][y+1]);

    ret = max( ret, a[x][y] + a[x-1][y] + a[x][y-1] + a[x][y+1]);

    ret = max(ret,  a[x][y] + a[x][y-1] + a[x-1][y] + a[x+1][y]);

    ret = max(ret,  a[x][y] + a[x-1][y] + a[x+1][y] + a[x][y+1]);

    ret = max(ret, a[x][y] + a[x][y-1] + a[x][y+1] + a[x+1][y]);
    
    return ret;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            sum = 0;
            memset(check, false, sizeof(check));
            check[i][j] = true;
            dfs(i,j, 1 , a[i][j]);
        }
    }
    for(int i=1; i<n-1; i++){
        for(int j=1; j<m-1; j++){
            ans = max(go(i,j), ans);
        }
    }
    cout << ans << '\n';
    return 0;
}