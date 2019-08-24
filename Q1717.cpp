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
int parent[1000001];

int FIND(int x){
    if (x == parent[x])
        return x;
    else {
        int y = FIND(parent[x]);
        parent[x] = y;
        return y;
    }
}

void UNION(int x, int y) {
    int p = FIND(x);
    int q = FIND(y);
    if (p != q)
        parent[q] = p;
}


int main() {
    int n, m, what, x, y;
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i <= n ; i++)
        parent[i] = i;
    for (int i = 0 ; i < m ; i++){
        scanf("%d %d %d", &what, &x, &y);
        if (what == 0) {
            UNION(x, y);
        }
        else {
            if (FIND(x) == FIND(y))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }

    }







  return 0;
}
