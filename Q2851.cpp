#include <bits/stdc++.h>
using namespace std;
int a[12];
int sum[12];
int main(){
    sum[0] = 0;
    for(int i=1; i<=10 ; i++){
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    int answer= 0;
    int d= 987654321;
    for(int i=1; i<=10; i++){
        if( d > abs(sum[i] - 100)) {
            d = abs(sum[i] - 100);
            answer= sum[i];
            }
        else if (d == abs(sum[i] - 100)){
            if(sum[i] - 100 >=0) answer = sum[i];
        }
    }
    cout << answer << '\n';
    return 0;

}