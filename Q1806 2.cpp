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
int a[100001];

int main() {
    scanf("%d %d", &n, &m);
    long long total = 0;
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
        total += (long long)a[i];
    }
    int ans = n;
    deque<int> q;
    int left = 1;
    int right = 1;
    int sum = 0;
    while(true) {
        int qs = q.size();
        if (sum < m) {
            sum += a[right];
            q.push_back(a[right++]);
        }
        else if (sum >= m) {
            if (qs < ans)
                ans = qs;
            q.pop_front();
            sum -= a[left];
            left++;
        }
        if (right > n+1)
            break;
    }
    if (ans == n) {
        if (total < m)
            printf("0");
        else
            printf("%d", n);
    }
    else
        printf("%d", ans);

















  return 0;
}
