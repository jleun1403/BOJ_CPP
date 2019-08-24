#include <bits/stdc++.h>

using namespace std;

char board[51][51];
int docci[51][51];
int water[51][51];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
queue<pair<int, int>> water_queue;
int n, m;

void water_BFS() {
    while(!water_queue.empty()){
        auto p = water_queue.front();
        int cx = p.first;
        int cy = p.second;
        water_queue.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (board[nx][ny] == '.' && water[nx][ny] == 0) {
                    water_queue.push(make_pair(nx, ny));
                    water[nx][ny] = water[cx][cy] + 1;
                }
            }
        }
    }
}

void docci_BFS(int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int cx = p.first;
        int cy = p.second;
        for (int i = 0 ; i < 4 ; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if ((board[nx][ny] == '.' || board[nx][ny] == 'D') && docci[nx][ny] == 0) {
                    if ((docci[cx][cy] + 1 < water[nx][ny]) || (water[nx][ny] == 0)) {
                        docci[nx][ny] = docci[cx][cy] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}

int main() {
    //printf("ddd");
    scanf("%d %d", &n, &m);
    int x, y;
    int a, b;
    for (int i = 0 ; i < n;  i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf(" %c", &board[i][j]);
            if (board[i][j] == '*') {
                water_queue.push(make_pair(i, j));
            }
            if (board[i][j] == 'D') {
                a = i;
                b = j;
            }
            if (board[i][j] == 'S') {
                x = i;
                y = j;
            }
            //printf("%c", board[i][j]);
        }
    }
    water_BFS();
    /*for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            printf("%d ", water[i][j]);
        }
        printf("\n");
    }
    docci_BFS(x, y);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            printf("%d ", docci[i][j]);
        }
        printf("\n");
    } */
    docci_BFS(x, y);
    if (docci[a][b] == 0) {
        printf("KAKTUS\n");
    }
    else printf("%d\n", docci[a][b]);

    return 0;
}