#include <bits/stdc++.h>
using namespace std;
int n;
int a[16];
int p[16];
int d[16];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        scanf("%d %d", &a[i], &p[i]);
    }

    for(int i=n; i>=1; i--){
        if(i == n){
            if(a[i] ==1) d[i] = p[i];
            else d[i] =0;
            continue;
        }
        
        if(i + a[i]-1  <=n){
            d[i] = p[i] + d[i+a[i]];
        }
        
        int m = 0;
        for(int k=i; k<=n; k++){
            m= max(m, d[k]);
        }
        d[i] = m;
    }
    cout << d[1];
    return 0;
}