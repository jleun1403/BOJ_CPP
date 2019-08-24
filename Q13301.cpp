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
long long fib[81];
int main() {
    fib[0] = 1LL;
    fib[1] = 1LL;
    fib[2] = 2LL;
    for (int i = 3 ; i <= 80 ; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    int n;
    scanf("%d", &n);
    printf("%lld", (fib[n-1] + fib[n]) * 2);

















  return 0;
}
