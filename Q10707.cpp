#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, p;
    int sum1, sum2;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);
    sum1 = a*p;
    if( p<=c) sum2 = b;
    else sum2 = b + (p-c) * d;
    printf("%d\n", min(sum1, sum2));
    return 0;

}