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
long long fib[10001];

int main() {
    fib[0] = 0LL;
    fib[1] = 1LL;
    fib[2] = 1LL;
    for (int i = 3 ; i <= 10000; i++){
        fib[i] = fib[i-1] +fib[i-2];
    }
    int n;
    scanf("%d", &n);
    printf("%lld", fib[n]);








  return 0;
}
