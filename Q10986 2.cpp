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
long long a[100001];
long long s[100001];
int cnt[1000];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%lld", &a[i]);
        s[i] = s[i-1] + a[i];
        cnt[s[i] % m] += 1;
    }
    long long ans = 0;
    cnt[0]++;
    for (int i = 0 ; i < m ; i++) {
        int k = cnt[i];
        if (k == 0)
            continue;
        ans += k*(k-1)/2;
    }
    printf("%lld", ans);
















  return 0;
}
