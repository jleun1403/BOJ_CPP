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
int testcase, n;
long long a, b;

int main() {
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %lld %lld", &n, &a, &b);
        int ans = 0;
        if (a > b)
            swap(a, b);
        if (a % 2 == 1) {
            printf("%d\n", n);
            continue;
        }
        while(a % (1LL<<n) != 0) {
            n--;
            ans++;
        }
        printf("%d\n", ans);
    }
















  return 0;
}














  return 0;
}
