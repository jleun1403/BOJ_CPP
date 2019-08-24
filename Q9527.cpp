#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

long long number(long long x) {
    long long ret = 0;
    for (int i = 0 ; i < 63 ; i++) {
        long long k = (1LL<<i);
        ret += x / k * (k/2);
        if (x % k >= k / 2) {
            ret += x % k - (k / 2);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    long long a, b;
    cin >> a >> b;
    cout << number(b+1) - number(a);















  return 0;
}
