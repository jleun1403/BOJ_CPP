#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int a[1001][1001];
int d[1001][1001];
bool check[1001][1001];
int answer = 0;
queue <pair<int,int>> q;
vector<pair<int,int>> tomato ;
bool all(){
    bool ok = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(d[i][j] ==0){
                return false;
            }
        }
    }
    return true;
}
int main(){
    cin >> m>> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] == 1){
                q.push(make_pair(i,j));
                check[i][j] = true;
                d[i][j] =1;
            }
            else if(a[i][j] == -1){
                check[i][j] = true;
                d[i][j] = -1;
            }
        }
    }

        while(!q.empty()){
            int x= q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx>=0 && nx <n && ny >=0 && ny <m && !check[nx][ny]){
                    if(a[nx][ny] == 0){
                        d[nx][ny] = d[x][y] +1;
                        check[nx][ny] = true;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
        if(!all()) cout << "-1\n";
        else {
            int maxnum = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    maxnum = max(maxnum, d[i][j]);
                }
            }
            cout << maxnum-1 << '\n';
        }          
        return 0;
    }