#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

bool isSquare(long long p) {
    long long q = (long long)(sqrt(p) + 0.5);
    return q*q == p;
}

int main() {
    long long p;
    scanf("%lld", &p);

    printf("%lld", isSquare(p) ? (long long)(sqrt(p) + 0.5) : (long long)(sqrt(p) +1 ));
















  return 0;
}
