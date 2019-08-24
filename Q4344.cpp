#include <bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
    int t,n,sum, score,cnt;
    cin >>t;
    while(t--){
        sum = 0; cnt = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
            sum+=a[i];
        }
        double avg = double(sum)/n;
        for(int i=0; i<n; i++){
            if(a[i] > avg) cnt+=1;
        }      
        printf("%.3f%%\n", (double)cnt/n *100);
    }
    return 0;
}