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

using namespace std;
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int a[101][101];
int water[101][101];
int cheese[200];

void BFS_water(int x, int y) {
    water[x][y] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()) {
        auto p = q.front();
        int cx = p.first;
        int cy = p.second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 < nx && nx <= n && 0 < ny && ny <= m) {
                if (water[nx][ny] == 0 && a[nx][ny] == 0) {
                    water[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void shrink() {
    BFS_water(1, 1);
    for (int i = 2 ; i < n ; i++) {
        for (int j = 2 ; j < m ; j++) {
            if (a[i][j] == 1) {
                for (int k = 0 ; k < 4 ; k++) {
                    if (water[i+dx[k]][j+dy[k]] == 1) {
                        a[i][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    memset(water, 0, sizeof(water));
}

int countcheese() {
    int ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (a[i][j] == 1)
                ans++;
        }
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++)
            scanf("%d", &a[i][j]);
    }
    if (countcheese() == 0) {
        printf("0\n0");
        return 0;
    }
    for (int l = 0 ; l < 200 ; l++) {
        int x = countcheese();
        if (x == 0) {
            printf("%d\n%d", l, cheese[l-1]);
            return 0;
        }
        else
            cheese[l] = x;
        shrink();
    }















  return 0;
}
