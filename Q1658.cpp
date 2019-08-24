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
int m, n;
struct Edge {
    int to;
    int capacity;
    int flow;
    Edge* rev;
    Edge(int t, int c) : to(t), capacity(c), flow(0) {}

    int spare() {
        return capacity - flow;
    }
    void addflow(int f) {
        flow += f;
        rev->flow -= f;
    }
};

int pre[1000000];
Edge* path[1000000];

vector<vector<Edge*>> v(1000000);

int main() {
    scanf("%d %d", &m, &n);
    const int source = 0;
    const int drain = (n+1)*m + n + 1;
    for (int i = 1 ; i <= m ; i++) {
        int cap;
        scanf("%d", &cap);
        Edge* e1 = new Edge(i, cap);
        Edge* e2 = new Edge(source, 0);
        e1->rev = e2;
        e2->rev = e1;
        v[source].push_back(e1);
        v[i].push_back(e2);
    }
    for (int i = 1 ; i <= n ; i++) {
        int keys;
        vector<int> key;
        scanf("%d", &keys);
        for (int j = 1 ; j <= keys ; j++) {
            int keynum;
            scanf("%d", &keynum);
            key.push_back(keynum);
        }
        for (int j : key) {
            for (int k : key) {
                if (j == k) continue;
                Edge* e1 = new Edge(i*m + k, inf);
                Edge* e2 = new Edge((i-1)*m + j, 0);
                e1->rev = e2;
                e2->rev = e1;
                v[(i-1)*m + j].push_back(e1);
                v[i*m + k]. push_back(e2);
            }
            Edge* e3 = new Edge((n+1)*m + i, inf);
            Edge* e4 = new Edge(i*m+j, 0);
            e3->rev = e4;
            e4->rev = e3;
            v[i*m+j].push_back(e3);
            v[(n+1)*m + i].push_back(e4);
        }
        int dc;
        scanf("%d", &dc);
        Edge* e5 = new Edge(drain, dc);
        Edge* e6 = new Edge((n+1)*m + i, 0);
        e5->rev = e6;
        e6->rev = e5;
        v[drain].push_back(e6);
        v[(n+1)*m + i].push_back(e5);
        key.clear();
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            Edge * e1 = new Edge(i*m + j, inf);
            Edge * e2 = new Edge((i-1)*m + j, 0);
            e1->rev = e2;
            e2->rev = e1;
            v[i*m + j].push_back(e2);
            v[(i-1)*m +j].push_back(e1);
        }
    }

    int total = 0;
    while(true) {
        memset(pre, -1, sizeof(pre));
        memset(path, 0, sizeof(path));
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0 ; i < v[cur].size() ; i++) {
                auto next = v[cur][i];
                if (pre[next->to] == -1 && next->spare() > 0) {
                    pre[next -> to] = cur;
                    q.push(next->to);
                    path[next->to] = next;
                    if (next->to == drain)
                        break;
                }
            }
        }
        if (pre[drain] == -1)
            break;
        int f = inf;
        for (int i = drain; i != source ; i = pre[i]) {
            f = min(f, path[i]->spare());
        }
        for (int i = drain ; i != source ; i = pre[i]) {
            path[i]->addflow(f);
        }
        total += f;
    }
    printf("%d\n", total);
















  return 0;
}
