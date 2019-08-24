#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[301][301];
int a_copy[301][301];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int d[301][301];
bool check[301][301];
int cnt;
void dfs(int x, int y, int cnt){
    d[x][y] = cnt;
    for(int k=0; k<4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx>=0 && nx<n && ny >=0 && ny <m){
            if(d[nx][ny] == 0 && a[nx][ny] !=0){
                dfs(nx,ny, cnt);
            }
        }
    }
}
int count_zero(int x, int y){
    int cnt= 0;
    for(int k=0; k<4; k++){
        int nx= x + dx[k];
        int ny = y + dy[k];
        if(nx>=0 && nx <n && ny >=0 && ny <m){
            if(a[nx][ny] ==0){
                cnt +=1;
            }
        }
    }
    return cnt;
}
int main(){
    cin >> n>> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            a_copy[i][j] = a[i][j];
        }
    }
    int year = 0;
    while(true){
        memset(check, false, sizeof(check));
        memset(d, 0, sizeof(d));
        memset(a_copy,0, sizeof(a_copy));
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] !=0 && d[i][j] == 0){
                    cnt +=1;
                    dfs(i, j, cnt);
                }
            }
        }
        if(cnt>=2){
            cout << year << '\n';
            return 0;
        }
        year+=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] !=0){
                    a_copy[i][j] = a[i][j] - count_zero(i,j);
                    if(a_copy[i][j] <0) a_copy[i][j] = 0;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a[i][j] = a_copy[i][j];
            }
        }
        bool ok = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] !=0) ok = true;
                else continue;
            }
            if (ok == true) break;
        }
        if(ok == false){
            cout << "0\n";
            return 0;
        }
        
    }

}