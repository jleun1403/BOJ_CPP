#include <bits/stdc++.h>
using namespace std;

int main(){
    int answer = 0;
    int sum = 0;
    int a, b;
    for(int i=0; i<4; i++){
        cin >> a >> b;
        answer += b-a;
        sum = max(sum, answer);
    }
    cout << sum << '\n';
    return 0;
}