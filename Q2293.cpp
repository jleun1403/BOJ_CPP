#include <bits/stdc++.h>
using namespace std;
int a[101];
int d[10001];
int main(){
    int n, m;
    cin >> n>> m;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    d[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(j-a[i] >=0){
                d[j] +=d[j-a[i]];
            }
        }
    }
}