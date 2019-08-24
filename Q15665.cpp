#include <bits/stdc++.h>
using namespace std;
int a[10];
int d[10];
int n, m,cnt;
set<int> number;
void go(int num){
    if(num ==m){
        for(int i=0; i<m; i++) printf("%d ", d[i]);
        printf("\n");
        return;
    }
    for(int i=0; i<cnt; i++){
        d[num] = a[i];
        go(num+1);
        d[num] = 0;
    }
}
int main(){
    int num;
    cin >> n>> m;
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if(number.count(num) == 0){
            number.insert(num);
            a[cnt]=num;
            cnt+=1;
        }
    }
    sort(a, a+cnt);
    go(0);
    return 0;
}