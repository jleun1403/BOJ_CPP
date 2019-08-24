#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int d[125][125];
int a[126][126];
int main(){
    int t = 0;
    while(true){
        int n;
        scanf("%d", &n);
        if(n ==0) break;
        queue <pair<int,int>> q;
        q.push(make_pair(0,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                d[i][j] = 987654321;
            }
        }
        t+=1;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &a[i][j]);
            }
        }
        d[0][0] = a[0][0];
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >=0 && nx <n && ny >=0 && ny <n){
                    if(d[nx][ny]  > d[x][y] + a[nx][ny]) {
                        d[nx][ny] = d[x][y] + a[nx][ny];
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
        printf("Problem %d: %d\n", t, d[n-1][n-1]);
    }
    return 0;
}