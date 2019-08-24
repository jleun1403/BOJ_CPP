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

int dice(int x, int y, int z) {
    if (x == y && y == z)
        return 10000 + 1000*x;
    else if (x == y)
        return 1000 + 100*x;
    else if ( y == z)
        return 1000 + 100*y;
    else if (x == z)
        return 1000 +100*z;
    else
        return max(x, max(y, z)) * 100;

}

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        ans = max(ans, dice(x, y, z));
    }
    printf("%d", ans);















  return 0;
}
