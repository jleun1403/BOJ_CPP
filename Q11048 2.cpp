#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int d[1001][1001];
int main(){
    int n, m;
    cin >> n>> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    d[1][1] = a[1][1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1 && j==1) continue;
            d[i][j] = max(d[i-1][j], d[i][j-1]) + a[i][j];
        }
    }
    /*for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }*/
    cout << d[n][m] << '\n';
    return 0;
    
}