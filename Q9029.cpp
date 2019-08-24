#include <bits/stdc++.h>
using namespace std;
bool check[10001];
int prime[10001];
int main(){
    int t;
    cin >> t;

    for(int i=2; i<=10000; i++){
        if(check[i] == false){
            prime[i] = true;
            check[i] = true;
            for(int j=i*2; j<=10000; j+=i){
                check[j] = true;
            }
        }
    }
   
    while(t--){
        int n;
        cin >> n;
        for(int i=n/2; i>=0; i--){
            if(prime[i] == true && prime[n-i]== true){
                printf("%d %d\n", i, n-i);
                break;
            }
        }
    }
    return 0;
}