#include <bits/stdc++.h>
using namespace std;
int a[6][6];
int check[1000000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int num;
int answer;
void dfs(int x, int y, int cnt, int num){
    if(cnt == 6){
        if(check[num] == false){
            check[num] = true;
            answer +=1;
        }
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >=0 && nx <5 && ny >=0 && ny <5){
            dfs(nx,ny,cnt+1, num*10 + a[nx][ny]);
        }
    }
}
int main(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            num = 0;
            dfs(i,j, 1, a[i][j]);
        }
    }
    printf("%d\n", answer);
    return 0;
}