#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
queue <pair<int,int>> fire;
queue <pair<int,int>> q;
int fdist[1003][1003];
bool check[1003][1003];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0 ,-1, 1};
int n, m ;
int d[1003][1003];
int startx , starty;
void firebfs(){
    while(!fire.empty()){
        int x =fire.front().first;
        int y = fire.front().second;
        fire.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=1 && nx <= n && ny >=1 && ny <= m){
                if(a[nx][ny]!= '*' && a[nx][ny] != '#' && fdist[nx][ny] ==0){
                    fdist[nx][ny] = fdist[x][y] +1;
                    fire.push(make_pair(nx,ny));
                }
            }
        }
    }
}
int main(){
    int tt;
    cin >> tt;
    for(int t=1; t<=tt; t++){
        scanf("%d %d" , & m, &n);
        memset(d, 0, sizeof(d));
        memset(fdist, 0, sizeof(fdist));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                scanf(" %c", &a[i][j]);
                if(a[i][j] == '@'){
                    d[i][j] = 1;
                    q.push(make_pair(i,j));
                }
                else if(a[i][j] =='*'){
                    fire.push(make_pair(i,j));
                    fdist[i][j] = 1;
                }
                else if (a[i][j] == '#'){
                    check[i][j] = true;
                }
            }
        }
        firebfs();
        while(!q.empty()){
            int x= q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >=0 && nx <=n+1 && ny >=0 && ny <=m+1){
                    if(d[nx][ny] ==0 && (fdist[nx][ny] == 0 || d[x][y]+1 < fdist[nx][ny]) && a[nx][ny] != '#' && a[nx][ny] != '*'){
                        d[nx][ny] = d[x][y] +1;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
        int mintime = 987654321;
        bool ans = false;
        for(int i=0; i<=n+1; i++){
            for(int j=0; j<=m+1; j++){
                if(i==0 ||i==n+1){
                    if(d[i][j] !=0) {
                        ans = true;
                        mintime = min(mintime, d[i][j]);
                    }
                }
                else {
                    if((j ==0 || j==m+1) && d[i][j]!=0) {
                        ans = true;
                        mintime = min(mintime, d[i][j]);
                    }
                }
            }
        }
        if(ans == false) printf("IMPOSSIBLE\n");
        else printf("%d\n", mintime -1);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                a[i][j] = '.';
            }
        }
    }
    return 0;
}