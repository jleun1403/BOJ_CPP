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
int s, n, m;
    int asum = 0;
    int bsum = 0;
    int a[1000];
    int b[1000];
    int ad[1000][1000];
    int bd[1000][1000];
int main() {


    scanf("%d %d %d", &s, &n, &m);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
        asum += a[i];
        ad[i][i] = a[i];
    }
    for (int i = 0 ; i < m ; i++) {
        scanf("%d", &b[i]);
        bsum += b[i];
        bd[i][i] = b[i];
    }

    vector<int> va;
    vector<int> vb;
    va.push_back(0);
    vb.push_back(0);
    for (int i = 0 ; i < n ; i++)
        va.push_back(ad[i][i]);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 1 ; j < n-1 ; j++) {
            int sum = ad[i][(i+j) % n] = ad[i][(i+j-1) % n] + a[(i+j) % n];
            va.push_back(sum);
        }
    }
    for (int i = 0 ; i < m ; i++)
        vb.push_back(bd[i][i]);
    for (int i = 0 ; i < m ; i++) {
        for (int j = 1 ; j < m-1 ; j++) {
            int sum = bd[i][(i+j) % m] = bd[i][(i+j-1) % m] + b[(i+j) % m];
            vb.push_back(sum);
        }
    }
    va.push_back(asum);
    vb.push_back(bsum);
    sort(vb.begin(), vb.end());
    long long ans = 0;
    for (int i = 0 ; i < va.size() ; i++) {
        int t = s - va[i];
        auto hi = upper_bound(vb.begin(), vb.end(), t);
        auto lo = lower_bound(vb.begin(), vb.end(), t);
        ans += (hi - lo);
    }
    cout << ans;
















  return 0;
}
