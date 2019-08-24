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
int ans;
int n;
int q[15][15] = {0};

bool col(int x, int y) {
    for (int i = 0 ; i < x ; i++) {
        if (q[i][y] == 1)
            return false;
    }
    return true;
}

bool dig1(int x, int y) {
    x = x - 1;
    y = y - 1;
    while (0 <= x && 0 <= y) {
        if (q[x][y] == 1)
            return false;
        x = x - 1;
        y = y - 1;
    }
    return true;
}
bool dig2(int x, int y) {
    x = x - 1;
    y = y + 1;
    while (0 <= x && y < n) {
        if (q[x][y] == 1)
            return false;
        x = x - 1;
        y = y + 1;
    }
    return true;
}
void calc(int row) {
    if (row == n)
        ans += 1;
    for (int i = 0 ; i < n ; i++) {
        q[row][i] = 1;
        if (col(row, i) && dig1(row, i) && dig2(row, i)) {
            calc(row +1);
        }
        q[row][i] = 0;
    }
}

int main() {
    scanf("%d", &n);
    ans = 0;
    calc(0);
    cout << ans;







  return 0;
}
