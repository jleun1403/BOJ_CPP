#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>

using namespace std;
int from[10000];
int check[10000];
int dist[10000];
char how[10000];

void BFS(int n) {
    queue<int> q;
    check[n] = 1;
    dist[n] = 0;
    q.push(n);
    while (!q.empty()){
        int now = q.front();
        q.pop();
        int next = (2*now) % 10000;
        if (check[next] == 0) {
            q.push(next);
            check[next] = 1;
            from[next] = now;
            how[next] = 'D';
        }
        next = now - 1;
        if (now ==0) next = 9999;
        if (check[next] == 0) {
            q.push(next);
            check[next] = 1;
            from[next] = now;
            how[next] = 'S';
        }
        next = (now %1000) *10 + (now / 1000);
        if (check[next] == 0) {
            q.push(next);
            check[next] = 1;
            from[next] = now;
            how[next] = 'L';
        }
        next = (now / 10) + (now % 10) *1000;
        if (check[next] == 0) {
            q.push(next);
            check[next] = 1;
            from[next] = now;
            how[next] = 'R';
        }
    }
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while (testcase--) {
        int start, to;
        scanf("%d %d", &start, &to);
        memset(from, 0, sizeof(from));
        memset(check, 0, sizeof(check));
        memset(dist, 0, sizeof(dist));
        memset(how, 0, sizeof(how));
        BFS(start);
        int k = to;
        string ans = "";
        while (k != start) {
            ans = ans + how[k];
            k = from[k];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';

    }








  return 0;
}
