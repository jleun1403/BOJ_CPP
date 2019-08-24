#include <bits/stdc++.h>
using namespace std;
int a[10];
int d[10];
bool check[10];
int n, m;
set<string>s;
void go(int num){
    if(num == m){
        string str = "";
        for(int i=0; i<m; i++) str+= to_string(d[i]) + " ";
        if(s.count(str) == 0){
            s.insert(str);
            for(int i=0; i<m; i++) printf("%d ", d[i]);
            printf("\n");
            return;
        }
        return ;
    }
    for(int i=1; i<=n; i++){
        if( d[num-1] <=a[i] ){
            d[num] = a[i];
            go(num+1);
            d[num] = 0;
        }
    }
}
int main(){
    cin >> n>> m;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    sort(a+1,a+n+1);
    go(0);
    return 0;
}