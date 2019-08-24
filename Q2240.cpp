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
int a[1001];
int d[1001][31];
int t, w;
int go(int sec, int turn) {
    if (sec == t+1 && turn <= w) return 0;
    if (turn > w) return 0;
    if (d[sec][turn] != -1)
        return d[sec][turn];
    int pos = turn % 2  +1;
    if (a[sec] == pos) d[sec][turn] = 1 + max(go(sec + 1, turn +1), go(sec + 1 , turn));
    else
        d[sec][turn] = max(go(sec + 1, turn +1), go(sec + 1 , turn));
    return d[sec][turn];
}

int main() {
    scanf("%d %d", &t, &w);
    for (int i= 1 ; i <= t ; i++)
        scanf("%d", &a[i]);
    memset(d, -1, sizeof(d));
    printf("%d", max(go(1, 0), go(1, 1)));








  return 0;
}
