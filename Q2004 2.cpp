#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);

    int n2 = 0;
    int n5 = 0;
    int m2 = 0;
    int m5 = 0;
    int nm2 = 0;
    int nm5 = 0;
    for (long long i = 2LL ; i <= n ; i = i*2) {
        n2 += n / i;
    }
    for (long long i = 5LL ; i <= n ; i = i*5) {
        n5 += n / i;
    }
    for (long long i = 2LL ; i <= m ; i = i*2) {
        m2 += m / i;
    }
    for (long long i = 5LL ; i <= m ; i = i*5) {
        m5 += m / i;
    }
    for (long long i = 2LL ; i <= n - m ; i = i*2) {
        nm2 += (n-m) / i;
    }
    for (long long i = 5LL ; i <= n - m ; i = i*5) {
        nm5 += (n-m) / i;
    }
    int f2 = n2 - m2 - nm2;
        if (f2 < 0)
            f2 = 0;
    int f5 = n5- m5 - nm5;
        if (f5 < 0)
            f5 = 0;
    printf("%d", min(f2,f5));

















  return 0;
}
