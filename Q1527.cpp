#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>
#define inf 987654321

using namespace std;

int go(long long low, long long high, long long x) {
    if (x > high)
        return 0;
    int ret = 0;
    if (x >= low)
        ret = 1;
    return go(low, high, 10*x+4) + go(low, high, 10*x + 7) + ret;
}

int main() {
    long long l, h;
    scanf("%lld %lld", &l, &h);
    printf("%d", go(l, h, 0LL));
















  return 0;
}
