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

int main() {
    int a, b, c, x1, x2, y1, y2;
    scanf("%d %d %d %d %d %d %d", &a, &b, &c, &x1, &x2, &y1, &y2);
    double x, y;
    long long ans = 0;
    if (a == 0 && b == 0) {
        if (c == 0)
            ans = (x2 - x1 +1LL) * (y2 - y1 + 1LL);
        else
            ans = 0;
    }
    else if (a == 0 && b != 0) {
        y = (c *-1.0) *1.0 / (double)b;
        if (y == (int)y && y1 <= y && y <= y2)
            ans = (x2 - x1 + 1LL);
    }
    else if (a != 0 && b == 0) {
        x = (c *-1.0)*1.0 / (double)a;
        if (x == (int)x && x1 <= x && x <= x2)
            ans = (y2 - y1 +1LL);
    }
    else {
        for (int i = y1 ; i <= y2 ; i++) {
            x = (b*(-1.0)*i + c*-1.0) / (double)a;
            if (x == (int)x && x1 <= x && x<= x2)
                ans++;
        }
    }
    printf("%lld", ans);








  return 0;
}
