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
#define inf 987654321

using namespace std;
int a[200];
int d[200];
int n;
int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ;i++) {
        scanf("%d", &a[i]);
    }
    d[0] = 1;
    for (int i = 1; i < n ; i++) {
        d[i] = 1;
        for (int j = 0; j < i ; j++) {
            if (a[j] < a[i]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0 ; i <n ; i++) {
        ans = max(ans, d[i]);
    }
    printf("%d", n - ans);
















  return 0;
}
