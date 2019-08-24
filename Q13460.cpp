#include <bits/stdc++.h>
using namespace std;
int n, m;
int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, -1, 0, 1 };
char a[11][11];
int bfs(int rx, int ry, int hx, int hy, int bx, int by){
    queue <pair<int,int>> q;
    q.push(make_pair(rx,ry));
    while(!q.empty()){
        for(int i=0; i<4; i++){
       
        }
    }
}

int main(){
    cin >> n>> m;
    int redx,redy, bluex,bluey,hx,hy;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'B'){
                bluex= i;
                bluey = j;
            }
            if(a[i][j] == 'R'){
                redx = i;
                redy = j;
            }
            if(a[i][j] == '0'){
                hx = i;
                hy =j;
            }
        }
    }
    bfs(rx,ry,)

}