#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;
vector<vector<pair<int, int>>> v;
int c[10001];

void BFS(int node, int limit){
    queue<int> q;
    q.push(node);
    c[node] = 1;
    while(!q.empty()) {
        int nextnode = q.front();
        q.pop();
        for (int i = 0 ; i < v[nextnode].size() ; i++) {
            if (c[v[nextnode][i].first] == 0 && v[nextnode][i].second >= limit) {
                c[v[nextnode][i].first] = 1;
                q.push(v[nextnode][i].first);
            }
        }
    }
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    v.resize(n+1);
    for (int i = 0 ; i < m ; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        v[from].push_back(make_pair(to, weight));
        v[to].push_back(make_pair(from, weight));
    }
    int left = 0;
    int right = 1000000000;
    int start, arrive, ans;
    scanf("%d %d", &start, &arrive);
    while (left <= right) {
        memset(c, 0, sizeof(c));
        int mid = (left + right) / 2;
        BFS(start, mid);
        if (c[arrive] == 1) {
            ans = mid;
            left = mid +1;
        }
        else
            right = mid - 1;
    }
    cout <<ans;









  return 0;
}
