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
vector<vector<pair<int ,int >>> v(1001);
int dist[1001];
int from[1001];
int c[1001];
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    priority_queue<pair<int, int>> q;
    from[1] = 0;
    q.push(make_pair(0, 1));
    for (int i = 2 ; i <= n ; i++) {
        dist[i] = inf;
    }
    while(!q.empty()) {
        auto p = q.top();
        int cur = p.second;
        q.pop();
        if (c[cur] == 1)
            continue;
        c[cur] = 1;
        for (int i = 0 ; i < v[cur].size() ; i++) {
            int next = v[cur][i].first;
            int d = v[cur][i].second;
            if (dist[next] > dist[cur] + d) {
                dist[next] = dist[cur] + d;
                from[next] = cur;
                q.push(make_pair(dist[next]*-1, next));
            }
        }
    }
    set<pair<int ,int >> s;
    for (int i = 2 ; i <= n ; i++) {
        int t = i;
        int p = from[i];
        s.insert(make_pair(p, t));
        while(p != 1) {
            s.insert(make_pair(p, t));
            t = p;
            p = from[t];
        }
    }
    cout << s.size() << '\n';
    for (auto i = s.begin() ; i != s.end() ; i++) {
        cout << (*i).first << ' ' << (*i).second << '\n';
    }















  return 0;
}
