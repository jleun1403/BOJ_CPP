#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int main() {
    int n;
    long long answer = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n ; i++) {
        answer += (long long)i * (i+1) * 3 / 2;
    }
    printf("%lld", answer);
















  return 0;
}
