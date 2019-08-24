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

int good[1001];
int a[1001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
    }
    if (n == 1) {
        printf("0");
        return 0;
    }
    if (n == 2) {
        printf("%d", abs(a[2] - a[1]));
        return 0;
    }
    good[1] = 0;
    good[2] = abs(a[2] - a[1]);
    for (int i = 3 ; i <= n ; i++) {
        good[i] = good[i-1];
        int maximum = a[i];
        int minimum = a[i];
        for (int j = i-1; j > 0 ; j--) {
            if (a[j] > maximum) {
                maximum = a[j];
            }
            if (a[j] < minimum) {
                minimum = a[j];
            }
            good[i] = max(good[i], good[j-1] + maximum - minimum);
        }
    }
    printf("%d", good[n]);















  return 0;
}
