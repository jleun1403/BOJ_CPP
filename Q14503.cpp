#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1 ,0, -1};
int d[51][51];
int ans;
int startx, starty, startd;
void dfs(int x, int y, int d){
    while(true){
        if(a[x][y] == 0) {
            a[x][y] = 2;
            ans+=1;
        }
        if(a[x+1][y] !=0 && a[x-1][y]!=0 && a[x][y+1] !=0 && a[x][y-1]!=0 ){
            if(a[x-dx[d]][y-dy[d]] ==1) break;
            else{
                x-=dx[d];
                y-=dy[d];
            }
        }
        else{
            if(d==0) d=3;
            else d-=1;
            if(a[x+dx[d]][y+dy[d]] == 0){
                x += dx[d];
                y += dy[d];
            }
        }
    } 
}
 int main(){
     cin >> n>> m;
     cin >> startx >> starty >> startd;
     for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
             cin >> a[i][j];
         }
     }
    dfs(startx,starty, startd);
    cout << ans << '\n';
    return 0;
 }