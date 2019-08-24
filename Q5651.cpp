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

struct Edge{
    int to;
    int capacity;
    int flow;
    Edge *rev;
    Edge(int t, int c) : to(t), capacity(c), flow(0) {};

    int spare() {
        return capacity - flow;
    }
    void addflow(int f) {
        flow += f;
        rev->flow -= f;
    }
};
int testcase, n, m;
vector<vector<Edge*>> v;
int pre[301];
Edge* path[301];
bool visited[301];

void DFS(int x) {
    visited[x] = true;
    for (int i = 0 ; i < v[x].size() ; i++) {
        auto next = v[x][i];
        if (visited[next->to] == false && next->spare() > 0) {
            DFS(next->to);
        }
    }
}


int main() {
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d", &n, &m);
        v.resize(n+1);
        for (int i = 0 ; i < m ; i++) {
            int f, t, b;
            scanf("%d %d %d", &f, &t, &b);
            Edge *e1 = new Edge(t, b);
            Edge *e2 = new Edge(f, 0);
            e1->rev = e2;
            e2->rev = e1;
            v[f].push_back(e1);
            v[t].push_back(e2);
        }
        int total = 0;
        while(true) {
            memset(pre, -1, sizeof(pre));
            memset(path, 0, sizeof(path));
            queue<int> q;
            q.push(1);
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int i = 0 ; i < v[cur].size() ; i++) {
                    Edge* next = v[cur][i];
                    if (pre[next->to] == -1 && next->spare() > 0) {
                        pre[next->to] = cur;
                        path[next->to] = next;
                        q.push(next->to);
                    }
                }
            }
            if (pre[n] == -1)
                break;
            int f = inf;
            for (int i = n ; i != 1; i = pre[i]) {
                f = min(f, path[i]->spare());
            }
            for (int i = n ; i != 1; i = pre[i]) {
                path[i]->addflow(f);
            }
            total += f;
        }

        int ans = 0;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 0 ; j < v[i].size() ; j++) {
                if (v[i][j]->spare() == 0 && v[i][j]->capacity > 0) {
                    ans++;
                    memset(visited, false, sizeof(visited));
                    DFS(i);
                    if (visited[v[i][j]->to]) {
                        ans--;
                    }
                }
            }
        }
        printf("%d\n", ans);
        v.clear();
    }
















  return 0;
}
