#include <iostream>

using namespace std;

int main(){
    long factorial[13];
    int n;
    scanf("%d", &n);
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2 ; i <= 13 ; i++)
        factorial[i] = factorial[i-1] * i;
    printf("%ld", factorial[n]);
}
