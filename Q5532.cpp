#include <bits/stdc++.h>
using namespace std;

int main(){
    int l, a, b, c, d;
    int sum1 = 0, sum2=0 , sum =0;
    scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
    if(a%c == 0) sum1=a/c;
    else sum1=a/c+1;
    if(b%d==0) sum2 = b/d;
    else sum2 = b/d +1;
    sum = max(sum1, sum2);
    printf("%d\n", l-sum);
    return 0;
}