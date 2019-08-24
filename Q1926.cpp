#include <bits/stdc++.h>
using namespace std;
int a[501][501];
int d[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;
int num;
int answer;
void dfs(int x, int y, int cnt){
    d[x][y] = cnt;
    for(int i=0; i<4; i++){
        int nx= x + dx[i];
        int ny= y + dy[i];
        if(nx >= 0 && nx <n && ny >=0 && ny <m && d[nx][ny] == 0 && a[nx][ny] == 1){
            num +=1;
            dfs(nx, ny, cnt);
        }
    }
   
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int temp = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 1 && d[i][j] == 0){
                num = 1;
                temp +=1;
                dfs(i,j,temp);
                answer = max(answer, num);
            }
        }
    }
    printf("%d\n", temp);
    printf("%d\n", answer);
    return 0;

}

