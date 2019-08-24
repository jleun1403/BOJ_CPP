#include <bits/stdc++.h>
using namespace std;
char a[33][33][33];
int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 1,0,-1,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int d[31][31][31];
struct Escape{
    int x, y, z;
};
queue <Escape> q;
int main(){
    while(true){
        int n, m, k;
        scanf("%d %d %d", &k, &n, &m);
        if(n ==0 && m ==0 && k == 0) break;
        int endx, endy, endz;
        for(int i=0; i<k; i++){
            for(int j=0; j<n; j++){
                for(int p=0; p<m; p++){
                    d[i][j][p] = 987654321;
                }
            }
        }
        for(int i=0; i<k; i++){
            for(int j=0; j<n; j++){
                for(int p=0 ; p<m; p++){
                    scanf(" %c", &a[i][j][p]);
                    if(a[i][j][p] == 'S'){
                        d[i][j][p] = 1;
                        Escape e;
                        e.z =i;
                        e.x = j;
                        e.y = p;
                        q.push(e);
                    }
                    else if (a[i][j][p] == 'E'){
                        endx = j; endy = p; endz = i;
                    }
                }
            }
        }
        while(!q.empty()){
            int z= q.front().z;
            int x = q.front().x;
            int y= q.front().y;
            q.pop();
            for(int i=0; i<6; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];
                if(nx <0 || nx >=n || ny <0 || ny >=m || nz <0 || nz >=k) continue;
                if(a[nz][nx][ny] != '#'){
                    if(d[nz][nx][ny] > d[z][x][y] +1){
                        d[nz][nx][ny] = d[z][x][y] +1;
                        Escape e;
                        e.z =nz;
                        e.x = nx;
                        e.y = ny;
                        q.push(e);
                    }
                }
            }
        }
    if(d[endz][endx][endy] == 987654321) printf("Trapped!\n");
    else printf("Escaped in %d minute(s).\n", d[endz][endx][endy]-1);
    
    }
    return 0;
}