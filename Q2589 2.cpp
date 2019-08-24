#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[52][52];
int dx[4] = { -1, 1, 0 ,0};
int dy[4] = { 0, 0 ,- 1, 1};
int d[52][52];
bool check[52][52];
int d2[52][52];
int answer;
void dfs(int x, int y, int cnt){
    d[x][y] = cnt;
    for(int i=0; i<4; i++){
        int nx =x + dx[i];
        int ny= y + dy[i];
        if(nx>=0 && nx <n && ny>=0 && ny <m){
            if(d[nx][ny] == 0 && a[nx][ny] == 'L'){
                dfs(nx,ny,cnt);
            }
        }
    }
}
int bfs(int i, int j, int k){
    int ret = 0;
    memset(d2, 0, sizeof(d2));
    queue <pair<int,int>> q;
    q.push(make_pair(i,j));
    check[i][j] = true;
    d2[i][j] = 1;
    while(!q.empty()){
        int x= q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx <n && ny >=0 && ny <m){
                if(d2[nx][ny] == 0 && d[nx][ny] == k){
                    d2[nx][ny] = d2[x][y] +1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(d2[i][j]!=0){
                ret= max (ret, d2[i][j]);
            }
        }
    }
    return ret;
}
int main(){
    cin >> n>> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf(" %c", &a[i][j]);
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] =='L' && d[i][j] ==0){
                cnt+=1;
                dfs(i,j, cnt);
            }
        }
    }
    bool ok =false;
    if(cnt ==0) {
        printf("0\n"); 
        return 0;
        }
    for(int k=1; k<=cnt; k++){
        ok = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(d[i][j] ==k){
                    answer = max(answer, bfs(i,j,k));
                    ok = true;
                    break;
                }
            }
            if(ok == true) break;
        }
    }
    printf("%d\n", answer);
    return 0;

}