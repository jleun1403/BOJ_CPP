#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int n, t;
vector<pair<int, int>> v;
int dist[50001];
bool visited[50001];

int BFS() {
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        int current_index = q.front();
        if (v[current_index].second == t) {
            return dist[current_index];
        }
        int cx = v[current_index].first;
        int cy = v[current_index].second;
        q.pop();
        for (int i = current_index - 1 ; i > 0 ; i--) {
            if (abs(v[i].first - cx) > 2 || abs(v[i].second - cy) > 2) {
                break;
            }
            if (!visited[i]) {
                dist[i] = dist[current_index] +1;
                visited[i] = true;
                q.push(i);
            }
        }
        for (int i = current_index + 1 ; i <= n ; i++) {
            if (abs(v[i].first - cx) > 2 || abs(v[i].second - cy) > 2) {
                break;
            }
            if (!visited[i]) {
                dist[i] = dist[current_index] +1;
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &t);
    v.push_back(make_pair(0, 0));
    memset(visited, false, sizeof(visited));
    for (int i = 0 ; i < n ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    printf("%d", BFS());
















  return 0;
}
