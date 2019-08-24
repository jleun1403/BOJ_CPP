#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int answer= 0;
    for(int i=0; i<5; i++){
        int a;
        cin >> a;
        if(a%10==n) answer+=1;
    }
    cout << answer<< '\n';
    return 0;

}