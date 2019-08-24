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
int d[5001];
int h[5001];

int go(int x) {
    int ans = 0;
    if (d[x] != 0)
        return d[x];
    else {
        for (int i = 0 ; i < a[x].size() ; i++) {
            int nextv = a[x][i];
            if (h[nextv] > h[x]) {
                int nextans = go(nextv);
                if (nextans > ans)
                    ans = nextans;
            }
        }
        return d[x] = ans + 1;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    a.resize(n+1);
    for (int i = 1; i <= n ;i++) {
        scanf("%d", &h[i]);
    }
    for (int i = 0 ; i < m ; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        a[from].push_back(to);
        a[to].push_back(from);
    }
    for (int i = 1 ; i <= n ; i++) {
        if (d[i] == 0)
            go(i);
    }
    for (int i = 1; i <= n ; i++) {
        printf("%d\n", d[i]);
    }
















  return 0;
}
