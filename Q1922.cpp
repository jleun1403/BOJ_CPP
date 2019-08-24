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

using namespace std;
int n, m;
int c[1001];
vector<vector<pair<int, int>>> v;


int main() {
    scanf("%d %d", &n, &m);
    v.resize(n+1);
    for (int i = 1 ; i <= m ; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        v[from].push_back(make_pair(to, weight));
        v[to].push_back(make_pair(from, weight));
    }
    c[1] = 1;
    int ans = 0;
    priority_queue<pair<int, int>> q;
    for (int i = 0 ; i < v[1].size(); i++) {
        q.push(make_pair(v[1][i].second * -1, v[1][i].first));
    }
    while(!q.empty()) {
        pair<int, int> next = q.top();
        q.pop();
        if (c[next.second] == 1)
            continue;
        c[next.second] = 1;
        ans += next.first * -1;
        for (int i = 0 ; i < v[next.second].size() ; i++)
            q.push(make_pair(v[next.second][i].second * -1, v[next.second][i].first));
    }
    printf("%d", ans);








  return 0;
}
