#include <bits/stdc++.h>
using namespace std;
int prime[4000001];
bool check[4000001];
int main(){
    int n;
    cin >> n;
    int cnt=0;
    for(int i=2; i<=n; i++){
        if(check[i] == false){
            prime[cnt++] = i;
            for(int j=i*2; j<=n; j+=i){
                check[j] = true;
            }
        }
    }
    //cout << "cnt" << cnt << '\n';
    //cout <<prime[0] << '\n';

    int left = 0, right = 1;
    long long sum = prime[0];
    int ans =0;
    while(left <=right && right <=cnt){
        if(sum >=n){
            if(sum == n) ans+=1;
            sum-=prime[left];
            left+=1;
        }
        else{
            if(right == cnt) break;
            else{
                sum+=prime[right];
                right +=1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}