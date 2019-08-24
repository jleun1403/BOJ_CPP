#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
long long A[101], B[101];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%lld", &B[i]);
    }
    for (int i = 1 ; i <= n ; i++) {
        printf("%lld ", B[i]*i - B[i-1]*(i-1));
    }
















  return 0;
}
