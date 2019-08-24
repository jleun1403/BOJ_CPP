#include <bits/stdc++.h>
using namespace std;
int a[21][21];
int d[21][21];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;
int startx, starty;
int answer;
int sharksize;
int eaten;
void bfs(int i, int j){
    queue <pair<int,int>> q;
    q.push(make_pair(i,j));
    d[i][j] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front(). second;
        q.pop();
        for(int i=0 ; i<4; i++){
            int nx= x + dx[i];
            int ny = y  +dy[i];
            if(nx >=0 && nx <n && ny >=0 && ny <n){
                if( d[nx][ny] == 0 && (a[nx][ny] <= sharksize)){
                q.push(make_pair(nx,ny));
                d[nx][ny] = d[x][y] +1;
            }
        }
    }
    }
}
int main(){
    cin >> n;
    sharksize = 2;
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
        memset(d, 0, sizeof(d));
        bfs(startx, starty);
        int caneat = 0;
        int mindist = 987654321;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(d[i][j]!=0 && a[i][j] < sharksize && a[i][j]!=0){
                   mindist = min(mindist, d[i][j]);
                    caneat +=1; 
                }
            }
        } 
        if(caneat == 0) break;
        bool found = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(d[i][j] == mindist && a[i][j] < sharksize && a[i][j] !=0){
                    a[i][j] = 0;
                    a[startx][starty] = 0;
                    eaten +=1;
                    startx = i;
                    starty = j;
                    found  = true;
                    break;
                }
            }
            if(found == true) break;
        }
        if(sharksize == eaten){
            sharksize +=1;
            eaten = 0;
        }
        answer += mindist -1;
    }
    printf("%d\n", answer);
    return 0;
    
}