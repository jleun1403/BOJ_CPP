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
int n, m;
// 1~50 :A, 51~100:B
// 0:source 101:drain

const int source= 0;
const int drain = 101;

vector<vector<int>> v(102);

int cap[102][102];
int flow[102][102];
int cost[102][102];
int dist[102];
int pre[102];
bool inque[102];
int flow2[102][102];
int flowans[102][102];


int main() {
    scanf("%d %d", &n, &m);
    int sumn = 0;
    int summ = 0;
    for (int i = 1 ; i<= n ; i++) {
        int a;
        scanf("%d", &a);
        sumn += a;
        for (int j = m ; j > 0 ; j--) {
            int op = j + 50;
            cap[i][op] = 1;
            cost[i][op] = j;
            cost[op][i] = -j;
            v[i].push_back(op);
            v[op].push_back(i);
        }
        cap[source][i] = a;
        v[source].push_back(i);
        v[i].push_back(source);
    }
    for (int i = 1 ; i <= m ; i++) {
        int b;
        scanf("%d", &b);
        summ += b;
        cap[i+50][drain] = b;
        v[i+50].push_back(drain);
        v[drain].push_back(i+50);
    }
    if (sumn != summ) {
        printf("-1");
        return 0;
    }

    int ans = 0;

    while (true) {
        memset(pre, -1, sizeof(pre));
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0 ; i < v[cur].size() ; i++) {
                int next = v[cur][i];
                if (cap[cur][next] > flow[cur][next] && pre[next] == -1) {

                    pre[next] = cur;
                    q.push(next);
                }
            }
        }
        if (pre[drain] == -1)
            break;
        for (int i = drain ; i!= source ; i = pre[i]) {
            flow[pre[i]][i] += 1;
            flow[i][pre[i]] -= 1;
        }
        ans++;
    }
    if (ans != sumn) {
        printf("-1");
        return 0;
    }





    for (int i = 1;  i<= n ; i++) {
        for (int j = 1; j <= m ; j++) {
            cap[i][50+j] = 0;
            if (flow[i][50+j] == 0)
                continue;

            int temp = 0;
            memset(flow2, 0, sizeof(flow2));
            while (true) {
                memset(pre, -1, sizeof(pre));
                queue<int> q;
                q.push(source);
                while(!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    for (int i = 0 ; i < v[cur].size() ; i++) {
                        int next = v[cur][i];
                        if (pre[next] == -1 && cap[cur][next] > flow2[cur][next]) {
                            pre[next] = cur;
                            q.push(next);
                            if (next == drain)
                                break;
                        }
                    }
                }
                if (pre[drain] == -1)
                    break;
                for (int i = drain ; i!= source ; i = pre[i]) {
                    flow2[pre[i]][i] += 1;
                    flow2[i][pre[i]] -= 1;
                }
                temp++;
            }
            if (temp == ans) {
                for (int k = 1 ; k <= n ; k++) {
                    for (int l = 1 ; l <= m ; l++)
                        flow[k][50+l] = flow2[k][50+l];
                }
            }
            else {
                cap[i][50+j] = 1;
            }
        }
    }

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            printf("%d", flow[i][50+j]);
        }
        printf("\n");
    }
















    return 0;
}

