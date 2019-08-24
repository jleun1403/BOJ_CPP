#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> a;

bool same(int x, int y, int n) {
    int temp = a[x][y];
    for (int i = x ; i < x+ n ; i++) {
        for (int j = y ; j < y + n ; j++) {
            if (a[i][j] != temp)
                return false;
        }
    }
    return true;
}

void solve(int x, int y, int n){
    if (same(x, y, n)){
        cout << a[x][y];
        return;
    }
    else {
        cout << "(";
        solve(x, y, n/2);
        solve(x, y+n/2, n/2);
        solve(x+n/2 , y, n/2);
        solve(x+n/2, y+n/2 , n/2);
        cout << ")";
    }
}

int main(){
    int n;
    cin >>n;
    a.resize(n, vector<int> (n));
    for (int i = 0; i < n ; i++) {
        for (int j = 0 ; j < n; j++) {
            scanf("%1d",&a[i][j]);
        }
    }
    solve(0,0,n);










}
