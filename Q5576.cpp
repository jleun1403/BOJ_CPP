#include <bits/stdc++.h>
using namespace std;
int a[10], b[10];
int main(){
    for(int i=0; i<10; i++){
        scanf("%d", &a[i]);
    }
    for(int i=0; i<10 ; i++){
        scanf("%d", &b[i]);
    }
    sort(a, a+10);
    sort(b, b+10);
    printf("%d %d\n", a[9] + a[8] + a[7], b[9] + b[8] + b[7]);
    return 0;
}