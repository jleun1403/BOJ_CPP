#include <bits/stdc++.h>
using namespace std;
vector <int> bricks;
int a[501];
int low[501];
int high[501];
int main(){
    int n, m;
    cin >> m >> n;
    int lownum = 0, highnum = 0;
    int answer = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    lownum = a[0];
    highnum = a[n-1];
    for(int i=1; i<n; i++){
        low[i] = lownum;
        if(a[i] >lownum) {
            low[i] = 0;
            lownum = a[i];
        }
    }
    for(int i=n-2; i>=0; i--){
        high[i] = highnum;
        if(a[i] >highnum) {
            high[i] = 0;
            highnum = a[i];
        }
    }
    for(int i=1; i<n-1; i++){
      if(min(low[i],high[i]) != 0) 
        answer += min(low[i], high[i]) - a[i];
    }
    cout << answer << '\n';
    return 0;
}
