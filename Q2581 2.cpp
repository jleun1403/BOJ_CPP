#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

bool isprime[10001];

void go() {
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for (int i = 2 ; i <= 10000 ; i++) {
        if (isprime[i]) {
            for (int j = i*i ; j <= 10000 ; j += i) {
                isprime[j] = false;
            }
        }
    }
}


int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    go();
    int ans = inf;
    int sum = 0;
    for (int i = m ; i <= n ; i++) {
        if (isprime[i]) {
            sum += i;
            ans = min(ans, i);
        }
    }
    if (sum == 0)
        printf("-1");
    else {
        printf("%d\n%d", sum, ans);
    }
















  return 0;
}
