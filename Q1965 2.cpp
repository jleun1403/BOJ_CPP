#include <bits/stdc++.h>
using namespace std;
int a[1001];
int d[1001];
int answer;
int main(){
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n; i++){
        d[i] = 1;
        for(int j=0; j<=i; j++){
            if(a[j] <a[i] && d[i] < d[j] +1){
                d[i] = d[j] +1;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(answer < d[i]) answer = d[i];
    }
    cout << answer << '\n';
    return 0;
}