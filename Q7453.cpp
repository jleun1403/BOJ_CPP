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
int a[4000];
int b[4000];
int c[4000];
int d[4000];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n; i ++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    vector<int> first;
    vector<int> second;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            first.push_back(a[i] + b[j]);
        }
    }
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < n ; j++) {
            second.push_back(c[i] + d[j]);
        }
    }
    long long ans = 0;
    sort(second.begin(), second.end());
    for (int i = 0 ; i < first.size() ; i++) {
        int t = first[i] * -1;
        auto hi = upper_bound(second.begin(), second.end(), t);
        auto lo = lower_bound(second.begin(), second.end(), t);
        ans += (hi - lo);
    }
    cout << ans;


















  return 0;
}
