#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, m;
int cnt;
vector<vector<int>> d;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int x, int y){
    d[x][y] = 1;
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
                if (d[nx][ny] != -1 || d[nx][ny] != 1){
                    if ((d[nx][ny] == 0))
                        {
                        d[nx][ny] = d[k][l] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}
void BFS2(int x, int y){
    d[x][y] = 1;
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
                if (d[nx][ny] != -1 || d[nx][ny] != 1){
                    if  ((d[nx][ny] > d[k][l] +1) || (d[nx][ny] == 0))
                        {
                        d[nx][ny] = d[k][l] + 1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}



int main(){


    cin >> m >> n;
    int cnt1 = 0;
    stack <pair<int, int>> ones;
    d.resize(n, vector<int> (m, 0));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf("%d", &d[i][j]);
            if (d[i][j] == 1) {
                ones.push(make_pair(i, j));
            }
        }
    }
    int cnt11 = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++)
            if (d[i][j] == -1)
                cnt11++;
    }
    if (cnt11 == m*n){
        cout << "0";
        return 0;
    }
    if (ones.empty()){
        cout << "-1";
        return 0;
    }
    int k = ones.top().first;
    int l = ones.top().second;
    BFS(k, l);
    ones.pop();
    while (!ones.empty()){
        k = ones.top().first;
        l = ones.top().second;
        BFS2(k, l);
        ones.pop();
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout << d[i][j] << ' ';
        }
        cout <<endl;
    }
    int mx = d[0][0];
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ;j < m ; j++) {
            if (d[i][j] == 0){
                cout << "-1";
                return 0;
            }
            if (d[i][j] > mx)
                mx = d[i][j];
        }
    }
    cout << mx - 1;

}

