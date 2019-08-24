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
#define inf 1000000000

using namespace std;
int dist[100001];
int c[100001];
int n, k;

void BFS(int x) {
    queue<int> q;
    q.push(x);
    c[x] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        int next = cur;
        while(next <= 50000 && cur != 0) {
            next = next * 2;
            if (c[next] == 0)
                q.push(next);
            dist[next] = min(dist[next], dist[cur]);
            c[next] = 1;
        }
        if (cur < 100000) {
            next = cur +1;
            dist[next] = min(dist[next], dist[cur] +1);
            if (dist[next] == dist[cur] + 1) {
                c[next] = 1;
                q.push(next);
            }
        }
        if (cur > 0) {
            next = cur - 1;
            dist[next] = min(dist[next], dist[cur] +1);
            if (dist[next] == dist[cur] + 1) {
                c[next] = 1;
                q.push(next);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0 ; i <= 100000 ; i++)
        dist[i] = inf;
    dist[n] = 0;
    BFS(n);
    printf("%d", dist[k]);

















  return 0;
}
