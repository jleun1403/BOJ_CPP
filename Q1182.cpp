#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;

int main() {
    vector<int> v;
    int n, m;
    int ans = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < n ; i++) {
        int k;
        scanf("%d", &k);
        v.push_back(k);
    }
    for (int i = 1 ; i < (1 << n) ; i++) {
        int sum = 0;
        for (int k = 0 ; k < n ; k++) {
            if (((1 << k ) & i)){
                sum = sum + v[k];
            }
        }
        if (m == sum)
            ans++;
    }
    printf("%d", ans);






  return 0;
}
