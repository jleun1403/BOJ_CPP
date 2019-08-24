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
int n, k;
vector<vector<int>> v(1000);
int A[1000];
int B[1000];
bool visited[1000];

bool DFS(int x) {
    visited[x] = true;
    for (int i = 0 ; i <v[x].size() ; i++) {
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
    scanf("%d %d", &n, &k);
    for (int t = 0 ; t < k ; t++) {
        int i, j;
        scanf("%d %d", &i, &j);
        i -= 1; j -=1;
        j += n;
        v[i].push_back(j);
        v[j].push_back(i);
    }

    int match = 0;
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    for (int i = 0 ; i < n ;i++) {
        if (A[i] == -1) {
            memset(visited, false, sizeof(visited));
            if (DFS(i))
                match++;
        }
    }
    printf("%d", match);
















  return 0;
}
