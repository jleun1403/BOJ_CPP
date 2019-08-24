#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y){
    if(y ==0) return x;
    else return gcd(y, x%y);
}
int main(){
    int n, a, b,c;
    cin >>n;
    if(n == 2) {
        scanf("%d %d", &a, &b);
        int x =gcd(a,b);
        for(int i=1; i<=x; i++){
            if(x%i == 0) printf("%d\n", i);
        }
    }
    else {
        scanf("%d %d %d", &a, &b, &c);
        int x= gcd(gcd(a,b),c);
        for(int i=1; i<=x; i++){
            if(x%i == 0) printf("%d\n", i);
        }

    }
    return 0;
}