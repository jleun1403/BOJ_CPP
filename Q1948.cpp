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
int n, m, start, finish;
vector<vector<pair<int, int>>> v;
vector<vector<pair<int, int>>> rev;
int dist[10001];
int in[10001];
bool used[10001][10001];

int main() {
    scanf("%d %d", &n, &m);
    v.resize(n+1); rev.resize(n+1);
    for (int i = 0 ; i < m ; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        v[from].push_back(make_pair(to, weight));
        rev[to].push_back(make_pair(from, weight));
        in[to] += 1;
    }
    scanf("%d %d", &start, &finish);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0 ; i < v[cur].size() ; i++) {
            auto p = v[cur][i];
            int next = p.first;
            int weight = p.second;
            dist[next] = max(dist[next], dist[cur] + weight);
            in[next] -= 1;
            if (in[next] == 0)
                q.push(next);
        }
    }

    queue<pair<int, int>> rq;
    int ans = 0;
    for (int i = 0 ; i < rev[finish].size() ; i++) {
        int next = rev[finish][i].first;
        int weight = rev[finish][i].second;
        if (dist[next] == dist[finish] - weight) {
            rq.push(make_pair(next, weight));
            ans++;
            used[finish][next] = true;
        }
    }
    while (!rq.empty()) {
        int curr = rq.front().first;
        rq.pop();
        for (int i = 0 ; i < rev[curr].size(); i++) {
            int next = rev[curr][i].first;
            int weight = rev[curr][i].second;
            if ((dist[next] == dist[curr] - weight) && (used[curr][next] == false)) {
                rq.push(make_pair(next, weight));
                ans++;
                used[curr][next] = true;
            }
        }
    }
    printf("%d\n%d",dist[n], ans);

















  return 0;
}
