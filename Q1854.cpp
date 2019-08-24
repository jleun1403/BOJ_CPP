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
int n, m, k;
vector<priority_queue<int>> dist(1001);
vector<vector<pair<int, int>>> a(1001);

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0 ; i < m ; i++) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        a[from].push_back(make_pair(to, cost));
    }
    priority_queue<pair<int ,int>> q;
    q.push({0, 1});
    dist[1].push(0);
    while(!q.empty()) {
        auto p = q.top();
        int cur_dist = p.first * -1;
        int cur = p.second;
        q.pop();
        for (int i = 0 ; i < a[cur].size() ; i++) {
            int next = a[cur][i].first;
            int cost = a[cur][i].second;
            if (dist[next].size() < k || dist[next].top() > cur_dist + cost) {
                if (dist[next].size() == k) {
                    dist[next].pop();
                }
                dist[next].push(cur_dist + cost);
                q.push(make_pair((cur_dist +cost) * -1, next));
            }
        }
    }
    for (int i = 1 ; i <= n ;i++) {
        if (dist[i].size() < k)
            printf("-1\n");
        else
            printf("%d\n", dist[i].top());
    }















  return 0;
}
