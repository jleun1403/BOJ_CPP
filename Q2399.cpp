#include <bits/stdc++.h>
using namespace std;
int a [10001];
int main(){
    int n;
    cin >> n;
    long long sum = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            sum += abs(a[i]-a[j]);
        }
    }
    printf("%lld\n", sum*2);
    return 0;
}