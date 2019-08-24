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
    #define source 5000
    #define drain 5001

    using namespace std;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    char a[52][52];
    vector<int> c;
    vector<int> p;
    int dist[52][52];
    int check[52][52];
    int n, m;
    vector<vector<pair<int, int>>> v(5010);
    int A[5001], B[5001];
    bool visited[5001];

    void BFS(int x, int y) {
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        dist[x][y] = 0;
        check[x][y] = 1;
        while(!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            for (int i = 0 ; i <4 ; i++) {
                int nx = cx +dx[i];
                int ny = cy +dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    if (check[nx][ny] == 0 && a[nx][ny] != 'X') {
                        check[nx][ny] = 1;
                        dist[nx][ny] = dist[cx][cy] +1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }

    bool DFS(int a, int b) {
        visited[a] = true;
        for (int i = 0 ; i < v[a].size(); i++) {
            if (v[a][i].second > b)
                continue;
            int next = v[a][i].first;
            if (B[next] == -1 || !visited[B[next]] && DFS(B[next], b)) {
                A[a] = next;
                B[next] = a;
                return true;
            }
        }
        return false;
    }

    bool possible(int k) {
        int ans = 0;
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        for (int i = 0 ; i < 2500 ; i++) {
            if (A[i] == -1) {
                memset(visited, false, sizeof(visited));
                if (DFS(i, k)) {
                    ans++;
                }
            }
        }
        return (ans == c.size());
    }


    int main() {

        scanf("%d %d", &n, &m);
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                scanf(" %1c", &a[i][j]);
                if (a[i][j] == 'P') {
                    p.push_back(i*m + j + 2500);
                }
                if (a[i][j] == 'C') {
                    c.push_back(i*m + j);
                }
            }
        }
        if (c.size() == 0) {
            printf("0");
            return 0;
        }

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (a[i][j] == 'C') {
                    BFS(i, j);
                    for (int k = 0 ; k < p.size() ; k++) {
                        int pat = p[k];
                        int px = (p[k] - 2500) / m;
                        int py = (p[k] - 2500) % m;
                        if (dist[px][py] != 0) {
                            v[i*m + j].push_back(make_pair(p[k], dist[px][py]));
                            v[p[k]].push_back(make_pair(i*m + j, 0));
                        }
                    }
                    memset(check, 0, sizeof(check));
                    memset(dist, 0, sizeof(dist));
                }
            }
        }

        int left = 0;
        int right = 5000;
        int ans = 0;
        while(left <= right) {
            int mid = (left +right) / 2;
            if (possible(mid)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if (ans == 0)
            printf("-1");
        else
            printf("%d", ans);


















      return 0;
    }
