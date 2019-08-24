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
int n, k;
int dist[100001];
int make[100001];

void BFS(int x){
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur > 0) {
            int next = cur - 1;
            dist[next] = min(dist[next], dist[cur] + 1);
            if (dist[next] == dist[cur] + 1) {
                make[next] += 1;
                q.push(next);
            }
        }
        if (cur < 100000) {
            int next = cur + 1;
            dist[next] = min(dist[next], dist[cur] + 1);
            if (dist[next] == dist[cur] + 1) {
                make[next] += 1;
                q.push(next);
            }
        }
        if (cur <= 50000) {
            int next = cur *2;
            dist[next] = min(dist[next], dist[cur] + 1);
            if (dist[next] == dist[cur] + 1) {
                make[next] += 1;
                q.push(next);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0 ; i <= 100000 ; i++) {
        dist[i] = inf;
    }
    dist[n] = 0;
    make[n] = 1;
    BFS(n);
    printf("%d\n%d", dist[k], make[k]);

















  return 0;
}
