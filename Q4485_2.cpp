#include <bits/stdc++.h>
using namespace std;
int a[126][126];
int d[126][126];
int main(){
    int n;
    int t = 0;
    while(true){
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));
        if(n ==0) break;
        t+=1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                scanf("%d", &a[i][j]);
            }
        }
        for(int i=1; i<=n; i++){
            d[0][i] = 987654321;
            d[i][0] = 987654321;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i ==1 && j ==1) d[i][j] = a[i][j];
                else d[i][j] = min(d[i-1][j], d[i][j-1]) + a[i][j];
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << d[i][j] << ' ';
            }
            cout << '\n';
        }
        printf("Problem %d: %d\n",t, d[n][n]);
    }
    return 0;
}