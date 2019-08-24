#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int f[2000001];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int havetoadd;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    int p = 0, k = 1;
    f[1] = 1;
    for (int i = 2 ; i <= 1000000; i++) {
        havetoadd = k;
        f[i] = f[i-1] + havetoadd;
        v.push_back(f[i]);
        p++;
        if (p == v[k+1] - v[k]) {
            p = 0;
            k++;
        }
    }
    for (int i = 1 ; i < 1000000 ; i++) {
        if (f[i+1] > n && f[i] <= n) {
            printf("%d", i);
            return 0;
        }
    }














  return 0;
}
