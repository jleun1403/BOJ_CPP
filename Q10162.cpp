#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool ok = false;
    int num300=0, num60 = 0, num10=0;
    num300 += n/300;
    n%=300;
 
    num60 +=n/60;
    n%=60;

    num10 += n/10;
    n%=10;

    if(n!=0 && n<10) printf("-1\n");
    else printf("%d %d %d\n", num300, num60, num10);
    return 0;
    
}