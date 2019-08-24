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
long long i, j;
int main() {
    long long a, b;
    scanf("%lld %lld", &i, &j);
    if (i >= 0 && j >= 0) {
        if (i > j)
            swap(i, j);
        a = i*(i-1) / 2LL;
        b = j*(j+1) / 2LL;
        printf("%lld", b-a);
    }
    else if (i < 0 && j >= 0) {
        i = -i;
        a = i*(i+1)/2LL;
        b = j*(j+1)/2LL;
        a = -a;
        printf("%lld", a+b);
    }
    else if (i >= 0 && j < 0) {
        j = -j;
        a = i*(i+1)/2LL;
        b = j*(j+1)/2LL;
        b = -b;
        printf("%lld", a+b);
    }
    else {
        j = -j;
        i = -i;
        if (i > j)
            swap(i, j);
        a = i*(i-1) / 2LL;
        b = j*(j+1) / 2LL;
        printf("%lld", (-1)*(b-a));
    }
















  return 0;
}
