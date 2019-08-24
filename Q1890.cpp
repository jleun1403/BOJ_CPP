#include <bits/stdc++.h>
using namespace std;
int a[101][101];
long long d[101][101];
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    d[1][1] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i ==1 && j == 1) continue;
            for(int k=1; k<j; k++){
                if(a[i][k] + k == j){
                    d[i][j] += d[i][k];
                }
            }
            for(int k=1; k<i; k++){
                if(a[k][j] + k == i){
                    d[i][j] += d[k][j];
                }
            }
        }
    }
    cout << d[n][n] << '\n';
    return 0;
}