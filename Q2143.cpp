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
int t, n, m;
int a[1000];
int b[1000];
int ad[1000][1000];
int bd[1000][1000];

int main() {
    vector<int> v1;
    vector<int> v2;
    scanf("%d", &t);
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
        ad[i][i] = a[i];
        v1.push_back(a[i]);
    }
    scanf("%d", &m);
    for (int i = 0 ; i < m ; i++){
        scanf("%d", &b[i]);
        bd[i][i] = b[i];
        v2.push_back(b[i]);
    }


    for (int k = 1 ; k < n ; k++) {
        for (int i = 0 ; i < n - k ; i++) {
            int sum = ad[i][i+k] = ad[i][i+k-1] + a[i+k];
            v1.push_back(sum);
        }
    }
    for (int k = 1 ; k < m ; k++) {
        for (int i = 0 ; i < m - k ; i++) {
            int sum = bd[i][i+k] = bd[i][i+k-1] + b[i+k];
            v2.push_back(sum);
        }
    }
    sort(v2.begin(), v2.end());
    long long ans = 0;
    for (int i = 0 ; i < v1.size(); i++) {
        int f = t - v1[i];
        auto hi = upper_bound(v2.begin(), v2.end(), f);
        auto lo = lower_bound(v2.begin(), v2.end(), f);
        ans += (hi - lo);
    }
    cout <<ans;
















  return 0;
}
