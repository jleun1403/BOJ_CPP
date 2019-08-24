#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> a;
int c[3] = {0, 0, 0};

bool same(int x, int y, int n) {
    int temp = a[x][y];
    for (int i = x ; i < x + n ; i++) {
        for (int j = y ; j < y + n ; j++){
            if (a[i][j] != temp)
                return false;
        }
    }
    return true;
}

void solve(int x, int y, int n) {
    if (same(x, y, n)){
        c[a[x][y]]++;
        return;
    }
    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 3 ; j++) {
            solve(x+ i*n/3, y+ j*n/3, n/3);
        }
    }
}

int main(){
    int n;
    cin >> n;
    a.resize(n, vector<int>(n));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n; j++){
            int k;
            cin >> k;
            a[i][j] = k + 1;
        }
    }
    solve(0, 0, n);
    cout << c[0]<<'\n';
    cout << c[1]<<'\n';
    cout << c[2]<<'\n';
}
