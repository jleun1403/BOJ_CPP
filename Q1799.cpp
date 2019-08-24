#include <bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
int ans =0;
int d[10][10]; // 색칠이 안되어있고 
vector<pair<int,int>> v;

bool check(int i, int j){
    int x = i-1;
    int y = j-1;
    while(x>=0 && y>=0){
        if(d[x][y]!=0) return false;
        else{
        x-=1;
        y-=1;
        }
    }
    x = i-1;
    y = j+1;
    while(x>=0 && y <n){
        if(d[x][y] !=0) return false;
        else{
            x-=1;
            y+=1;
        }
    }
    return true;  
}
void bishop(int x, int y) {
    if (x == n && y == 0) {
        int count = 0;
        for (int i  = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (d[i][j]){
                    count++;
                }
            }
        }
        ans = max(ans, count);
        return;
    }
    int nx = x;
    int ny = y + 1;
    if ( y == n - 1) {
        nx = x+1;
        ny = 0;
    }
    int count = 0;
    for (int i = 0 ; i < x*n + y ; i++) {
        if (d[i/n][i%n]) {
            count++;
        }
    }
    if (count + (n*n - (x*n+y)) < ans)
        return;
    //skip
    bishop(nx, ny);

    //put
    if (a[x][y]) {
        if(check(x, y)) {
            d[x][y] = true;
            bishop(nx , ny);
            d[x][y] = false;
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    bishop(0, 0);
    cout << ans << '\n';
    return 0;
}