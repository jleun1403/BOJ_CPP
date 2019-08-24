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
int testcase, n, m;
char a[80][80];
vector<vector<int>> v;
int dx[6] = {-1, 0, -1, 0, 1, 1};
int dy[6] = {-1, -1, 1, 1, 1, -1};
int A[3200];
int B[3200];
bool visited[3200];

bool DFS(int x) {
    visited[x] = true;
    for (int i = 0 ; i < v[x].size() ; i++) {
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
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d", &n, &m);
        v.resize(3200);
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                scanf(" %c", &a[i][j]);
            }
        }
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                if (a[i][j] == 'x')
                    continue;
                for (int k = 0 ; k < 6 ; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                        {
                            int id = nx*m + ny;
                            if (j % 2 == 1 && ny % 2 == 0) {
                                v[i*m + j+1600].push_back(id);
                                v[id].push_back(i*m + j+1600);
                            }
                            else {
                                v[i*m + j].push_back(id + 1600);
                                v[id+1600].push_back(i*m + j);
                            }
                        }
                    }
                }
            }
        }
        int match = 0;
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        for (int i = 0 ; i < 3200 ; i++) {
            if(A[i] == -1) {
                memset(visited, false, sizeof(visited));
                if (DFS(i))
                    match++;
            }
        }
        printf("%d\n", match);
        v.clear();
        memset(a, -1, sizeof(a));


    }

















  return 0;
}
