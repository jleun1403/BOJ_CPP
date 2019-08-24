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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;
int a[100][100];
bool visited[100][100];

bool BFS(double k) {
    int biggest, smallest;
    biggest = a[0][0];
    smallest = a[0][0];
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    while(!q.empty()) {
        auto p = q.front();
        int cx = p.first;
        int cy = p.second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (visited[nx][ny] == false) {
                    if (abs(a[nx][ny] - a[0][0]) <= k) {
                        visited[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    if (visited[n-1][n-1] == true)
        return true;
    else
        return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    double left = 0.0;
    double right = 200.0;
    double ans = 0;
    for (int i = 0 ; i < 100 ; i++) {
        memset(visited, false, sizeof(visited));
        double mid = (left +right) / 2.0;
        if (BFS(mid)) {
            ans = mid;
            right = mid;
        }
        else {
            left = mid;
        }
    }
    printf("%lf", ans);
















  return 0;
}
