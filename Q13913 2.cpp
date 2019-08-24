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

bool visited[100001];
int pre[100001];
int dist[100001];

void BFS(int x) {
    queue<int> q;
    q.push(x);
    pre[x] = -1;
    visited[x] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur > 0) {
            int next = cur -1;
            if (visited[next] == false) {
                visited[next] = true;
                pre[next] = cur;
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
        if (cur < 100000) {
            int next = cur + 1;
            if (visited[next] == false) {
                visited[next] = true;
                pre[next] = cur;
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
        if (cur <= 50000) {
            int next = cur*2;
            if (visited[next] == false) {
                visited[next] = true;
                pre[next] = cur;
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
}

void print(int k) {
    if (pre[k] == -1)
        printf("%d ", k);
    else {
        print(pre[k]);
        printf("%d ", k);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    memset(visited, false, sizeof(visited));
    BFS(n);
    printf("%d\n", dist[k]);
    print(k);

















  return 0;
}
