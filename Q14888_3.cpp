#include <bits/stdc++.h>
using namespace std;
int n;
int a[12];
int d[4];
int answer;
int minans = 987654321;
int maxans = -987654321;

bool canuse(int x){
    if(d[x] >0) return true;
    else return false;
}
void go(int index, int sum ){
    if(index == n) {
        minans = min(minans, sum);
        maxans = max(maxans, sum);
        return ;
    }
    int ans = sum;
    if(canuse(0)){
        d[0]-=1;
        sum=  ans+ a[index];
        go(index+1, sum);
        d[0]+=1;
    }
    if(canuse(1)){
        d[1] -=1;
        sum = ans- a[index];
        go(index+1, sum);
        d[1] +=1;
    }
    if(canuse(2)){
        d[2] -=1;
        sum = ans* a[index];
        go(index+1, sum);
        d[2] +=1;
    }
    if(canuse(3)){
        d[3] -=1;
        sum = ans /a[index];
        go(index+1, sum);
        d[3]+=1;
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<4; i++){
        cin >> d[i];
    }
    go(1, a[0]);
    cout << maxans << '\n';
    cout << minans << '\n';
    
    return 0;

}