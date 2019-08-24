#include <bits/stdc++.h>
using namespace std;
int n, length, weight;
int a[1001];
int truck[101];
int answer;
int cnt;
int weight_sum;
int main(){
   cin >> n>> length >> weight;
   for(int i=0; i<n; i++){
       scanf("%d", &a[i]);
   }
   int target = 0, right = 0;
   int number= n;
   while(n>0){
       if(cnt!=0){ // is truck
            for(int i=right; i<target; i++){
                truck[i] +=1;
            }
            if(truck[right] == length+1){
                cnt-=1;
                weight_sum -= a[right];
                right +=1;
                n-=1;
            }
       }
       if(target < number){
           if(cnt+1 <= length && a[target] + weight_sum <= weight){
               cnt+=1;
               weight_sum += a[target];
               truck[target]+=1;
               target+=1;
           }
       }
       answer+=1;
   }
   cout << answer << '\n';
   return 0;
}