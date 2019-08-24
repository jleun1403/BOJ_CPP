#include <bits/stdc++.h>
using namespace std;
double a[1001];
int main(){
    int n;
    cin >> n;
    double maxnum = 0, sum =0;
    for(int i=0; i<n; i++){
        scanf("%lf", &a[i]);
        maxnum = max(maxnum, a[i]);
    }
    for(int i=0; i<n; i++){
        a[i]= a[i]/maxnum * 100;
        sum += a[i];
    }
    printf("%.2f\n", (double)sum/n);
    return 0;

}