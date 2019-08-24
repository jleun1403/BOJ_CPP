#include <bits/stdc++.h>
#define inf 1000000007

using namespace std;
int fib[1000001];

int main() {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2 ; i <= 1000000 ; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        fib[i] %= inf;
    }
    int n;
    scanf("%d", &n);
    printf("%d\n", fib[n]);















  return 0;
}
