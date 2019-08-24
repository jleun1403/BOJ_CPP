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
long long fib[1500001];

int main() {
    fib[0] = 0LL;
    fib[1] = 1LL;
    fib[2] = 1LL;
    for (int i = 3 ; i <= 1500000 ; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % 1000000LL;
    }
    long long n;
    scanf("%lld", &n);
    n = n % 1500000LL;
    printf("%d", fib[n]);









  return 0;
}
