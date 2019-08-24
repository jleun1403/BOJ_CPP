#include <bits/stdc++.h>
using namespace std;
int a[1000001];
long long ans;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
    }
    int b,c;
    cin >> b >> c;
    for(int i=0; i<n; i++){
        if(a[i] <=b) {
            ans+=1;
        }
        else{
            if((a[i]-b) % c ==0){
                ans+=(a[i]-b)/c +1;
            }
            else{
                ans+=(a[i]-b)/c +2;
            }
        }
        
    }
    cout << ans << '\n';
    return 0;

}