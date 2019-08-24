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
int d[1001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1 ; i <= n ;i++) {
        scanf("%d", &a[i]);
    }
    d[1] = 1;
    int rans = 0;
    for (int i = 2 ; i <= n ; i++) {
        int ans = 0;
        for (int j = 1 ; j < i ; j++) {
            if (a[j] < a[i] && d[j] > ans)
                ans = d[j];
        }
        d[i] = ans + 1;
        if (d[i] > rans)
            rans = d[i];
    }
    printf("%d", rans);
















  return 0;
}
