#include <bits/stdc++.h>
using namespace std;

int main(){
    int sum1 = 0, sum2 = 0;
    int a;
    for(int i=0; i<4; i++){
        scanf("%d", &a);
        sum1 +=a;
    }
    for(int i=0; i<4; i++){
        scanf("%d", &a);
        sum2+=a;
    }
    cout << max(sum1, sum2) << '\n';
    return 0;
}