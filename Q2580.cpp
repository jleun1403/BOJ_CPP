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
int a[9][9];
int ans;

bool row(int x, int y, int t) {
    for (int i = 0 ; i < 9 ; i++){
        if (a[x][i] == t)
            return false;
    }
    return true;
}
bool col(int x, int y, int t) {
    for (int i = 0 ; i < 9 ; i++) {
        if (a[i][y] == t)
            return false;
    }
    return true;
}
bool small(int x, int y, int t) {
    for (int i = x / 3 * 3 ; i < x / 3  * 3+ 3 ; i++) {
        for (int j = y / 3 * 3 ; j < y / 3 * 3 + 3; j++) {
            if (a[i][j] == t)
                return false;
        }
    }
    return true;
}
void print(int arr[9][9] , int s) {
    for (int i = 0 ; i < s; i++) {
        for (int j = 0 ; j < s; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void sudoku(int x, int y) {
    if (x == 9 && y == 0) {
        ans++;
        return;
    }
    if (a[x][y] == 0) {
        for (int t = 1 ; t <= 9 ; t++) {
            if (row(x, y, t) && col(x, y, t) && small(x, y ,t)) {
                a[x][y] = t;
                if (y == 8) {
                    sudoku(x + 1, 0);
                }
                else
                    sudoku(x, y+1);
            }
        }
        a[x][y] = 0;
    }
    else {
       if (y == 8) {
            sudoku(x + 1, 0);
        }
        else
            sudoku(x, y+1);
    }

}


int main() {
    ans = 0;
    for (int i = 0 ; i < 9 ; i++) {
        for (int j = 0 ; j < 9 ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    sudoku(0, 0);
    cout <<ans <<endl;







  return 0;
}
