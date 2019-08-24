#include <bits/stdc++.h>
using namespace std;
int a[7][3];
int main(){
    int n, k, s, y;
    int answer = 0;
    cin >> n>> k;
    for(int i=0; i<n ; i++){
        scanf("%d %d", &s, &y);
        a[y][s] +=1;
    }
    for(int i=1; i<=6; i++){
        for(int j=0; j<2; j++){
            if(a[i][j] ==0) continue;
            else if ( a[i][j] <=k) answer +=1;
            else{
                answer += a[i][j] / k;
                if(a[i][j] %k !=0) answer +=1;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}