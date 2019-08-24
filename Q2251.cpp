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
int check[201][201];
int ans[201];

void BFS(int a, int b, int c) {
    int nx, ny, nz;
    check[0][0] = 1;
    ans[c] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int z = (c) - x - y;
        q.pop();

        // x -> y
        nx = 0;
        ny = x + y;
        if (ny >= b) {
            nx = ny - b;
            ny = b;
        }
        if (check[nx][ny] == 0) {
            check[nx][ny] = 1;
            q.push(make_pair(nx, ny));
            if (nx == 0) {
                ans[z] = 1;
            }
        }

        // y -> x
        nx = x + y;
        ny = 0;
        if (nx >= a) {
            ny = nx - a;
            nx = a;
        }
        if (check[nx][ny] == 0) {
            check[nx][ny] = 1;
            q.push(make_pair(nx, ny));
            if (nx == 0)
                ans[z] = 1;
        }
        // x -> z
        nz = x + z;
        nx = 0;
        if (nz >= c){
            nx = nz - c;
            nz = c;
        }
        if (check[nx][y] == 0) {
            check[nx][y] = 1;
            q.push(make_pair(nx, y));
            if (nx == 0)
                ans[nz] = 1;
        }

        // z -> x
        nz = 0;
        nx = x + z;
        if (nx >= a){
             nz = nx - a;
             nx = a;
        }
        if (check[nx][y] == 0) {
            check[nx][y] = 1;
            q.push(make_pair(nx, y));
            if (nx == 0)
                ans[nz] = 1;
        }
        // y -> z
        ny = 0;
        nz = y +z;
        if (nz >= c) {
            ny = nz - c;
            nz = c;
        }
        if (check[x][ny] == 0) {
            check[x][ny] = 1;
            q.push(make_pair(x, ny));
            if (x == 0)
                ans[nz] = 1;
        }

        // z -> y
        nz = 0;
        ny = y + z;
        if (ny >= b) {
            nz = ny - b;
            ny = b;
        }
        if (check[x][ny] == 0) {
            check[x][ny] = 1;
            q.push(make_pair(x, ny));
            if (x == 0)
                ans[nz] = 1;
        }
    }
}


int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    BFS(a, b, c);
    int cc =0;
    for (int i = 0 ; i <= 200 ; i++) {
        if (ans[i] == 1)
            cout << i <<' ';
    }







  return 0;
}
