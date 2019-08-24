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
int a[1000000];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i <n ; i++){
        scanf("%d", &a[i]);
    }
    int b, c;
    long long ans = 0;
    scanf("%d %d", &b, &c);
    for (int i = 0 ; i < n ;i++) {
        if (a[i] <= b)
            ans++;
        else
            ans += (long long)(a[i] - b - 1)/ c + 2LL;
    }
    printf("%lld", ans);

















  return 0;
}
