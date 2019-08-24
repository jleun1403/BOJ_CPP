#include <bits/stdc++.h>
using namespace std;

int main(){
    int sum =0;
    int a;
    for(int i=0; i<4; i++){
        scanf("%d", &a);
        sum+=a;
    }
    cout << sum/60 << '\n' <<  sum%60 << '\n';
    return 0;

}