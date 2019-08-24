#include <bits/stdc++.h>
using namespace std;
int n, low, high;
int a[51][51];
int d[51][51];
int d_copy[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0 ,-1, 1};
int sum, num;
int change[10001];
void dfs(int x, int y, int cnt){
    d[x][y] = cnt;
    num +=1;
    sum+=a[x][y];
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx <n && ny >=0 && ny <n){
            if(d[nx][ny] ==0 && abs(a[nx][ny] - a[x][y]) >=low && abs(a[nx][ny] - a[x][y]) <= high){
                dfs(nx,ny,cnt);
            }
        }
    }
}
void dfs2(int x, int y, int cnt){
    d_copy[x][y] = cnt;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx <n && ny >=0 && ny <n){
            if(d_copy[nx][ny] ==0 && abs(a[nx][ny] - a[x][y]) >=low && abs(a[nx][ny] - a[x][y]) <= high){
                dfs2(nx,ny,cnt);
            }
        }
    }
}
int main(){
    scanf("%d %d %d", &n, &low, & high);
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    int ans =0;
    int cnt = 0;
    int s_cnt = 0;
    while(true){
        cnt = 0;
        s_cnt=0;
        memset(d, 0, sizeof(d));
        memset(d_copy, 0, sizeof(d_copy));
        for(int i=0; i<n ;i++){
            for(int j=0; j<n; j++){
                if(d[i][j] ==0){
                cnt+=1;
                sum = 0;
                num = 0;
                dfs(i,j, cnt);
                change[cnt] = sum/num;
                }
            }
        }
        if(cnt == n*n) {
            printf("%d\n", ans);
            return 0;
        }
        ans+=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                a[i][j] = change[d[i][j]];
            }
        }
        //인구 이동 후 덩어리 세기 
        for(int i=0; i <n; i++){
            for(int j=0; j<n ; j++){
                if(d_copy[i][j] == 0){
                    s_cnt+=1;
                    dfs2(i, j, s_cnt);
                }
            }
        }
        bool end = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(d[i][j] == d_copy[i][j]) continue;
                else {
                    end = true;
                    break;
                }
            }
            if(end == true){
                break;
            }
        }
        if(end == false){
            cout << ans << '\n';
            break;
        }
    }
    return 0;
}