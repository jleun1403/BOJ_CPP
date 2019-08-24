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
int testcase, n, k, w;
int ttt[1001];
int dist[1001];
int indegree[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin >>testcase;
    while(testcase--) {
        memset(dist, 0, sizeof(dist));
        memset(ttt, 0, sizeof(ttt));
        memset(indegree, 0, sizeof(indegree));
        vector<vector<int>> v;
        v.resize(1001);
        cin >> n >> k;
        for (int i = 1 ; i <= n ; i++)
            cin >> ttt[i];
        for (int i = 0 ; i < k ; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            indegree[b]++;
        }
        cin >> w;
        queue<int> q;
        for (int i = 1 ; i <= n ; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dist[i] = ttt[i]; }
        }
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0 ; i < v[cur].size() ; i++) {
                int next = v[cur][i];
                dist[next] = max(dist[next], dist[cur]);
                indegree[next] -= 1;
                if (indegree[next] == 0) {
                    dist[next] += ttt[next];
                    q.push(next);
                }
            }

        }
        cout << dist[w] << '\n';
        v.clear();

    }
















  return 0;
}
