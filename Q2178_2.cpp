#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int d[101][101];
int dx[4] = {-1 ,1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main(){
    int n, m;
    cin >> n>> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    queue <pair<int,int>> q;
    q.push(make_pair(0,0));
    d[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<n && ny >=0 && ny <m){
                if(d[nx][ny] == 0 && a[nx][ny] == 1){
                    d[nx][ny] = d[x][y] +1;
                    q.push(make_pair(nx,ny));
                }
            }
        }

    }
    printf("%d\n", d[n-1][m-1]);
    return 0;

}