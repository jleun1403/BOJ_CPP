#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int,int>> v[101][101];
bool check[101][101];
bool answer[101][101];
int bfs(){
    memset(check,false,sizeof(check));
    queue <pair<int,int>> q;
    q.push(make_pair(1,1));
    check[1][1] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        bool found = false;
        for(int i=0; i<v[x][y].size(); i++){
            int nx = v[x][y][i].first;
            int ny = v[x][y][i].second;
            if(answer[nx][ny] == false){
                answer[nx][ny] = true;
                found = true;
            }

        }
        if(found == true) return -1;
        for(int i=0; i<4; i++){
            int nx= x +dx[i];
            int ny = y + dy[i];
            if(nx>=1 && nx <=n && ny>=1 && ny<=n){
                if(check[nx][ny] == false){
                    if(answer[nx][ny] == true){
                        check[nx][ny] = true;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(answer[i][j] == true){
                ans +=1;
            }
        }
    }
    return ans;
}
int main(){
    cin >> n>> m;
    int a, b ,c,d;
    while(m--){
        cin >> a >>b >> c >>d;
        v[a][b].push_back(make_pair(c,d));
    }
    answer[1][1] = true;
    while(true){
        int k = bfs();
        if(k !=-1){
            printf("%d\n", k);
            return 0;
        }
    }
    return 0;

}