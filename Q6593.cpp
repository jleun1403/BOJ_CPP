#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

// north east south west up down
int dz[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int z, x, y;

int dist[30][30][30];
char board[30][30][30];
bool visited[30][30][30];

void BFS(vector<int> &v) {
    queue<vector<int>> q;
    q.push(v);
    visited[v[0]][v[1]][v[2]] = true;
    while(!q.empty()) {
        auto p = q.front();
        int cz = p[0];
        int cx = p[1];
        int cy = p[2];
        q.pop();
        for (int i = 0 ; i < 6 ; i++) {
            int nz = cz + dz[i];
            int ny = cy + dx[i];
            int nx = cx + dy[i];
            if (0 <= nz && nz < z && 0 <= nx && nx < x && 0 <= ny && ny < y) {
                if (!visited[nz][nx][ny] && board[nz][nx][ny] != '#') {
                    dist[nz][nx][ny] = dist[cz][cx][cy] + 1;
                    visited[nz][nx][ny] = true;
                    vector<int> t(3);
                    t[0] = nz; t[1] = nx; t[2] = ny;
                    q.push(t);
                }
            }
        }
    }
}

int main() {
    while(true) {
        scanf("%d %d %d", &z, &x, &y);
        vector<int> start;
        vector<int> finish;
        if (x == 0 && y == 0 && z == 0)
            break;
        memset(dist, 0, sizeof(dist));
        memset(board, 0, sizeof(board));
        memset(visited, false, sizeof(visited));
        for (int i = 0 ; i < z ; i++) {
            for (int j = 0 ; j < x ; j ++) {
                for (int k = 0 ; k < y ; k++) {
                    scanf(" %c", &board[i][j][k]);
                    if (board[i][j][k] == 'S') {
                        start.push_back(i);
                        start.push_back(j);
                        start.push_back(k);
                    }
                    else if (board[i][j][k] == 'E') {
                        finish.push_back(i);
                        finish.push_back(j);
                        finish.push_back(k);
                    }
                }
            }
        }
        BFS(start);
        if (dist[finish[0]][finish[1]][finish[2]]) {
            printf("Escaped in %d minute(s)\n", dist[finish[0]][finish[1]][finish[2]]);
        }
        else printf("Trapped!\n");
    }
















  return 0;
}
