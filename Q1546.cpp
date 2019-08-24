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
int n;
double a[1001];

int main() {
    scanf("%d", &n);
    double high = 0;
    for (int i = 0 ; i < n; i++) {
        scanf("%lf", &a[i]);
        if (a[i] > high)
            high = a[i];
    }
    for (int i = 0 ; i < n ;i++) {
        a[i] = a[i]/high * 100;
    }
    double sum = 0.0;
    for (int i = 0 ; i < n ;i++) {
        sum += a[i];
    }
    printf("%.3lf", sum / n);















  return 0;
}
