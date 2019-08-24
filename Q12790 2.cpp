#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int sum = 0;
        int a,b, c, d, a1, b1, c1, d1;
        scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &a1, &b1, &c1, &d1);
        if(a + a1<1) a= 1, a1 = 0;
        if(b + b1 <1) b=1, b1 = 0;
        if(c +c1 <0) c1 = 0, c=0;
        sum = (a +a1) *1 + (b +b1 ) *5 + (c+c1) *2 + (d + d1)*2;
        printf("%d\n", sum);
    }
    return 0;
}