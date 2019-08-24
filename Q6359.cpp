#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int d[101];
int main(){
    int n , t, cnt;
    cin >> t;
    for(int i=1; i<=100; i++){ // i round
        for(int j=1; j<=100; j++){ // j room
            if(j%i == 0){
                if(a[i-1][j]==0) a[i][j] = 1;
                else a[i][j] = 0;
            }
            else a[i][j] = a[i-1][j];     
        }
    }
    while(t--){
        scanf("%d", &n);
        cnt = 0;
        for(int i=1; i<=n; i++){
            if(a[n][i] == 1) cnt +=1;
        }
       printf("%d\n", cnt);
    }
    return 0;
}