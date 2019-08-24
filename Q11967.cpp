#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int,int>> v[101][101];
bool answer[101][101];
bool check[101][101];
int n;
queue <pair<int,int>> q;
bool ok = false;
bool dfs(int x, int y, int from, int to){
    check[x][y] = true;
    if(abs(x-from) + abs(y-to) == 1) {//cout << x << y << from << to << "@@\n"; 
        ok = true;
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=1 && nx<=n && ny >=1 && ny<=n){
            if(answer[nx][ny] == true && check[nx][ny] == false){
                dfs(nx,ny,from,to);
            }
        }
    }
    if(ok == true) return true;
    else return false;
}
void go(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<v[x][y].size(); k++){
            int nx = v[x][y][k].first;
            int ny = v[x][y][k].second;
            if(answer[nx][ny] == false ){
                answer[nx][ny] = true;
                q.push(make_pair(nx,ny));   
            }
        }
        for(int k=0; k<v[x][y].size(); k++){
            int nx= v[x][y][k].first;
            int ny = v[x][y][k].second;
            ok = false;
            if(answer[nx][ny] == false && dfs(x,y,nx,ny) == true){
                answer[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
int main(){
    int m, ans=0;
    cin >> n>> m;
    int x ,y, w, z;
    while(m--){
        cin >> x >>y >>w >> z;
        v[x][y].push_back(make_pair(w,z));
    }
    q.push(make_pair(1,1));
    go();
    answer[1][1] = true;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(answer[i][j] == 1) ans +=1;
           
        }
    
    }
    cout << ans<< '\n';
    return 0;
}