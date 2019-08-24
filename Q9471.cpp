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
vector<vector<long long>> v;
int mod;
vector<vector<long long>> mul(vector<vector<long long>> &a, vector<vector<long long>> &b) {
    vector<vector<long long>> result(2, vector<long long> (2));
    for (int i = 0 ; i < 2 ; i++) {
        for (int j = 0 ; j < 2 ; j++) {
            result[i][j] = 0;
            for (int k = 0 ; k < 2; k++) {
                result[i][j] += (a[i][k] * b[k][j]) % mod;
            }
            result[i][j] %= mod;
        }
    }
    return result;
}
vector<vector<long long>> mul(vector<vector<long long>> &a, long long b) {
    if (b == 1) return a;
    if (b == 2) return mul(a, a);
    if (b % 2 == 0) {
        vector<vector<long long>> temp = mul(a, b/2);
        return mul(temp, temp);
    }
    else {
        vector<vector<long long>> temp = mul(a, b-1);
        return mul(temp, a);
    }
}

int main() {
    v.resize(2);
    v[0].push_back(1LL);
    v[0].push_back(1LL);
    v[1].push_back(1LL);
    v[1].push_back(0LL);
    int p;
    scanf("%d", &p);
    while(p--) {
        int w;
        scanf("%d %d", &w, &mod);
        long long ans = 3LL;
        vector<vector<long long>> a = mul(v, 2);
        while(true) {
            a = mul(a, v);
            if (a[0][1] == 0LL && mul(a, v)[0][1] == 1LL){
                break;
            }
            ans++;
        }
        cout << w << ' ' << ans << '\n';

    }








  return 0;
}
