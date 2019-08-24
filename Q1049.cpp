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
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    int ans = 1000000000;
    int cheapset = 10000;
    int cheapline = 10000;
    for (int i = 0 ; i < m ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if ( a < cheapset)
            cheapset = a;
        if (b < cheapline)
            cheapline = b;
    }
    ans = min(cheapset*(n/6 + 1), min(cheapset*(n/6) + cheapline*(n%6) , cheapline*n));
    printf("%d", ans);














  return 0;
}
