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
char c[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;
int surround(int x, int y) {
    int cnt = 0;
    for (int i = 0 ; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0<= ny && ny < n){
            if (c[nx][ny] == '#')
                cnt++;
        }
    }
    return cnt;
}

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i <n ;i++){
        scanf(" %1c", &c[0][i]);
    }
    for (int i = 0 ; i < n-1 ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (surround(i, j) % 2 == 1){
                c[i+1][j] = '#';
            }
            else
                c[i+1][j] = '.';
        }
    }
    for (int i = 0 ; i <n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            printf("%c", c[i][j]);
        }
        printf("\n");
    }







  return 0;
}
