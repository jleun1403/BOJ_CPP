#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[31][11];
int ans = 987654321;
void dfs(int count, int x, int y){
    if(count > ret) return;
    if(check()) {
        ret = count;
        return;
    }
    if (count ==3) return;
    for()

int main(){
    scanf("%d %d %d", &n, &m, &k);
    int x, y;
    for(int i=0; i<m; i++){
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
    }
    int ans = 4;
    dfs(0 ,1, 1);
    if(ans == 4) ans = -1;
    cout << ans << '\n';

}