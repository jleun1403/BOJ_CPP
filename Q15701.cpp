#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

bool isSquare(long long x) {
    long long t = (long long)(sqrt(x) + 0.5);
    return t*t == x;
}

int main() {
    long long n;
    scanf("%lld", &n);
    int ans = 0;
    if (n == 2) {
        printf("2");
        return 0;
    }
    else if (n == 3){
        printf("2");
        return 0;
    }
    for (int i = 1; i < sqrt(n) ; i++) {
        if (n % i == 0)
            ans++;
    }
    ans *= 2;
    if (isSquare(n))
        ans++;
    printf("%d", ans);
















  return 0;
}
