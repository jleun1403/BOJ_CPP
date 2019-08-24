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

int a[100][100];
bool visited[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;

void BFS(int x, int y, int k) {
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()) {
        auto cur = q.front();
        int cx = cur.first;
        int cy = cur.second;
        q.pop();
        for (int i = 0 ; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (visited[nx][ny] == false && a[nx][ny] > k) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0 ; i <= 100 ; i++) {
        memset(visited, false, sizeof(visited));
        int temp = 0;
        for (int k = 0 ; k < n ; k++) {
            for (int j = 0 ; j < n ; j++) {
                if (a[k][j] > i && !visited[k][j]) {
                    BFS(k, j, i);
                    temp++;
                }
            }
        }
        ans = max(ans, temp);
    }
    printf("%d", ans);
















  return 0;
}
