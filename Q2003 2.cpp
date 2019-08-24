#include <bits/stdc++.h>
using namespace std;
int ans;
int a[10001];
int main(){
    int n, m;
    cin >> n>> m;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    int left =1, right =1, ans=0, sum =0;
    while(left <= right && right <=n+1){
        if(sum >=m){
            if(sum == m) ans +=1;
            sum -=a[left];
            left+=1;
        }
        else {
            if(right == n+1) break;
            sum+= a[right];
            right +=1;
        }
    }
    cout << ans << '\n';
    return 0;

}