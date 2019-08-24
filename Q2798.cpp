#include <bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    int n, m;
    cin >> n>> m;
    for(int i=0; i<n ; i++){
        scanf("%d", &a[i]);
    }
    int sum = 0;
    int answer= 0;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                sum = a[i] + a[j] + a[k];
                if( sum <=m ){
                    answer = max(answer, sum);
                }
            }
        }
    }
    cout << answer << '\n';
    return 0;
}