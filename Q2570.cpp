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
int n, m;
int a[101][101];
int row[101][101];
int col[101][101];
vector<vector<int>> v(10001);

bool DFS(int x, vector<bool> &visited, vector<int> &A, vector<int> &B) {
    visited[x] = true;
    for (int i = 0 ; i < v[x].size() ; i++) {
        int next = v[x][i];
        if (B[next] == -1 || !visited[B[next]] && DFS(B[next], visited, A, B)) {
            A[x] = next;
            B[next] = x;
            return true;
        }
    }
    return false;
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < m ;i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        a[r][c] = 1;
    }
    int rownum = 1;
    int colnum = 1;
    for (int i = 1; i <= n ; i++) {
        for (int j = 1 ; j <= i; j++) {
            int r = i+1-j;
            if (a[r][j] == 1)
                continue;
            else {
                if (j == 1 || a[r+1][j-1] == 1)
                    row[r][j] = rownum++;
                else
                    row[r][j] = row[r+1][j-1];
            }
        }
    }
    for (int j = 2 ;  j <= n ; j++) {
        for (int k = n ; k >= j; k--) {
            int c = n+j-k;
            if (a[k][c] == 1)
                continue;
            else {
                if (k == n || a[k+1][c-1] == 1)
                    row[k][c] = rownum++;
                else
                    row[k][c] = row[k+1][c-1];
            }
        }
    }
    for (int i = 1; i <= n ; i++) {
        for (int j = n ; j > (n-i) ; j--) {
            int r = i+j-n;
            if (a[r][j] == 1)
                continue;
            else {
                if (j == n || a[r+1][j+1] == 1)
                    col[r][j] = colnum++;
                else
                    col[r][j] = col[r+1][j+1];
            }
        }
    }
    for (int j = n-1 ; j >= 1; j--) {
        for (int i = n ; i > n-j ; i--) {
            int c = i+j-n;
            if (a[i][c] == 1)
                continue;
            else {
                if (i == n || a[i+1][c+1] == 1)
                    col[i][c] = colnum++;
                else
                    col[i][c] = col[i+1][c+1];
            }
        }
    }

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (a[i][j] == 0) {
                v[row[i][j]].push_back(col[i][j]);
            }
        }
    }
    vector<int> A(rownum, -1);
    vector<int> B(colnum, -1);
    int match = 0;
    for (int i = 1 ; i<= rownum ; i++) {
        if (A[i] == -1) {
            vector<bool> visited(rownum, false);
            if (DFS(i, visited, A, B))
                match++;
        }
    }
    printf("%d", match);




















  return 0;
}
