#include <bits/stdc++.h>
using namespace std;
int fibo[30];
int main(){
    int n, k;
    cin >> n>> k;
    fibo[1] = 1;
    fibo[2] = 1;
    for(int i=3; i<=n; i++){
        fibo[i] = fibo[i-2] + fibo[i-1];
    }
    for(int i=1; ; i++){
        if((k -fibo[n-2] *i) %fibo[n-1] ==0){
            printf("%d\n", i);
            printf("%d\n", (k-fibo[n-2]*i)/fibo[n-1]);
            break;
        }
    }
    return 0;
}