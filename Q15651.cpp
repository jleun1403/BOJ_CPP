#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
bool check[10];
void go(int num){
    if(num == m){
        for(int i=0; i<m; i++) 
        printf("%d ", arr[i]);
        printf("\n");
        return ;
    }
    for(int i=1; i<=n; i++){
            arr[num] = i;
            go(num+1);
            arr[num] = 0;
    }
}
int main(){
    cin >> n>> m;
    go(0);
    return 0;
}