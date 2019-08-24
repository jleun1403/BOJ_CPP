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
int a[10001];
int main() {
    int n;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for (int i = 0 ; i < n ; i++) {
        int k;
        scanf("%d", &k);
        a[k] += 1;
    }
    for (int i = 1 ; i <= 10000 ; i++) {
        if (a[i] >= 1) {
            for (int j = 0 ; j < a[i] ; j++)
                printf("%d\n", i);
        }
    }


















  return 0;
}
