#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1002][1002];
int d[1002][1002][3];
int nd[1002][1002];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(){
    queue <pair<pair<int,int>, int>> q;
    q.push(make_pair(make_pair(0, 0),1));
    d[0][0][1] = 1;
    while(!q.empty()){
        int x= q.front().first.first;
        int y = q.front().first.second;
        int block = q.front().second;
        q.pop();
        if(x == n-1 && y == m-1){
            return d[x][y][block];
        }
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx <n && ny>=0 && ny<m){
                if(a[nx][ny] == 1 && block == 1){
                    d[nx][ny][block-1] = d[x][y][block] +1;
                    q.push(make_pair(make_pair(nx,ny), block-1));
                }
                else if(a[nx][ny] == 0 && d[nx][ny][block]==0){
                    d[nx][ny][block] = d[x][y][block] +1;
                    q.push(make_pair(make_pair(nx,ny), block));
                }
            }
        }
    }
    return -1;
}
int main(){
    cin >> n>> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    cout << bfs()<< '\n';
    return 0;
}