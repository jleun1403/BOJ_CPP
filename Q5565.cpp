#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int sum =0;
    for(int i=0; i<9; i++){
        int a;
        cin >> a;
        sum+=a;
    }
    cout << n-sum << '\n';
    return 0;
}