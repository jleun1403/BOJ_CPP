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
bool cleaned[51][51];
int a[51][51];
int dir; // 0 : north - 1 : west - 2 : south - 3 : east
int cleaned_area;
int n, m, r, c;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

pair<int, int> rear() {
    int x = r;
    int y = c;
    switch(dir) {
        case 0 :
            x += 1;
            break;
        case 1:
            y += 1;
            break;
        case 2:
            x -= 1;
            break;
        case 3:
            y -= 1;
            break;
    }
    return make_pair(x, y);
}

pair <int ,int > at_left() {
    int x = r;
    int y = c;
    switch(dir) {
        case 0 :
            y -= 1;
            break;
        case 1:
            x += 1;
            break;
        case 2:
            y += 1;
            break;
        case 3:
            x -= 1;
            break;
    }
    return make_pair(x, y);
}

int main() {
    scanf("%d %d %d %d %d", &n, &m, &r, &c, &dir);
    cleaned_area = 0;
    if (dir == 1)
        dir = 3;
    else if (dir == 3)
        dir = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf("%d", &a[i][j]);
            cleaned[i][j] = false;
        }
    }
    while(true) {
        if (!cleaned[r][c]) {
            cleaned[r][c] = true;
            cleaned_area++;
        }
        int wall = 0;
        for (int i = 0 ; i < 4 ; i++) {
            int nx = r + dx[i];
            int ny = c + dy[i];
            if (a[nx][ny] == 0 && !cleaned[nx][ny])
                break;
            wall++;
        }
        if (wall == 4) {
            if (a[rear().first][rear().second] == 1) {
                printf("%d", cleaned_area);
                return 0;
            }
        }

        bool flag = false;
        for (int i = 0 ; i < 4 ; i++) {
            if (a[at_left().first][at_left().second] == 0 && !cleaned[at_left().first][at_left().second]) {
                r = at_left().first;
                c = at_left().second;
                dir += 1;
                dir = dir % 4;
                flag = true;
                break;
            }
            dir += 1;
            dir = dir % 4;
        }
        if (flag)
            continue;
         r = rear().first;
         c = rear().second;
    }

















  return 0;
}
