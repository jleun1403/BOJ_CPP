#include <bits/stdc++.h>
using namespace std;
int a[2001];
bool d[2001][2001];
int main(){
    int n, m;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i=1; i<=n; i++){
        d[i][i] = true;
    }
    for(int i=1; i<=n-1; i++){
        if(a[i] == a[i+1]) d[i][i+1] = true;
        //else d[i][i+1] = false;
    }
    for(int k=3; k<=n; k++){
        for(int i=1; i<=n-k+1; i++){
            int j = i + k-1;
            if(a[i] == a[j] && d[i+1][j-1] == true) d[i][j] = true;
        }
    }
    while(m--){
        int left, right;
        scanf("%d %d", &left, &right);
        printf("%d\n", d[left][right]);
    }
    return 0;
}