#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int d[100][100];
int v[100][100];
int n;

//
void DFS(int x, int y, int cnt){
    d[x][y] = cnt;
    for (int i = 0 ; i < 4 ; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if (d[nx][ny] == 0 && v[nx][ny] == 1)
                DFS(nx, ny, cnt);
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    int c = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (v[i][j] == 1 && d[i][j] == 0)
                DFS(i, j, c++);
        }
    }
    if (c < 3){
        cout << "0";
        return 0;
    }
    int minimum = 100000;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <n ; j++) {
            if (v[i][j] == 1) {
                for (int k = 0 ; k < n ; k++) {
                    for (int l = 0 ; l < n ; l++) {
                        if (v[k][l] == 1 && (d[i][j] != d[k][l])){
                            if (abs(i - k) + abs(j - l) < minimum) {
                                minimum = abs(i - k) + abs(j - l);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << minimum - 1;

    return 0;


}
