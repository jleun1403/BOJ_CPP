#include <bits/stdc++.h>
using namespace std;
bool prime[10000001];
bool check[1000001];
int main(){
    int n, m;
    cin >> n>> m;
    for(int i=2; i<=m; i++){
        if(check[i] == false){
            prime[i] = true;
            for(int j=i*2; j<=m; j+=i){
                check[j] = true;
            }
        }
    }
    for(int i=n; i<=m; i++){
        if(prime[i] == true){
            cout << i << '\n';
        }
    }
    return 0;
}