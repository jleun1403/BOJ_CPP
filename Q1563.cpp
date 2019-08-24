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
#define mod 1000000

using namespace std;
int d[1001][2][3];
int n;

int go (int day, int late, int absent) {
    if (day == n && late < 2 && absent < 3)
        return 1;
    else if (late >= 2 || absent >= 3)
        return 0;
    if (d[day][late][absent] != -1)
        return d[day][late][absent];
    // attend
    int ans = go(day+1, late, 0) % mod;
    // late
    ans += go(day+1, late+1, 0) % mod;
    // absent
    ans += go(day+1, late, absent+1) % mod;
    return d[day][late][absent] = ans % mod;

}

int main() {
    scanf("%d", &n);
    memset(d, -1, sizeof(d));
    int ans = go(0, 0, 0) % mod;
    printf("%d", ans);
















  return 0;
}
