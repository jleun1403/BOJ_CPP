#include <bits/stdc++.h>
using namespace std;
bool prime[10001];
int main(){
    int n , m;
    cin >> m>> n;
    prime[1] = 1;
    for(int i=2; i<=10000; i++){
        if(!prime[i]){
            for(int j=i*2; j<=10000; j+=i){
                prime[j] = 1;
            }
        }
    }
    int answer =0;
    long long sum = 0;
    int cnt = 0;
    bool ok =false;
    for(int i = m; i<=n; i++){
        if(prime[i] == 0){
            if(ok == false){
                answer= i;
                ok = true;
            }
            cnt+=1;
            sum+=i;          
        }
    }
    if(cnt == 0) printf("-1\n");
    else {
        printf("%lld\n", sum);
        printf("%d\n", answer);
    } 
    return 0;
}