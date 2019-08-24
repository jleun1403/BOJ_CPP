#include <bits/stdc++.h>
using namespace std;
int n;
int a[21][21];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dist[21][21];
int startx, starty;
int sharksize;
int eat_num;
int ans;
void bfs(int xx, int yy){
    queue <pair<int,int>> q;
    q.push(make_pair(xx,yy));
    dist[xx][yy] = 1;
    while(!q.empty()){
        int x =q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx>=0 && nx <n && ny>=0 && ny <n){
                if((a[nx][ny] <= sharksize || a[nx][ny] == 0) && dist[nx][ny] == 0){
                    dist[nx][ny] = dist[x][y] +1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}
int main(){
    cin >> n;
    sharksize = 2;
    eat_num = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(a[i][j] == 9){
                startx = i;
                starty = j;
            }
        }
    }
    while(true){
        memset(dist, 0, sizeof(dist));
        int mindist = 987654321;
        bfs(startx, starty);
        int caneat = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][j] !=0 && a[i][j] < sharksize && a[i][j] !=0){
                    caneat +=1;
                    mindist = min(mindist, dist[i][j]);
                }
            }
        }
        if(caneat ==0) break;
        bool found = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][j] == mindist && a[i][j] < sharksize && a[i][j] !=0){
                    eat_num +=1;
                    a[i][j] = 9;
                    a[startx][starty] = 0;
                    startx = i;
                    starty = j;
                    found = true;
                    break;
                }
            }
            if(found==true) break;
        }
        if(sharksize == eat_num){
            sharksize +=1;
            eat_num = 0;
        }
        ans += mindist-1;
    }
    printf("%d\n", ans);
    return 0;
   
}