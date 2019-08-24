#include <bits/stdc++.h>
using namespace std;
int a[21][21];
int dx[5]={0, 0, 0, -1, 1};
int dy[5]={0, 1, -1, 0, 0};
int d[7];
int x, y, nx, ny, n, m, k, op;
void move(int op){
    int t;
    if(op==1) t=d[1],d[1]=d[4],d[4]=d[6],d[6]=d[3],d[3]=t;
    else if(op==2) t=d[1],d[1]=d[3],d[3]=d[6],d[6]=d[4],d[4]=t;
    else if(op==3) t=d[1],d[1]=d[5],d[5]=d[6],d[6]=d[2],d[2]=t;
    else t=d[1],d[1]=d[2],d[2]=d[6],d[6]=d[5],d[5]=t;
}
int main(){
    cin >> n>> m>> x >>y >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    
    while(k--){
        cin >> op;
        nx = x + dx[op];
        ny = y + dy[op];
        if(nx <0 || nx >=n || ny<0 || ny>=m){
            continue;
        }
        x= nx;
        y= ny;
        move(op);
        if(a[x][y] == 0){
            a[x][y] = d[6];
        }
        else{
            d[6] = a[x][y];
            a[x][y] = 0;
        }
        cout << d[1] << '\n';
    }
    return 0;
}