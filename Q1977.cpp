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
    int m, n;
    int ans = 0;
    int small;
    scanf("%d %d", &m, &n);
    for (int i = n ; i>= m ; i--) {
        if ((int)sqrt(i) == sqrt(i)) {
            ans += i;
            small = i;
        }
    }
    if (ans == 0) {
        printf("0");
        return 0;
    }
    else {
        printf("%d\n%d", ans, small);
    }
















  return 0;
}
