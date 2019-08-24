#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >>e;
    int sum1 ,sum2;
    sum1 = min(min(a,b), c);
    sum2 = min(d, e);
    cout << sum1 +sum2 -50 << '\n';
    return 0;
}