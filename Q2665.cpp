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
int a[50][50];
int dist[50][50];
bool check[2500];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            scanf("%1d", &a[i][j]);
            dist[i][j] = inf;
        }
    }

    memset(check, false, sizeof(check));
    priority_queue<pair<int , int>> q;
    q.push(make_pair(0, 0));
    dist[0][0] = 0;
    while(!q.empty()) {
        auto p = q.top();
        q.pop();
        int cur = p.second;
        if (check[cur])
            continue;
        check[cur] = true;
        int cx = cur / n;
        int cy = cur % n;
        for (int i = 0 ; i < 4 ; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if ( 0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (dist[nx][ny] > dist[cx][cy] + a[nx][ny] * -1 + 1) {
                    dist[nx][ny] = dist[cx][cy] + a[nx][ny]*-1 + 1;
                    q.push({-dist[nx][ny], nx*n + ny});
                }
            }
        }
    }
    printf("%d", dist[n-1][n-1]);















  return 0;
}
