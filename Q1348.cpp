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
    vector<vector<int>> v(5010);
    int temp[5100][5110];
    int capacity[5112][5112];
    int f[5112][5112];
    int pre[5112];


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

    bool possible(int k) {
        memset(f, 0, sizeof(f));
        for (int i = 0 ; i < 5000; i ++) {
            for (int j = 0 ; j < 5000 ; j++) {
                if (temp[i][j] > k)
                    capacity[i][j] = 0;
                else if (temp[i][j] > 0)
                    capacity[i][j] = 1;
                else
                    capacity[i][j] = 0;
            }
        }
        int ans = 0;
        while(true) {
            memset(pre, -1, sizeof(pre));
            queue<int> q;
            q.push(source);
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int i = 0 ; i < v[cur].size(); i++) {
                    int next = v[cur][i];
                    if (pre[next] == -1 && capacity[cur][next] > f[cur][next]) {
                        pre[next] = cur;
                        q.push(next);
                        if (next == 5001)
                            break;
                    }
                }
            }
            if (pre[5001] == -1)
                break;
            for (int i = 5001; i != source ; i = pre[i]) {
                f[pre[i]][i] += 1;
                f[i][pre[i]] -= 1;
            }
            ans++;
        }
        return (ans >= c.size());
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
        if (p.size() != c.size()){
            printf("-1");
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
                            v[i*m + j].push_back(p[k]);
                            v[p[k]].push_back(i*m + j);
                            temp[i*m +j][p[k]] = dist[px][py];
                        }
                    }
                    memset(check, 0, sizeof(check));
                    memset(dist, 0, sizeof(dist));
                }
            }
        }
        for (int i = 0 ; i < c.size() ; i++) {
            v[source].push_back(c[i]);
            v[c[i]].push_back(source);
            capacity[source][c[i]] = 1;
        }
        for (int i = 0 ; i < p.size(); i++) {
            v[5001].push_back(p[i]);
            v[p[i]].push_back(5001);
            capacity[p[i]][5001] = 1;
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
