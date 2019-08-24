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
vector<int> v1;
vector<int> v2;
vector<vector<int>> v(2005);
int a[101];
int A[2005];
int B[2005];
int n;
bool visited[2005];

bool isprime(int n) {
    if (n == 2)
        return true;
    for (int i = 2; i*i <= n ; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool DFS(int n, int fix) {
    visited[n] = true;
    for (int i = 0 ; i < v[n].size() ; i++) {
        int next = v[n][i];
        if (next == fix)
            continue;
        if (B[next] == -1 || !visited[B[next]] && DFS(B[next], fix)) {
            A[n] = next;
            B[next] = n;
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0 ; i< n ;i++) {
        if (a[i] % 2)
            v2.push_back(a[i]);
        else
            v1.push_back(a[i]);
    }
    if (v1.size() != v2.size()) {
        printf("-1");
        return 0;
    }
    for (int i = 0 ; i < n/2; i++) {
        for (int j = 0 ; j < n/2; j++) {
            if (isprime(v1[i] + v2[j])) {
                v[v1[i]].push_back(v2[j]);
                v[v2[j]].push_back(v1[i]);
            }
        }
    }
    int match = 0;
    vector<int> ans;
    for (int i = 0 ; i < v[a[0]].size() ; i++) {
        match = 0;
        int fix = v[a[0]][i];
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        A[a[0]] = fix;
        B[fix] = a[0];
        for (int j = 0 ; j < 2005 ; j++) {
            if (A[j] == -1) {
                memset(visited, false, sizeof(visited));
                if (DFS(j, fix))
                    match++;
            }
        }
        if (match == n-1)
            ans.push_back(fix);
    }
    if (ans.size() == 0) {
        printf("-1");
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0 ; i < ans.size() ; i++)
        printf("%d ", ans[i]);

















  return 0;
}
