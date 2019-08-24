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
int a[1001];

int main() {
    memset(a, 0, sizeof(a));
    int n, k;
    int cnt = 0;
    scanf("%d %d", &n, &k);
    for (int i = 2;  i<=n ; i++) {
        if (a[i] == 0) {
            cnt++;
            a[i] = cnt;
            for (int j = i*i ; j <= n ; j += i) {
                if (a[j] == 0) {
                    a[j] = ++cnt;
                }
            }
        }
    }
    for (int i = 2 ; i <= n ;i++) {
        if (a[i] == k)
            printf("%d ", i);
    }
















  return 0;
}
