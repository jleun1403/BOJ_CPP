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
int n, m;
int a[10001];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i++) {
        scanf("%d", &a[i]);
    }
    deque<int> q;
    int i = 1, j= 1;
    int ans = 0;
    while(true) {
        int qs = q.size();
        int sum = 0;
        for (int k = 0 ; k < qs ; k++) {
            sum += q[k];
        }
        if (sum < m)
            q.push_back(a[j++]);
        else if (sum > m) {
            q.pop_front();
            i++;
        }
        else {
            ans += 1;
            q.push_back(a[j++]);
        }
        if (j > n + 1)
            break;
        if (i == j) {
            q.push_back(a[j++]);
        }
    }
    cout << ans;

















  return 0;
}
