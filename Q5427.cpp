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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char a[1001][1001];
int fire[1001][1001];
int escape[1001][1001];
int visited[1001][1001];
void BFS_fire(int x, int y) {
    fire[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()) {
        auto p = q.front();
        int cx = p.first;
        int cy = p.second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] != '#') {
                    if (fire[nx][ny] > fire[cx][cy] + 1) {
                        fire[nx][ny] = fire[cx][cy] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}

void BFS_escape(int x, int y) {
    escape[x][y] = 0;
    visited[x][y] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        auto p = q.front();
        int cx = p.first;
        int cy = p.second;
        q.pop();
        for (int i = 0 ; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] != '#' && visited[nx][ny] == 0)  {
                    if (escape[cx][cy] + 1 < fire[nx][ny]) {
                        visited[nx][ny] = 1;
                        escape[nx][ny] = escape[cx][cy] +1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}

int main() {
    int p, q;
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
    scanf("%d %d", &m, &n);
    memset(a, 0, sizeof(a));
    memset(fire, 0, sizeof(fire));
    memset(escape, 0, sizeof(escape));
    memset(visited, 0, sizeof(visited));
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            scanf(" %1c", &a[i][j]);
            if (a[i][j] == '@') {
                p = i;
                q = j;
            }
        }
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++) {
            fire[i][j] = inf;
            escape[i][j] = inf;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (a[i][j] == '*')
                BFS_fire(i, j);
        }
    }
    BFS_escape(p, q);
    int ans = inf;
    for (int i = 0 ; i < m ; i++) {
        ans = min(ans, escape[0][i]);
    }
    for (int i = 0 ; i < m ; i++) {
        ans = min(ans, escape[n-1][i]);
    }
    for (int i = 0 ; i <n ; i++) {
        ans = min(ans, escape[i][0]);
    }
    for (int i = 0 ; i < n ;i++) {
        ans = min(ans, escape[i][m-1]);
    }
    if (ans == inf){
        printf("IMPOSSIBLE\n");
    }

    else {
        printf("%d\n", ans + 1);
    }
    }












  return 0;
}
