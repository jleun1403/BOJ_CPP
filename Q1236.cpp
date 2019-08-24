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

char a[50][50];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> a[i][j];
        }
    }
    int empty_row = 0;
    int empty_col = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (a[i][j] == 'X')
                break;
        }
        empty_row++;
    }
    for (int j = 0 ; j < m ; j++) {
        for (int i = 0 ; i < n ; i++) {
            if (a[i][j] == 'X')
                break;
        }
        empty_col++;
    }
    cout << max(empty_row, empty_col);














  return 0;
}
