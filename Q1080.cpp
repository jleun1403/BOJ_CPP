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
vector<vector<int>> a;
vector<vector<int>> b;

void change(int x, int y) {
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3; j++) {
            if (a[x+i][y+j] == 1)
                a[x+i][y+j] = 0;
            else
                a[x+i][y+j] = 1;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    a.resize(n);
    b.resize(n);
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < m ; j++) {
            int k;
            scanf("%1d", &k);
            a[i].push_back(k);
        }
    }
    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < m ; j++) {
            int k;
            scanf("%1d", &k);
            b[i].push_back(k);
        }
    }
    int ans = 0;
    for (int j = 0 ; j <= m - 3 ; j++) {
        for (int i = 0 ; i <= n - 3 ; i++) {
            if (a[i][j] != b[i][j]) {
                change(i, j);
                ans++;
            }
        }
    }
    if (a != b) {
        printf("-1");
    }
    else
        printf("%d", ans);
















  return 0;
}
