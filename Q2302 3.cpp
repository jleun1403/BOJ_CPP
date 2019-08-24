#include <bits/stdc++.h>
using namespace std;
bool check[41];
long long d[41];
int main(){
    int n, fix;
    cin >> n >> fix;
    for(int i=0; i<fix; i++){
        int a;
        scanf("%d", &a);
        check[a] = true;
    }
    d[0] = 1;
    d[1] = 1; 
    d[2] = 2;
    for(int i=3; i<=40; i++){
        d[i] = d[i-1] + d[i-2];
    }
    long long answer= 1;
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(check[i] == true){
            answer *= d[cnt] ;
            cnt= 0;
        }
        else cnt+=1;
    }
    answer*=d[cnt];
    printf("%lld\n", answer);
    return 0;
}