#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, a, cnt =0, n;
    float b, sum;
    cin >> t;
    while(t--){
        cin >> n;
        cnt = 0;
        sum = 0;
        for(int i=0; i<n; i++){
            scanf("%d %f", &a, &b );
            cnt += a;
            sum += a*b;

        }
        printf("%d %.1f\n", cnt, sum / (float)cnt);
    }
    return 0;
}