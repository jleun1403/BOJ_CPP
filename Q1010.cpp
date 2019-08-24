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
int n, m;
long long d[101][101];

int main() {

    d[1][0] = d[1][1] = 1LL;
    for (int i = 2; i <= 100 ; i++) {
        for (int j = 0 ; j <= i ; j++) {
            if (j == 0 || j == i)
                d[i][j] = 1LL;
            else{
                d[i][j] = d[i-1][j] + d[i-1][j-1];
            }
        }
    }

    scanf("%d %d", &n, &m);
    printf("%lld\n", d[n][m]);














  return 0;
}
