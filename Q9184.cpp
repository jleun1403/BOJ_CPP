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

int d[21][21][21];

int go(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return go(20, 20, 20);
    }
    if (d[a][b][c] != -1) {
        return d[a][b][c];
    }
    if (a < b && b < c)
        return d[a][b][c] = go(a, b, c-1) + go(a, b-1, c-1) - go(a, b-1, c);
    else
        return d[a][b][c] = go(a-1, b, c) + go(a-1, b-1, c) + go(a-1, b, c-1) - go(a-1, b-1, c-1);
}


int main() {
    memset(d, -1, sizeof(d));
    while(true) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
            break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, go(a, b, c));
    }
















  return 0;
}
