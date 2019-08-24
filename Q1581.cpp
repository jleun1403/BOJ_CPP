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

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a + b == 0) {
        if (c == 0)
            printf("%d", d);
        else
            printf("%d", d+1);
        return 0;
    }
    if (a == 0) {
        if (c == 0)
            printf("%d", d + 1);
        else {
            printf("%d", b >= c+1? 2*c+1 + d: min(b, c+1)*2 + d);
        }
        return 0;
    }
    else if ( b== 0) {
        printf("%d", a);
        return 0;
    }
    else {
        printf("%d", b >= c+1? 2*c+1 + a + d: min(b, c+1)*2 +a + d);
        return 0;
    }

















  return 0;
}
