#include <bits/stdc++.h>
using namespace std;
int n;
int answer;
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 1, 0};
int a[17][17];
bool check[17][17];
void go(int x, int y, int dir){
    if(y ==n && x!=n && dir ==1) return ;
    else if(x ==n && y!=n && dir == 3) return ;
    else if(y == n && x ==n ){
        answer +=1;
        return;
    }
    if(dir ==1){
        int nx = x + dx[1];
        int ny = y + dy[1];
        if(nx >=1 && nx <=n && ny >=1 && ny <=n && a[nx][ny] == 0){
            go(nx, ny, 1); 
            nx = x- dx[1];
            ny = y -dy[1];
        }
        nx = x + dx[2];
        ny = y + dy[2];
        if(nx >=1 && nx <=n && ny >=1 && ny <=n && a[nx][ny] == 0 && a[nx-1][ny] ==0 & a[nx][ny-1] == 0){
            go(nx, ny, 2);
            nx = x - dx[2];
            ny = y - dy[2];
        }    
    }
    else if ( dir == 2){
        int nx = x + dx[1];
        int ny = y + dy[1];
        if(nx >=1 && nx <=n && ny >=1 && ny <=n && a[nx][ny] == 0) {
            go(nx, ny, 1);
            nx = x- dx[1];
            ny = y -dy[1];
        }
        nx = x + dx[2];
        ny = y + dy[2];
        if(nx >=1 && nx <=n && ny >=1 && ny <=n && a[nx][ny] == 0&& a[nx-1][ny] ==0 & a[nx][ny-1] == 0){
            go(nx, ny, 2);
            nx = x - dx[2];
            ny = y - dy[2];
        }
        nx = x + dx[3];
        ny = y + dy[3];
        if(nx >=1 && nx <=n && ny >=1 && ny <=n && a[nx][ny] == 0){
            go(nx, ny, 3);
             nx = x - dx[3];
            ny = y - dy[3];
        }
    }
    else if(dir ==3){
        int nx = x + dx[2];
        int ny = y + dy[2];
        if(nx >=1 && nx <=n && ny >=1 && ny <=n && a[nx][ny] == 0&& a[nx-1][ny] ==0 & a[nx][ny-1] == 0){
            go(nx, ny, 2);
            nx = x - dx[2];
            ny = y - dy[2];
        }
        nx = x + dx[3];
        ny = y + dy[3];
        if(nx >=1 && nx <=n && ny >=1 && ny <=n && a[nx][ny] == 0){
            go(nx, ny, 3);
             nx = x - dx[3];
             ny = y - dy[3];
        }
    }
    return ;
}
int main(){
    cin >> n;
    for(int i=1; i<=n ;i++){
        for(int j=1 ;j <=n; j++){
            cin >> a[i][j];
        }
    }
    go(1, 2, 1);
    cout << answer << '\n';
    return 0;
}
