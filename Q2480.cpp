#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int answer= 0;
    if(a ==b && b == c){
        answer = 10000 + 1000*a;
    }
    else if (a!=b && a!=c &&b!=c) {
        int maxnum = 0;
        maxnum = max(max(a,b),c);
        answer= maxnum *100;
    }
    else {
        int num = 0;
        if(a==b && b!=c) num = a;
        else if(a == c && a!=b) num = a;
        else if (b==c && a!=b) num = b;
        answer= 1000 + 100 * num;
    }
    cout << answer << '\n';
    return 0;
}