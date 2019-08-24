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

int n, m;
bool visited[10000];
int d[10000];
vector<vector<int>> v(10000);
bool dist[10000];


void DFS(int x) {
    visited[x] = true;
    dist[x] = true;
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0 ; i < v[cur].size() ; i++) {
            int next = v[cur][i];
            if (visited[next] == false) {
                visited[next] = true;
                dist[next] = true;
                q.push(next);
            }
        }
    }

}

int cnt() {
    int ans = 0;
    for (int i = 0 ; i < n ;i++) {
        if (dist[i])
            ans++;
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < m ; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;
        v[b].push_back(a);
    }

    for (int i = 0 ; i < n ; i++)
        d[i] = 1;
    for (int i = 0 ; i < n ; i++){
        DFS(i);
        d[i] = cnt();
        memset(visited, false, sizeof(visited));
        memset(dist, false, sizeof(dist));
    }

    vector<int> answer;
    int flag = 0;
    for (int i = 0 ; i < n ;i++) {
        if (d[i] > flag) {
            answer.clear();
            answer.push_back(i);
            flag = d[i];
        }
        else if (d[i] == flag) {
            answer.push_back(i);
        }
    }
    sort(answer.begin(), answer.end());
    for (int i = 0 ; i < answer.size(); i++){
        printf("%d ", answer[i] + 1);
    }













  return 0;
}
