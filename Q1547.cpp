#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n;
    int start = 1;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        if(a == start){
            start = b;
        }
        else if(b == start){
            start = a;
        }
    }
    cout << start << '\n';
    return 0;
}