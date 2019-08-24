#include <bits/stdc++.h>
using namespace std;
int sum[15];
int d[15][15];
int main(){
    int t, n, m;
    cin >> t;
    for(int i=1; i<=14; i++){
        sum[i] += sum[i-1] + i;
    }
    for(int i=1; i<=14; i++) d[0][i] = i;

    for(int i=1; i<=14; i++){
        for(int j=1; j<=14; j++){
            for(int k = 1; k<=j; k++){
                d[i][j] += d[i-1][k];
            }
        }
    }
    while(t--){
        scanf("%d %d", &n, &m); // n층 m호
        printf("%d\n", d[n][m]);
    }
    return 0;
}