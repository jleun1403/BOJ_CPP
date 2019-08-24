#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
int a[10];
bool check[10001];
void go(int num){
    if(num == m){
        for(int i=0; i<m; i++) 
        printf("%d ", arr[i]);
        printf("\n");
        return ;
    }
    for(int i=1; i<=n; i++){
        if( check[a[i]] == false && arr[num-1] < a[i]){
            check[a[i]] = true;
            arr[num] = a[i];
            go(num+1);
            check[a[i]]= false;
            arr[num] = 0;
        }
    }
}
int main(){
    cin >> n>> m;
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    sort(a+1, a+1+n);
    go(0);
    return 0;
}