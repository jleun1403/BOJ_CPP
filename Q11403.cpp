#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[101][101];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(a[i][k] ==1 && a[k][j] ==1){
                    a[i][j] = 1;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", a[i][j]);
        }
        cout << '\n';
    }
    return 0;
}