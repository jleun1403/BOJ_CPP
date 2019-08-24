#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> group;
int n;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<int> answer;

void BFS(int x, int y, int cnt) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    group[x][y] = cnt;
    while (!q.empty()) {
        int k = q.front().first;
        int m = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int nx = k + dx[i];
            int ny = m + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                if (v[nx][ny] == 1 && group[nx][ny] == 0){
                    q.push(make_pair(nx, ny));
                    group[nx][ny] = cnt;
                }
            }
        }
    }

}

int main(){
    cin >> n;
    v.resize(n);
    group.resize(n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            int x;
            scanf("%1d", &x);
            v[i].push_back(x);
            group[i].push_back(0);
        }
    }
    int cnt = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n; j++) {
            if (v[i][j] == 1 && group[i][j] == 0)
                BFS(i, j, cnt++);
        }
    }
    cout << cnt - 1 << '\n';
    int result;
    for (int r = 1 ; r < cnt ; r++) {
        result = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n; j++) {
                if (group[i][j] == r)
                    result++;
            }
        }
        answer.push_back(result);
    }
    sort(answer.begin(), answer.end());
    for (int ekq : answer){
        cout << ekq << '\n';
    }
}
