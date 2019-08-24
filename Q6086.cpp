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
int c[52][52];
int f[52][52];


int CtoI(char c) {
    if (c <= 90)
        return c - 'A';
    else
        return c - 'a' + 26;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> v;
    v.resize(52);
    for (int i = 0 ; i < n ;i++) {
        char from, to;
        int capacity;
        scanf(" %c %c %d", &from, &to, &capacity);
        int a = CtoI(from);
        int b = CtoI(to);
        v[a].push_back(b);
        v[b].push_back(a);
        c[a][b] += capacity;
    }
    int source = CtoI('A');
    int sink = CtoI('Z');
    int ans = 0;
    while(true) {
        int prev[52];
        memset(prev, -1, sizeof(prev));
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int i = 0 ; i < v[cur].size() ; i++) {
                int next = v[cur][i];
                if (f[cur][next] < c[cur][next] && prev[next] == -1) {
                    prev[next] = cur;
                    q.push(next);
                    if (next == sink)
                        break;
                }
            }
        }
        if (prev[sink] == -1)
            break;
        int flow = inf;
        for (int i = sink ; i != source ; i = prev[i]) {
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        }
        for (int i = sink ; i != source ; i = prev[i]) {
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        ans += flow;
    }
    printf("%d", ans);
















  return 0;
}
