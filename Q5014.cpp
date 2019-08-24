#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int dist[1000001];
bool visited[1000001];
int f, s, g, u, d;

void BFS(int x) {
    visited[x] = true;
    queue<int> q;
    q.push(x);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur + u <= f){
            if (visited[cur + u] == false) {
                visited[cur+u] = true;
                dist[cur+u] = dist[cur] + 1;
                q.push(cur+ u);
            }
        }
        if (cur - d > 0) {
            if (visited[cur - d] == false) {
                visited[cur - d] = true;
                dist[cur -d] = dist[cur] + 1;
                q.push(cur - d);
            }
        }
    }
}

int main() {
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    BFS(s);
    if (dist[g] == 0 && s != g) {
        printf("use the stairs");
    }
    else printf("%d\n", dist[g]);














  return 0;
}
