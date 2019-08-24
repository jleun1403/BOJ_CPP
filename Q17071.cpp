#include <bits/stdc++.h>

using namespace std;

int dist[500001];
bool visited[500001];

void BFS(int x) {
    visited[x] = true;
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur > 0 && !visited[cur-1]) {
            dist[cur-1] = dist[cur] + 1;
            q.push(cur-1);
            visited[cur-1] = true; 
        }
        if (cur < 500000 && !visited[cur+1]) {
            dist[cur+1] = dist[cur] + 1;
            q.push(cur+1);
            visited[cur+1] = true;
        }
        if (cur <= 250000 && !visited[cur*2]) {
            dist[cur*2] = dist[cur] + 1;
            q.push(cur*2);
            visited[cur*2] = true;
        }
    }
}

bool possible(int from, int to, int steps) {
    if (steps < dist[to])
        return false;
    if ((steps - dist[to] % 2) == 0)
        return true;
    if (to < from)
        return false;
    if (to > 0 && possible(from, to - 1, steps -1))
        return true;
    if (to < 500000 && possible(from, to + 1, steps-1))
        return true;
    if (to % 2 == 0 && possible(from, to / 2, steps - 1))
        return true;
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    BFS(n);
    int a = 0;
    while(true) {
        if (k > 500000)
            break;
        k += a;
        if (possible(n, k, a)) {
            printf("%d\n", a);
            return 0;
        }
        a++;
        printf("%d\n", a);
    }
    printf("-1\n");

    return 0;
}