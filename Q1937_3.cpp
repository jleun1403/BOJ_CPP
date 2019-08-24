#include <bits/stdc++.h>
using namespace std;
int n;
int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0 ,0, -1, 1};
int a[501][501];
int d[501][501];
int go(int x, int y){
    if(d[x][y] != 0) return d[x][y];
    d[x][y] = 1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<n && ny >=0 && ny <n){
            if(a[nx][ny] > a[x][y]){
                d[x][y] = max(d[x][y], go(nx,ny) +1);
            }
        }
    }
    return d[x][y];
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d" ,&a[i][j]);
        }
    }
    int answer= 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            answer= max(answer,go(i ,j));
        }
    }
    printf("%d\n", answer);
    return 0;
}