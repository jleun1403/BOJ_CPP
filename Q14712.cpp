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
int d[25][25];
vector<vector<int>> c;
int ans;

bool square(int x, int y) {
    if (x == 0 || y == 0)
        return true;
    if (d[x-1][y-1] == 1 && d[x-1][y] == 1 && d[x][y-1] == 1)
        return false;
    return true;
}

void go(int x, int y) {
    if (x == n && y == 0) {
        ans++;
        return; }
    if (square(x, y)){
        d[x][y] = 1;
        if (y == m - 1) {
            go(x+1, 0);
        }
        else
            go(x, y+1);
        d[x][y] = 0;
    }
    if (y == m - 1) {
        go(x+1, 0);
    }
    else
        go(x, y+1);


}


int main() {
    scanf("%d %d", &n, &m);
    go(0, 0);
    cout << ans;








  return 0;
}
