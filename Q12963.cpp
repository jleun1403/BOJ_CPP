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
#define MOD 1000000007

using namespace std;
bool visited[2002];

vector<vector<int>> v(2002);
int n, m;
vector<tuple<int, int, int>> p;

bool DFS(int x) {
    visited[x] = true;
    for (int i = 0 ; i< v[x].size() ; i++) {
        int next = v[x][i];
        if (visited[next] == false) {
            visited[next] = true;
            DFS(next);
        }
    }
    return visited[n-1];
}

long long mypow(int a, int b) {
    if (b == 0)
        return 1LL;
    else if ( b == 1)
        return a;
    else if ( b % 2 ==0) {
        long long temp = mypow(a, b/2) % MOD;
        return (temp*temp) % MOD;
    }
    else {
        long long temp = mypow(a, b-1) %MOD;
        return (temp * a) % MOD;
    }
}


int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0 ; i < m ; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        p.push_back(make_tuple(from, to, i));
    }
    long long ans = 0LL;
    for (int i = m-1 ; i >= 0 ; i--) {
        int f = get<0>(p[i]);
        int t = get<1>(p[i]);
        int w = get<2>(p[i]);
        v[f].push_back(t);
        v[t].push_back(f);
        memset(visited, false, sizeof(visited));
        if (DFS(0)) {
            v[f].pop_back();
            v[t].pop_back();
            ans += mypow(3, w);
        }
    }

    printf("%lld", ans % MOD);
















  return 0;
}
