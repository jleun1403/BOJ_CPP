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
vector<vector<int>> v(201);
int A[201];
int B[201];
bool visited[201];

bool DFS(int a) {
    visited[a] = true;
    for (int i = 0 ; i < v[a].size() ; i++) {
        int next = v[a][i];
        if (next == 0)
            continue;
        if (B[next] == -1 || !visited[B[next]] && DFS(B[next])) {
            A[a] = next;
            B[next] = a;
            return true;
        }
    }
    return false;
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1; j <= n ; j++) {
            v[i].push_back(j);
        }
    }
    for (int i = 0 ; i < m ; i++) {
        int task, x, y, u;
        scanf("%d %d %d %d", &task, &x, &y, &u);
        if (task == 1) {
            for (int left = x ; left <= y ; left++) {
                for (int right = u+1; right <= n ; right++) {
                    v[left][right-1] = 0;
                }
            }
            for (int in = 1 ; in < x ; in ++) {
                v[in][u-1] = 0;
            }
            for (int in = y + 1; in <= n ; in++) {
                v[in][u-1] = 0;
            }
        }
        else if (task == 2) {
            for (int left = x; left <= y ; left++){
                for (int right = 0 ; right < u-1; right++) {
                    v[left][right] = 0;
                }
            }
            for (int in = 1 ; in < x ; in ++) {
                v[in][u-1] = 0;
            }
            for (int in = y + 1; in <= n ; in++) {
                v[in][u-1] = 0;
            }

        }
    }


    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    int match = 0;
    for (int i = 1 ; i <= n ; i++) {
        if (A[i] == -1) {
            memset(visited, false, sizeof(visited));
            if (DFS(i))
                match++;
        }
    }
    if (match == n) {
        for (int i = 1 ; i<= n ; i++)
            printf("%d ", A[i]);
    }
    else {
        printf("-1");
    }
















  return 0;
}
