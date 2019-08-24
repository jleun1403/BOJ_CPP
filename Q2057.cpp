#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    if (n == 0) {
        printf("NO");
        return 0;
    }
    long long a[21];
    a[0] = 1;
    for (int i = 1 ; i <= 20 ; i++) {
        a[i] = a[i-1]*i;
    }
    reverse(a, a+21);
    for (int i = 0 ; i <= 20 ; i++) {
        if( n >= a[i]) {
            n -= a[i];
        }
    }
    if (n == 0)
        printf("YES");
    else
        printf("NO");
















  return 0;
}
