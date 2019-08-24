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

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int base = n / k;
    int bigger = n - base*k;
    long long ans = 1;
    for (int i = 0 ; i < k-bigger ; i++) {
        ans *= (long long)base;
    }
    for (int i = 0 ; i < bigger ; i++) {
        ans *= (long long)(base+1);
    }
    printf("%lld", ans);
















  return 0;
}
