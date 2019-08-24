#include <bits/stdc++.h>
using namespace std;

int d[101][101];
int v[101][101];
int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(d[a][b] == 0){
            d[a][b] = c;
        }
        else d[a][b] = min(d[a][b], c);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            v[i][j] = j;
        }
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j) continue;
                if(d[i][k]!=0 && d[k][j] !=0){
                   if(d[i][j] ==0) {
                       d[i][j] = d[i][k] + d[k][j];
                       v[i][j] = k;
                   }
                   else {
                       if( d[i][j] > d[i][k] + d[k][j]){
                           d[i][j] = d[i][k] + d[k][j];
                           v[i][j] = k;
                       }
                   } 
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", v[i][j]);
        }
        cout << '\n';
    }

    return 0;
}