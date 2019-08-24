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
long long GCD(long long a, long long b) {
    long long n = b % a;
    while (n != 0) {
        b = a;
        a = n;
        n = b % a;
    }
    return a;
}

int main() {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        if (a > b)
            swap(a, b);
        long long = GCD(a, b);
        for (long long i = 0 ; i <gcd ; i++)
            printf("1");
















  return 0;
}
