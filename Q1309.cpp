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
int d[1000001][3];
int main() {
    scanf("%d", &n);
    d[1][0] = 1;
    d[1][1] = 1;
    d[1][2] = 1;
    for (int i = 2 ; i <= n ; i++) {
        d[i][0] = (d[i-1][0] + d[i-1][1] + d[i-1][2]) % 9901;
        d[i][1] = (d[i-1][0] + d[i-1][2]) % 9901;
        d[i][2] = (d[i-1][0] + d[i-1][1]) % 9901;
    }
    printf("%d" ,(d[n][0] + d[n][1] + d[n][2]) % 9901);

















  return 0;
}
