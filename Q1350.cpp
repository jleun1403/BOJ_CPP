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
    int n, f, c;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &f);
        v.push_back(f);
    }
    long long ans = 0;
    scanf("%d", &c);
    for (int i = 0 ; i < n ; i++){
        int need = v[i] / c;
        if (v[i] % c != 0)
            need++;
        ans += (long long)need * c;
    }
    printf("%lld", ans);

















  return 0;
}
