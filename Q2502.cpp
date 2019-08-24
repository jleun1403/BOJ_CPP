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
long long fib[31];

pair<int, int> solve(long long a, long long b, int k) {
    for (int i = 1 ; i < k ; i++) {
        double temp = ((k - (a * i)) / (double)b);
        if ((long long)temp == temp && temp >= i) {
            return make_pair(i, temp);
        }
    }
}

int main() {
    fib[1] = 1LL;
    fib[2] = 1LL;
    fib[3] = 2LL;
    for (int i = 4 ; i <= 31; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    int d, k;
    scanf("%d %d", &d, &k);
    long long a = fib[d-2];
    long long b = fib[d-1];
    auto p = solve(a, b, k);
    printf("%d\n%d", p.first, p.second);


















  return 0;
}
