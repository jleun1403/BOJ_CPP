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
int d[2000];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ;i++ ) {
        scanf("%d", &a[i]);
    }
    d[0] = 0;
    for (int i = 1; i < n ; i++) {
        d[i] = inf;
    }
    for (int i = 0; i < n ; i++) {
        for (int j = 1 ; j < a[i] ; j++) {
            d[i+j] = min(d[i+j], d[i] +1);
        }
    }
    if (d[n-1] == inf)
        printf("-1");
    else
        printf("%d", d[n-1]);
















  return 0;
}
