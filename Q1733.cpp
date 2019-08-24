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

vector<vector<int>> v(1000001);
int A[1000001];
int B[1000001];
bool visited[1000001];

bool DFS(int a) {
    visited[a] = true;
    for (int i = 0 ; i < v[a].size(); i++) {
        int next = v[a][i];
        if (B[next] == -1  || !visited[B[next]] && DFS(B[next])) {
            A[a] = next;
            B[next] = a;
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[i].push_back(b);
        v[i].push_back(a);
    }

    int match = 0;
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    for (int i = 1 ; i <= n ; i++) {
        memset(visited, false, sizeof(visited));
        if (A[i] == -1) {
            DFS(i);
            match++;
        }
    }
    if (match == n) {
        for (int i = 1; i <= n ;i++) {
            printf("%d\n", A[i]);
        }
    }
    else {
        printf("-1");
    }
















  return 0;
}
