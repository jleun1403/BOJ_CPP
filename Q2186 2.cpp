#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int n, m, k;
string s;
char a[100][100];
int b[100][100][81];
int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, 1, -1};
vector<vector<vector<pair<int, int>>>> v;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++) {
            scanf(" %c", &a[i][j]);
        }
    }
    cin >> s;
    v.resize(n);
    for (int i = 0 ; i < n ; i++) {
        v[i].resize(m);
    }
    for (int l = 1 ; l <= k ; l++){
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                for (int dir = 0 ; dir < 4 ; dir++) {
                    int nx = i + dx[dir] * l;
                    int ny = j + dy[dir] * l;
                    if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                        v[i][j].push_back(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++) {
            if (a[i][j] == s[s.length() - 1])
                b[i][j][s.length() - 1] = 1;
        }
    }
    int ans = 0;
    for (int len = 1 ; len < s.length() ; len++){
        int cur = s.length() - 1 - len;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++) {
                if (a[i][j] == s[cur]) {
                    for (int t = 0 ; t < v[i][j].size() ; t++) {
                        int nx = v[i][j][t].first;
                        int ny = v[i][j][t].second;
                        if (a[nx][ny] == s[cur+1])
                            b[i][j][cur] += b[nx][ny][cur+1];
                    }
                    if (len == s.length()- 1)
                        ans += b[i][j][0];
                }

            }
        }
    }
    /*for (int i = 0 ; i<n ; i++){
        for (int j = 0 ; j < m ; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    } */
    printf("%d\n", ans);















  return 0;
}
