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
long long fib[41];


int main() {
    fib[0] = 1;
    fib[1] = 1;
    fib[2] = 2;
    fib[3] = 3;
    for (int i = 4 ; i < 41 ; i++)
        fib[i] = fib[i-1] + fib[i-2];
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a;
    a.push_back(0);
    for (int i = 0 ; i < m ; i++) {
        int k;
        scanf("%d", &k);
        a.push_back(k);
    }
    a.push_back(n+1);
    if (m == 0)
        printf("%lld", fib[n]);
    else {
        long long ans = 1LL;
        for (int i = 1 ; i <= m+1 ; i++) {
            int space = a[i] - a[i-1] -1;
            ans *= fib[space];
        }
        printf("%lld", ans);
    }
















  return 0;
}
