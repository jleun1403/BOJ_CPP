#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> d;
int m, n;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(int x, int y) {
    d[x][y] = 1;
    for (int i = 0 ; i < 8 ; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (d[nx][ny] == 0 && v[nx][ny] == 1)
                DFS(nx, ny);
        }
    }

}


int main() {
    while(true){
        cin >> m >> n;
        if (m == 0 && n == 0)
            break;
        v.resize(n);
        d.resize(n);
        for (int i = 0 ; i < n; i++) {
            for (int j = 0 ; j < m ; j++) {
                int k;
                cin >> k;
                v[i].push_back(k);
                d[i].push_back(0);
            }
        }
        int cnt = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if ((v[i][j] == 1) && (d[i][j] == 0)) {
                    DFS(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';

        v.clear();
        d.clear();


    }
}
