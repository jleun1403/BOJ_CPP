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
#define inf 987654321

using namespace std;
int n, m;
char a[50][50];
int row[50][50];
int col[50][50];
vector<vector<int>> v(5000);
int A[5000];
int B[5000];
bool visited[5000];

bool DFS(int x) {
    visited[x] = true;
    for (int i = 0 ;i < v[x].size() ; i++) {
        int next = v[x][i];
        if (B[next] == -1 || !visited[B[next]] && DFS(B[next])) {
            A[x] = next;
            B[next] = x;
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf(" %c", &a[i][j]);
        }
    }
    int cnt = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if (a[i][j] == '*') {
                if (j == 0)
                    row[i][j] = cnt++;
                else if (a[i][j-1] == '*') {
                    row[i][j] = row[i][j-1];
                }
                else
                    row[i][j] = cnt++;
            }
        }
    }
    cnt = 1;
    for (int j = 0 ; j < m ; j++) {
        for (int i = 0 ; i < n ; i++) {
            if (a[i][j] == '*') {
                if (i == 0)
                    col[i][j] = cnt++;
                else if (a[i-1][j] == '*') {
                    col[i][j] = col[i-1][j];
                }
                else
                    col[i][j] = cnt++;
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (a[i][j] == '*') {
                v[row[i][j]].push_back(col[i][j] +2500);
                v[2500 + col[i][j]].push_back(row[i][j]);
            }
        }
    }

    int match = 0;
    memset(A, -1 ,sizeof(A));
    memset(B, -1, sizeof(B));
    for (int i = 1 ; i < 101 ; i++) {
        if (A[i] == -1) {
            memset(visited, false, sizeof(visited));
            if (DFS(i)) {
                match++;
            }
        }
    }
    printf("%d", match);















  return 0;
}
