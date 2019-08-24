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

const int source = 0;

struct Edge {
    int to;
    int capacity;
    int flow;
    Edge * rev;
    Edge(int t, int c) : to(t), capacity(c),flow(0) {}
    int spare() {
        return capacity - flow;
    }
    void addflow(int f) {
        flow += f;
        rev->flow -= f;
    }
};


int pre[101050];
vector<vector<Edge*>> v;
Edge* path[101050];

int main() {
    int testcase, n, start, people, s;
    int m, r;
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d %d %d", &n, &start, &people, &s);
        v.resize(n*(s+1)+ 2);

        for (int i = 1 ; i <= n ; i++) {
            for (int time = 0 ; time < s; time++) {
                int curnode = (i-1)*(s+1) +time +1;
                int nextnode = (i-1) *(s+1) +time + 2;
                Edge* e1 = new Edge(nextnode, inf);
                Edge* e2 = new Edge(curnode, 0);
                e1->rev = e2;
                e2->rev = e1;
                v[curnode].emplace_back(e1);
                v[nextnode].emplace_back(e2);
            }
        }
        int startnode = (start-1)*(s+1) +1;
        Edge * e3 = new Edge(startnode, people);
        Edge * e4 = new Edge(source , 0);
        e3->rev = e4;
        e4->rev = e3;
        v[source].emplace_back(e3);
        v[startnode].emplace_back(e4);

        scanf("%d", &m);
        int drain = n*(s+1)+ 1;
        for (int i = 0 ; i < m ; i++) {
            int hospital;
            scanf("%d", &hospital);
            int hnode = (hospital * (s+1));
            Edge* e5 = new Edge(drain, inf);
            Edge* e6 = new Edge(hnode, 0);
            e5->rev = e6;
            e6->rev = e5;
            v[hnode].emplace_back(e5);
            v[drain].emplace_back(e6);
        }
        scanf("%d", &r);
        for (int road = 0 ; road < r; road++) {
            int a, b, p, t;
            scanf("%d %d %d %d", &a ,&b, &p, &t);
            int tt = 1;
            if (a == start)
                tt = 0;
            while (tt + t <= s) {
                int snode = (a-1) * (s+1) + tt +1;
                int arrivenode = (b-1) *(s+1) + tt + 1 + t;
                Edge * e7 = new Edge(arrivenode, p);
                Edge * e8 = new Edge(snode, 0);
                e7-> rev = e8;
                e8-> rev = e7;
                v[snode].emplace_back(e7);
                v[arrivenode].emplace_back(e8);
                tt++;
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
                        pre[next->to] = cur;
                        path[next->to] = next;
                        q.push(next->to);
                        if (next->to == drain)
                            break;
                    }
                }
            }
            if (pre[drain] == -1)
                break;
            int f = inf;
            for (int i = drain; i != source ; i = pre[i])
                f = min(f, path[i]->spare());
            for (int i = drain; i != source ; i = pre[i])
                path[i]->addflow(f);
            total +=f;
        }
        printf("%d\n", total);

        v.clear();
    }


















  return 0;
}
