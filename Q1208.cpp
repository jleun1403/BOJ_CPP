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
int a[20];
int b[20];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int as = n/2;
    int bs = n - as;
    vector<int> va;
    vector<int> vb;
    for (int i = 0 ; i < as ; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0 ; i < bs; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0 ; i < (1 << as) ; i++) {
        int sum = 0;
        for (int k = 0 ; k < as ; k++) {
            if (i & (1 << k)) {
                sum += a[k];
            }
        }
        va.push_back(sum);
    }
    for (int i = 0 ; i < (1 << bs) ; i++) {
        int sum = 0 ;
        for (int k = 0 ; k < bs ; k++) {
            if (i & (1 << k))
                sum += b[k];
        }
        vb.push_back(sum);
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    long long ans = 0;
    for (int i = 0 ; i < va.size() ; i++) {
        int f = m - va[i];
        auto hi = upper_bound(vb.begin(), vb.end(), f);
        auto lo = lower_bound(vb.begin(), vb.end(), f);
        ans += (hi - lo);
    }
    if (m == 0)
        ans--;
    printf("%lld", ans);
















  return 0;
}
