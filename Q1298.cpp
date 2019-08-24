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
#define inf 987654321

using namespace std;
int n, m;
int f[202][202];
int c[202][202];
int pre[202];
vector<vector<int>> v(202);
// source = 0 drain = 201;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < m ; i++) {
        int student, laptop;
        scanf("%d %d", &student, &laptop);
        laptop += 100;
        v[student].push_back(laptop);
        v[laptop].push_back(student);
        c[student][laptop] = 1;
    }
    for (int i = 1; i <= n ; i++) {
        v[0].push_back(i);
        v[i].push_back(0);
        v[100+i].push_back(201);
        v[201].push_back(100+i);
        c[0][i] = 1;
        c[100+i][201] = 1;
    }
    int ans = 0;
    while(true) {
        memset(pre, -1, sizeof(pre));
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0 ; i < v[cur].size() ; i++) {
                int next = v[cur][i];
                if (c[cur][next] > f[cur][next] && pre[next] == -1) {
                    pre[next] = cur;
                    q.push(next);
                }
            }
        }
        if (pre[201] == -1)
            break;
        for (int i = 201 ; i != 0 ; i = pre[i]) {
            f[pre[i]][i] += 1;
            f[i][pre[i]] -= 1;
        }
        ans++;
    }
    printf("%d", ans);

















  return 0;
}
