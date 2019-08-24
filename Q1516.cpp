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
int n;
int in[501];
vector<vector<int>> v;
int d[501];
int a[501];

void topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            d[i] = a[i];
        }
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0 ; i < v[x].size() ; i++) {
            if (d[v[x][i]] < d[x] + a[v[x][i]])
                d[v[x][i]] = d[x] +a[v[x][i]];
            in[v[x][i]] -= 1;
            if (in[v[x][i]] == 0)
                q.push(v[x][i]);
        }

    }
}

int main() {
    scanf("%d", &n);
    v.resize(n+1);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
        int k;
        scanf("%d", &k);
        while( k != -1) {
            in[i]++;
            v[k].push_back(i);
            scanf("%d", &k);
        }
    }
    topsort();
    for (int i = 1 ; i <= n ; i++) {
        printf("%d\n", d[i]);
    }








  return 0;
}
