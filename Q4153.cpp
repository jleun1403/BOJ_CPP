#include <bits/stdc++.h>
using namespace std;
int a[4];
int main(){
    while(true){
        for(int i=0; i<3; i++) scanf("%d", &a[i]);
        sort(a, a+3);
        if(a[0] ==0 && a[1]==0 && a[2]==0) break;
        if(sqrt(pow(a[0],2) + pow(a[1],2)) ==a[2]) printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}