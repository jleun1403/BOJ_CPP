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
long long a[1001][1001];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    a[1][1] = a[1][0] = 1LL;
    for (int i = 0 ; i <= 1000 ; i++) {
        for (int j = 0 ; j <= i; j++) {
            if (j == 0 || j == i)
                a[i][j] = 1;
            else
                a[i][j] = (a[i-1][j-1] + a[i-1][j]) % 10007LL;
        }
    }
    printf("%d", a[n][k]);







  return 0;
}
