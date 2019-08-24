#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b, c;
    cin >>t;
    while(t--){
        
        scanf("%d %d %d", &a, &b, &c);
        if(a <b -c) printf("advertise\n");
        else if ( a == b-c) printf("does not matter\n");
        else printf("do not advertise\n");
    }
    return 0;
}