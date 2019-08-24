#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long answer = 0;
    for(int i=1; i<=n; i++){
        answer += i*(i+1);
    }
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum+=i;
        answer += sum;
    }
    cout << answer << '\n';
    return 0;
}