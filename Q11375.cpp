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
int A[2002];
int B[2002];
vector<vector<int>> v(2002);
bool visited[2002];
int match;

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
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0 ; j < k ; j++) {
            int job;
            scanf("%d", &job);
            job += 1000;
            v[i].push_back(job);
            v[job].push_back(i);
        }
    }
    match = 0;
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    for (int i = 1 ; i <= n ; i++) {
        if (A[i] == -1) {
            memset(visited, false, sizeof(visited));
            if(DFS(i))
                match++;
        }
    }
    printf("%d", match);
















  return 0;
}
