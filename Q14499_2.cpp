#include <bits/stdc++.h>
using namespace std;
int n ,m, x, y, k;
int a[21][21];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int d[7];
int nx, ny;
int direc;
void move(int op){
    int t;
    if(op==1) t=d[1],d[1]=d[4],d[4]=d[6],d[6]=d[3],d[3]=t;
    else if(op==2) t=d[1],d[1]=d[3],d[3]=d[6],d[6]=d[4],d[4]=t;
    else if(op==3) t=d[1],d[1]=d[5],d[5]=d[6],d[6]=d[2],d[2]=t;
    else t=d[1],d[1]=d[2],d[2]=d[6],d[6]=d[5],d[5]=t;
}

int main(){
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    while(k--){
        scanf("%d", &direc);
        if(x + dx[direc] >=n || x+dx[direc] <0 || y+dy[direc] >=m ||  y+dy[direc] <0) continue;
         x += dx[direc];
         y += dy[direc];
        move(direc);
        if(a[x][y] == 0){
            a[x][y] = d[6];
        }
        else{
            d[6] =a[x][y];
            a[x][y] = 0;
        }
        cout << d[1] << '\n';
    }
    return 0;
}