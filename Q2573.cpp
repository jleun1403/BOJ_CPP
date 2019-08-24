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
int a[300][300];
int temp[300][300];
int c[300][300];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

void shrink() {
    for (int i = 1 ; i < n-1 ; i++) {
        for (int j = 1 ; j < m-1 ; j++) {
            int cnt = 0;
            if (a[i][j] > 0) {
                for (int k = 0 ; k < 4 ; k++) {
                    if (a[i+dx[k]][j+dy[k]] == 0)
                        cnt++;
                }
            }
            temp[i][j] = max(a[i][j] - cnt, 0);
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            a[i][j] = temp[i][j];
        }
    }
}

void DFS(int x, int y) {
    c[x][y] = 1;
    for (int i = 0 ; i < 4 ; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (c[nx][ny] == 0 && a[nx][ny] > 0)
                DFS(nx, ny);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < n ;i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf("%d", &a[i][j]);
            if (i == 0 || i == n-1 || j == 0 || j == m-1)
                a[i][j] = 0;
        }
    }

    int ans = 0;
    while(ans < 10000) {
        memset(c, 0, sizeof(c));
        int group = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j <m ; j++) {
                if (c[i][j] ==0 && a[i][j] > 0) {
                    DFS(i, j);
                    group++;
                }
            }
        }


        if (group >= 2) {
            printf("%d", ans);
            return 0;
        }
        ans++;
        shrink();

    }
    printf("0");















  return 0;
}
