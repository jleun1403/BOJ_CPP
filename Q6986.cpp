#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>
#define inf 987654321

using namespace std;
int n, k;
int a[100000];

int main() {
    scanf("%d %d", &n, &k);
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        double dd;
        scanf("%lf", &dd);
        a[i] = dd*10;
    }
    sort(a, a+n);
    for (int i = k ; i < n - k ; i++) {
        sum += a[i];
    }
    printf("%d.%d\n", sum*100 / (n - 2*k)/1000, sum*100 / (n-2*k) % 1000 >= 5 ? sum*10 / (n-2*k) % 100 +1 :sum*10 / (n-2*k) % 100);
    sum += a[k]*k + a[n-k-1]*k;
    printf("%d.%d", sum*100 / n / 1000,sum*100 / (n) % 1000 >= 5 ? sum*10 / n % 100 +1 :sum*10 / n % 100);


















  return 0;
}
