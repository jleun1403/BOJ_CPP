#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
int n, c;
vector<int> v;
bool possible(int mid) {
    int cnt = 1;
    int house = v[0];
    for (int i = 1; i < n ; i++) {
        if (v[i] - house >= mid) {
            cnt++;
            house = v[i];
        }
    }
    return cnt >= c;
}

int main() {
    scanf("%d %d", &n, &c);
    v.resize(n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int left = 1;
    int right = v[n-1] - v[0];
    int ans = 1;
    while (right >= left) {
        int mid = (left + right) / 2;
        if (possible(mid)){
            left = mid +1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    cout << ans;






  return 0;
}
