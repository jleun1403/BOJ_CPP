#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long sum = 0;
    while(n>=1){
        sum+=n;
        n-=1;
    }
    cout << sum << '\n';
    return 0;
}