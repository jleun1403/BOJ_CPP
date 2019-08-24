#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;
char v[21][21];
int ch[26];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r, c;
vector<int> temp;

int DFS(int x, int y) {
    int ans = 0;
    if (ch[v[x][y] - 'A'] == 1) {
        return 0;
    }
    ch[v[x][y] - 'A'] = 1;
    for (int i = 0 ; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < r && 0<= ny && ny < c) {
            int p = DFS(nx, ny);
            if (p > ans)
                ans = p;
        }
    }
    ch[v[x][y] - 'A'] = 0;
    return ans +1;
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0 ; i <r ; i++) {
        for (int j = 0 ; j < c ; j++) {
            scanf(" %1c", &v[i][j]);
        }
    }
    cout << DFS(0, 0);









  return 0;
}
