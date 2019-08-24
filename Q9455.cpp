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
int testcase, m, n;
int a[100][100];

int below(int x, int y) {
    int ret = 0;
    for (int i = x+1; i < m ; i++) {
        if (a[i][y] == 1)
            ret++;
    }
    return ret++;
}

int main() {
    scanf("%d", &testcase);
    while(testcase--) {
        memset(a, 0, sizeof(a));
        scanf("%d %d", &m, &n);
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (a[i][j] == 1)
                    ans += (m - i- 1) - below(i, j);
            }
        }
        printf("%d\n", ans);
    }

















  return 0;
}
