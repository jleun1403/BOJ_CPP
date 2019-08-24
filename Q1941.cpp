#include <bits/stdc++.h>
using namespace std;
char a[6][6];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool check[5][5];
int ans = 0;
void dfs(int x, int y, int snum, int len){
    
    if(len == 7 && snum>=4){
        ans +=1;
        return;
    }
    check[x][y] = true;
    for(int k=0; k; k++){
        int nx = x + dx[k];
        int ny = y+ +dy[k];
        if(nx>=0 && nx <5 && ny>=0 && ny <5){
            if(check[nx][ny] == false){
                if(a[nx][ny] == 'S') dfs(nx,ny,snum+1,len+1);
                else dfs(nx,ny,snum,len+1);
            }
        }
    }
    check[x][y] = false;
}
int main(){
    for(int i=0; i<5; i++){
        string s;
        cin >> s;
        for(int j=0; j<5; j++){
            a[i][j] = s[j];
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            dfs(i,j)
        }
    }
    cout << ans << '\n';
    return 0;
}