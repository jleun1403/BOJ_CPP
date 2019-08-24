#include <bits/stdc++.h>
using namespace std;
int n, w, L;
int a[1001];
int truck[101];
int t=0;
int result;
int main(){
    cin >> n>> w >> L;
    for(int i=0; i<n; i++){
       scanf("%d", &a[i]);
    }
    int cnt = 0;
    int left_weight = 0;
    int i=0, j=0, limit = n-1;

     while(n>0){ 
      
      if(cnt!=0){ 
        for(int q=j; q<i; q++){
            truck[q]++;
        }
        
        if(truck[j]==w+1){ 
            cnt--;
            left_weight-=a[j];
            j++;
            n--;
        }
      }
      
      if(i<=limit){ 
        if( cnt+1<=w && left_weight+a[i]<=L){
          cnt++;
          left_weight+=a[i];
          truck[i]++;
          i++;
        }
      }
      
      result++;
    }
    cout << result << '\n';
    return 0;
}