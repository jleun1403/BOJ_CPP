#include <bits/stdc++.h>
using namespace std;
long long a[1000001];
long long sum[1000001];
long long cnt[1001];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }
    sum[0] = 0;
    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1] + a[i];
    }
    for(int i=1; i<=n; i++){
        cnt[sum[i]%m] +=1;
    }
    cnt[0] +=1;
    long long answer= 0;
    for(int i=0; i<m; i++){
        answer += cnt[i]*(cnt[i]-1)/2;
    }
    //for(int i=1; i<=n; i++) printf("%d ", sum[i]);
    printf("%lld\n", answer);
    return 0;
    
}