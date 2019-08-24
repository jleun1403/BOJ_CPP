#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int answer = 0;
    for(int i=1; i<=n; i++){
            for(int j = i; i*j <=n; j++){
                answer+=1;
            }
        }
    
    cout << answer << '\n';
    return 0;
}