#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y){
    if(y==0) return x;
    else return gcd(y,x%y);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int m , n, x, y;
        scanf("%d %d %d %d", &m, &n, &x, &y);
        int minnum = m * n /gcd(m,n);
        cout << minnum << '\n';
        while(true){
            if(x>minnum || (x-1)%n +1  ==y) break;
            x+=m;
        }
        if(x > minnum) printf("-1\n");
        else printf("%d\n", x);
    }
    return 0;
}
//binary-search