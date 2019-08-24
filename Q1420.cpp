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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
int a[100][100];

//int c[10000][10000];
//int f[10000][10000];
int source, sink;
int pre[20000];

struct Edge {
    int to;
    int capacity;
    int flow;
    Edge * rev;
    Edge(int t, int c) : to(t), capacity(c), rev(nullptr), flow(0) {};

    void addflow() {
        flow += 1;
        rev->flow -=1;
    }
    int able() {
        return capacity - flow;
    }

};
vector<vector<Edge*>> v(20000);
Edge* path[20000];

int main() {
    scanf("%d %d", &n, &m);
    int si, sii, sj, sjj;
    for (int i = 0 ; i < n ;i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'K') {
                source = (m*i + j) + m*n;
                si = i;
                sj = j;
            }
            else if (a[i][j] == 'H') {
                sink = (m*i + j);
                sii = i;
                sjj = j;
            }
        }
    }
    if (si == sii) {
        if (sj - sjj == 1 || sj - sjj == -1) {
            printf("-1");
            return 0;
        }
    }
    if (sj = sjj) {
        if (si - sii == 1 || si - sii == -1) {
            printf("-1");
            return 0;
        }
    }



    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (a[i][j] == '#')
                continue;
            Edge *e1 = new Edge(m*i+j + m*n, 1);
            Edge *e2 = new Edge(m*i+j, 0);
            e1 -> rev = e2;
            e2 -> rev = e1;
            //v[m*i+j].push_back(m*i+j + m*n);
            //v[m*i+j + m*n].push_back(m*i +j);
            //c[m*i+j][m*i+j + m*n] = 1;
            v[m*i + j].push_back(e1);
            v[m*i+j + m*n].push_back(e2);
            for (int k = 0 ; k < 4; k ++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if (a[nx][ny] != '#') {
                        //v[i*m+j + m*n].push_back(nx*m + ny);
                        //v[nx*m + ny].push_back(i*m+j + m*n);
                        //c[i*m+j + m*n][nx*m + ny] = 1000000000;
                        Edge *e3 = new Edge(nx*m + ny, 1000000000);
                        Edge *e4 = new Edge(m*i + j + m*n, 0);
                        e3->rev = e4;
                        e4->rev = e3;
                        v[i*m+j + m*n].push_back(e3);
                        v[nx*m + ny].push_back(e4);
                    }
                }
            }
        }
    }
    int ans = 0;
    while (true) {
        memset(path, 0, sizeof(path));
        memset(pre, -1, sizeof(pre));
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0 ; i < v[cur].size(); i++) {
                int next = v[cur][i]->to;
                if (v[cur][i]->able() > 0 && pre[next] == -1) {
                    pre[next] = cur;
                    q.push(next);
                    path[next] = v[cur][i];
                    if (next == sink)
                        break;
                }
            }
        }
        if (pre[sink] == -1)
            break;
        for (int i = sink ; i != source ; i = pre[i]) {
            path[i]->addflow();
        }
        ans++;
    }
    printf("%d", ans);
















  return 0;
}
