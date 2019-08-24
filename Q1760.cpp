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

int a[101][101];
int row[101][101];
int col[101][101];
int n, m;
vector<vector<int>> v(10001);

bool DFS(int x, vector<bool> &visited, vector<int> &A, vector<int> &B) {
    visited[x] = true;
    for (int i = 0 ; i < v[x].size();  i++){
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
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int rownum = 1;
    int colnum = 1;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j<= m ; j++) {
            if (a[i][j] == 2)
                continue;
            else {
                if (a[i][j-1] != 2 && j != 1)
                    row[i][j] = row[i][j-1];
                else
                    row[i][j] = rownum++;
            }
        }

    }

    for (int i = 1 ; i <= m ; i++) {
        for (int j = 1 ; j<= n ; j++) {
            if (a[j][i] == 2)
                continue;
            else {
                if (a[j-1][i] != 2 && j != 1)
                    col[j][i] = col[j-1][i];
                else
                    col[j][i] = colnum++;
            }
        }

    }


    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= m ; j++) {
            if (a[i][j] == 0) {
                v[row[i][j]].push_back(col[i][j]);
            }
        }
    }
    vector<int> A(rownum, -1);
    vector<int> B(colnum, -1);
    int match = 0;
    for (int i = 1; i <= rownum ; i++) {
        if (A[i] == -1) {
            vector<bool> visited(rownum, false);
            if (DFS(i, visited, A, B)) {
                match++;
            }
        }
    }
    printf("%d", match);
















    return 0;
}
