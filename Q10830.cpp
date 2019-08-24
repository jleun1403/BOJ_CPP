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
vector<vector<int>> v;
int n;
vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> t(n, vector<int> (n));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            t[i][j] = 0;
            for (int k = 0 ; k < n ; k++) {
                t[i][j] += (a[i][k] * b[k][j]) % 1000;
            }
            t[i][j] %= 1000;
        }
    }
    return t;

}

vector<vector<int>> mul(vector<vector<int>> a, long long b) {
    if (b == 1) return a;
    if (b == 2) return mul(a, a);
    if (b % 2LL == 0LL){
        vector<vector<int>> temp = mul(a, b/2);
        return mul(temp, temp);
    }
    else {
        vector<vector<int>> temp = mul(a, b-1);
        return mul(temp, a);
    }
}


int main() {
    scanf("%d" ,&n);
    long long b;
    scanf("%lld", &b);
    v.resize(n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n; j++) {
            int k;
            scanf("%d", &k);
            k %= 1000;
            v[i].push_back(k);
        }
    }
    vector<vector<int>> ans = mul(v, b);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <n; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }







  return 0;
}
