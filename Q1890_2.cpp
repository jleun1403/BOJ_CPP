#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int d[101][101];
int n;
int answer ;
void dfs(int i, int j){
    int x = i;
    int y = j;
    if(i ==n && j == n){
        
    }
    for(int i=0; i<2; i++){
        if(x + a[x][y]<=n){

        }
    }
}
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(1,1));
    dfs(1,1);
}