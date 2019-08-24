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
int a[101][101];
int b[101][101];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            a[i][j] += b[i][j];
            cout << a[i][j] <<' ';
        }
        cout << '\n';
    }






  return 0;
}
