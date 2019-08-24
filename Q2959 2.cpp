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
#define inf 987654321

using namespace std;

long long gcd(long long x, long long y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    long long g = gcd(a, b);
    printf("%lld", a*(b / g));















  return 0;
}
