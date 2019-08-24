#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int a[125][125];
int dist[125][125];

int main() {
    int n;
    int problem = 0;
    while(true) {
        scanf("%d", &n);
        if (n == 0)
            return 0;
        problem++;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                scanf("%d", &a[i][j]);
                dist[i][j] = inf;
            }
        }
        dist[0][0] = a[0][0];
        priority_queue<pair<int , int>> q;
        q.push(make_pair(-a[0][0], 0));
        while(!q.empty()) {
            int cx = q.top().second / n;
            int cy = q.top().second % n;
            q.pop();
            for (int i = 0 ; i < 4;  i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    int next = nx*n + ny;
                    if (dist[nx][ny] > dist[cx][cy] + a[nx][ny]) {
                        dist[nx][ny] = dist[cx][cy] + a[nx][ny];
                        q.push(make_pair(-dist[nx][ny], next));
                    }
                }
            }

        }
        printf("Problem %d: %d\n", problem, dist[n-1][n-1]);
    }
















  return 0;
}
