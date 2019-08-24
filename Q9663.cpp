#include <bits/stdc++.h>
using namespace std;
int a[16][16];
int n;
int ans;
bool check[16][16];
bool solve(int row, int col){
    for(int i=0; i<n; i++){
        if(row == i) continue;
        if( check[i][col] == true) return false;
    }
    int x = row-1;
    int y = col-1;
    while(x>=0 && y >=0){
        if(check[x][y]) return false;
        x-=1;
        y-=1;
    }
    x = row -1;
    y = col +1;
    while(x>=0 && y<n){
        if(check[x][y]) return false;
        x-=1;
        y+=1;
    }
   return true;

}
void dfs(int row){
    if(row == n){
        ans +=1;
    }
    for(int col =0; col<n; col++){
        check[row][col] = true;
        if(solve(row,col)) {
            dfs(row+1);
        }
        check[row][col] = false;
    }
}
int main(){
    cin >> n;
    dfs(0);
    cout << ans << '\n';
    return 0;
}