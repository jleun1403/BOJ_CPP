#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[101][101];
bool check[101][101];
int d[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void bfs(int i, int j){
    queue <pair<int,int>> q;
    check[i][j] = true;
    q.push({i,j});
    d[i][j] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >=0 && nx<n && ny >=0 && ny <m){
                if(check[nx][ny]== false && a[nx][ny] == 1){
                    check[nx][ny] = true;
                    q.push({nx,ny});
                    d[nx][ny] = d[x][y] +1;
                }
            }
        }
    }

}
int main(){
    cin >> n>> m;
    for(int i=0; i<n ; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    bfs(0,0);
    cout << d[n-1][m-1] << '\n';
    return 0;
}