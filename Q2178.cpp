#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int cnt;
vector<vector<int>> v;
vector<vector<int>> d;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int x, int y){
    d[x][y] = cnt;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        int k = q.front().first;
        int l = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4; i++) {
            int nx = k +dx[i];
            int ny = l +dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (d[nx][ny] == 0 && v[nx][ny] == 1){
                    d[nx][ny] = d[k][l] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

}



int main(){


    cin >> n >> m;
    v.resize(n, vector<int> (m));
    d.resize(n, vector<int> (m, 0));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf("%1d", &v[i][j]);
        }
    }
    cnt = 1;
    BFS(0, 0);
    cout << d[n-1][m-1];



}
