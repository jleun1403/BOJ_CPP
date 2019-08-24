#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
long long v[10001];
int n, k;
using namespace std;
bool possible(long long mid) {
    int cnt = 0;
    for (long long x : v){
        cnt = cnt + x / mid;
    }
    return cnt >= n;
}

int main() {
    scanf("%d %d", &k, &n);
    long long maxe = 0;
    for (int i = 0 ; i < k ; i++){
        scanf("%lld", &v[i]);
        if (v[i] > maxe)
            maxe = v[i];
    }
    long long ans = 0;
    long long left = 1;
    while (maxe >= left) {
        long long mid = (maxe + left) / 2;
        if (possible(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else
            maxe = mid - 1;
    }
    cout << ans;








  return 0;
}
