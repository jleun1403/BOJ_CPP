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
int n;
int a[100001];
int main() {
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 0 ; i < n ;i++){
        scanf("%d", &a[i]);
        sum += (long long)a[i];
    }
    long long ans = sum * sum;
    for (int i = 0 ; i < n ; i++) {
        ans -= (long long)(a[i] *a[i]);
    }
    printf("%lld", ans/2);

















  return 0;
}
