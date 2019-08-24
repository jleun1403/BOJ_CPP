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

struct shark {
    int a;
    int b;
    int c;
    shark(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {};
    shark() : shark(0 ,0, 0) {};
    bool operator== (shark &other) {
        if (a == other.a && b == other.b && c == other.c)
            return true;
        return false;
    }
    bool operator >(shark &other) {
        if (a >= other.a && b >= other.b && c>= other.c)
            return true;
        return false;
    }
};
shark v[2002];
int n;
int c[2002][2002];
int f[2002][2002];
int pre[2002];
vector<vector<int>> connected(2002);

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ;i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[i] = shark(a, b, c);
        v[1000+i] = shark(a, b, c);
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1001 ; j <= 1000 + n ; j++) {
            if (i + 1000 == j)
                continue;
            if (v[i] == v[j]) {
                if (i + 1000 < j) {
                    c[i][j] = 1;
                    connected[i].push_back(j);
                    connected[j].push_back(i);
                }
            }
            else if (v[i] > v[j]) {
                c[i][j] = 1;
                connected[i].push_back(j);
                connected[j].push_back(i);
            }
        }
        c[0][i] = 2;
        connected[0].push_back(i);
        connected[i].push_back(0);
    }
    for (int j = 1001; j <= 1000 + n ; j++) {
        connected[j].push_back(2001);
        connected[2001].push_back(j);
        c[j][2001] = 1;
    }
    int ans = 0;
    while (true) {
        memset(pre, -1, sizeof(pre));
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0 ; i < connected[cur].size() ; i++) {
                int next = connected[cur][i];
                if (pre[next] == -1 && c[cur][next] > f[cur][next]) {
                    pre[next] = cur;
                    q.push(next);
                    if (next == 2001)
                        break;
                }
            }
        }
        if (pre[2001] == -1)
            break;
        for (int i = 2001; i != 0 ; i = pre[i]) {
            f[pre[i]][i] += 1;
            f[i][pre[i]] -= 1;
        }
        ans++;
    }
    printf("%d", n - ans);

















  return 0;
}
