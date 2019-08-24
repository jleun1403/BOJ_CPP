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
int c[101];
vector<vector<int>> v;

bool BFS(int x, int y) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0 ; i < v[cur].size() ; i++) {
            int next = v[cur][i];
            if (c[next] == 0) {
                c[next] = 1;
                q.push(next);
            }
        }
    }
    bool flag;
    if (c[y] == 1)
        flag = true;
    else
        flag = false;
    memset(c, 0, sizeof(c));
    return flag;
}

int main() {
    scanf("%d", &n);
    v.resize(n+1);
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1; j <=n ; j++) {
            int k;
            scanf("%d", &k);
            if (k == 1)
                v[i].push_back(j);
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j<= n ; j++) {
            if (BFS(i, j))
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }









  return 0;
}
