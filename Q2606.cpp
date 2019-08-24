#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;
int parent[101];

int ffind(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = ffind(parent[x]);
}

void uunion(int x, int y) {
    x = ffind(x);
    y = ffind(y);
    if (x == 1)
        parent[y] = 1;
    else if (y == 1)
        parent[x] = 1;
    else
        parent[y] = x;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++)
        parent[i] = i;
    for (int i = 0 ; i < m ; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        uunion(x, y);

    }
    int cnt = 0;
    for (int i = 1; i <= n ; i++) {
        ffind(i);
        if (parent[i] == 1)
            cnt++;
    }
    printf("%d", cnt - 1);







  return 0;
}
