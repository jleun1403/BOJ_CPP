#include <bits/stdc++.h>
using namespace std;

int board[21][21];
int n;
int eaten;
int sharksize;
int dist[21][21];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int sx, sy;

void BFS(int x, int y) {
    queue<pair<int, int >> q;
    dist[x][y] = 1;
    q.push(make_pair(x, y));
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int cx = p.first;
        int cy = p.second;
        for (int i = 0 ;i < 4 ; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (dist[nx][ny] == 0 && (board[nx][ny] == 0 || sharksize >= board[nx][ny])) {
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] = dist[cx][cy] + 1;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    sharksize = 2;
    eaten = 0;
    int answer = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 9) {
                sx = i;
                sy = j;
            }
        }
    }
    while(true) {
        memset(dist, 0, sizeof(dist));
        BFS(sx, sy);
        int caneat = 0;
        int mindist  = 987654321;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ;j++) {
                //printf("%d ", dist[i][j]);
                if(dist[i][j] && board[i][j] != 0 && board[i][j] < sharksize) {
                    caneat  += 1;
                    mindist = min(mindist, dist[i][j]);
                } 
            }
        }
        if (caneat == 0)
            break;
        bool found = false;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ;j++) {
                if (dist[i][j] == mindist && board[i][j] != 0 && board[i][j] < sharksize) {
                    board[i][j] = 9;
                    board[sx][sy] = 0;
                    sx = i;
                    sy = j;
                    eaten += 1;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        if (sharksize == eaten) {
            sharksize += 1;
            eaten = 0;
        }
        answer += mindist - 1;
    }
    printf("%d\n", answer);

    return 0;
}