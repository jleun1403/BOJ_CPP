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
int n;
int a[100][100];
bool visited[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};


bool BFS(int x, int y, int m, int k) {
    if (a[x][y] < m || a[x][y] > k)
        return false;
    queue<pair<int , int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    while(!q.empty()) {
        auto cur = q.front();
        int cx = cur.first;
        int cy = cur.second;
        q.pop();
        for (int i = 0 ; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (visited[nx][ny] == false && a[nx][ny] <=k && a[nx][ny] >= m) {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return visited[n-1][n-1];

}

int main() {
    scanf("%d", &n);
    int min = 200;
    int max = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] > max)
                max = a[i][j];
            if (a[i][j] < min)
                min = a[i][j];
        }
    }

    int left = 0;
    int right = 200;
    int ans = 0;
    while(left <= right ) {
        int mid = (left + right) / 2;
        bool flag = false;
        for (int i = min ; i <= max ; i++) {
            memset(visited, false, sizeof(visited));
            if (BFS(0, 0, i, i+mid)) {
                flag = true;
                break;
            }
        }
        if (flag) {
            right = mid -1;
            ans = mid;
        }
        else
            left = mid + 1;
    }
    printf("%d\n", ans);
















  return 0;
}
