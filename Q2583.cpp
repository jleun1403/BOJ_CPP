#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>
#define inf 987654321

using namespace std;
int n, m, k;
int a[100][100];
bool visited[100][100];
int group[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int groupsize[10000];

void BFS(int x, int y, int g) {
    visited[x][y] = true;
    group[x][y] = g;
    queue<pair<int, int>>q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int cx = p.first;
        int cy = p.second;
        for (int i = 0 ; i < 4 ; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (visited[nx][ny] == false && a[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    group[nx][ny] = g;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int t = 0 ; t < k ; t++) {
        int p,q,r,s;
        scanf("%d %d %d %d", &p, &q, &r, &s);
        for (int i = p;  i < r ; i++) {
            for (int j = n - s ; j < n - q; j++) {
                a[j][i] = 1;
            }
        }
    }
    int groupnum = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <m ; j++) {
            if (a[i][j] == 0 && visited[i][j] == false){
                BFS(i, j, groupnum);
                groupnum++;
            }
        }
    }
    printf("%d\n", groupnum-1);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (group[i][j] > 0) {
                groupsize[group[i][j]] +=1;
            }
        }
    }
    sort(groupsize, groupsize+10000);
    for (int i = 0 ; i < 10000 ; i++) {
        if (groupsize[i] > 0)
            printf("%d ", groupsize[i]);
    }



















  return 0;
}
