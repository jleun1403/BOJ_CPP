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

int parent[50001];
vector<vector<pair<int, int>>> v(50001);
int dp[50001][16];
int dist[50001];
int qmax[50001][16];


int Find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        parent[y] = x;
        return true;
    }
    return false;
}

struct Edge {
    int x, y, weight;
    bool used;
    Edge() : Edge(0, 0, 0) {};
    Edge(int a, int b, int c) : x(a), y(b), weight(c), used(false) {}
    bool operator< (const Edge& e1) const {
        return weight < e1.weight;
    }
};
int n, m;

Edge e[200000];

int biggest(int a, int b, int cost) {
    if (b == 0) {
        if (qmax[a][b] == cost) return inf*2;
        return qmax[a][b];
    }
    if (qmax[a][b-1] == cost) {
        if (qmax[dp[a][b-1]][b-1] == cost) {
            return max(biggest(a, b-1, cost) , biggest(dp[a][b-1], b-1, cost));
        }
        else
            return qmax[dp[a][b-1]][b-1];
    }
    else
        return qmax[a][b-1];
}



int lca(int x, int y, int cost) {
    int ans = (1<<31);
    if (dist[x] < dist[y])
        swap(x, y);
    int diff = dist[x] - dist[y];
    for (int j = 0 ; diff ; j++) {
        if (diff % 2) {
            if (qmax[x][j] == cost) {
                ans = max(ans, biggest(x, j, cost));
            }
            else {
                ans = max(ans, qmax[x][j]);
            }
            x = dp[x][j];
        }
        diff /= 2;
    }
    if (x == y)
        return ans;
    for (int i = 15 ; i>= 0 ; i--) {
        if (dp[x][i] != -1 && dp[x][i] != dp[y][i]) {
            if (qmax[x][i] == cost) {
                ans = max(ans, biggest(x, i, cost));
            }
            else
                ans = max(ans, qmax[x][i]);
            if (qmax[y][i] == cost) {
                ans = max(ans, biggest(y, i, cost));
            }
            else
                ans = max(ans, qmax[y][i]);
            x = dp[x][i];
            y = dp[y][i];
        }
    }
    if (qmax[x][0] < cost) {
        ans = max(ans, qmax[x][0]);
    }
    if (qmax[y][0] < cost) {
        ans = max(ans, qmax[y][0]);
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int a, b, c;
    for (int i = 0 ; i < m ; i++) {
        cin >> a >> b >> c;
        e[i].x = a;
        e[i].y = b;
        e[i].weight = c;
        e[i].used = false;
    }
    sort(e, e+m);

    if (m <= n-1) {
        printf("-1");
        return 0;
    }

    for (int i = 1 ; i <= n ; i++) {
        parent[i] = i;
    }

    int mst = 0;
    int used_edge = 0;
    for (int i = 0 ; i < m ; i++) {
        int f = e[i].x;
        int t = e[i].y;
        if (Union(f, t)) {
            v[t].push_back(make_pair(f, e[i].weight));
            v[f].push_back(make_pair(t, e[i].weight));
            mst += e[i].weight;
            e[i].used = true;
            used_edge += 1;
        }
    }

    // doing lca
    memset(dp, -1, sizeof(dp));
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    queue<int > q;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0 ; i < v[cur].size() ; i++) {
            int next = v[cur][i].first;
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                dp[next][0] = cur;
                qmax[next][0] = v[cur][i].second;
                q.push(next);
            }
        }
    }

    int pp = Find(1);
    for (int i = 2 ; i<= n ; i++) {
        if (Find(i) != pp) {
            printf("-1");
            return 0;
        }
    }


    for (int i = 0 ; i < 15; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (dp[j][i] != -1) {
                dp[j][i+1] = dp[dp[j][i]][i];
                qmax[j][i+1] = max(qmax[j][i], qmax[dp[j][i]][i]);
            }
        }
    }

    int second_mst = (1<<31)-1;
    for (int i = 0 ; i < m ;i++) {
        if (e[i].used)
            continue;
        int f = e[i].x;
        int t = e[i].y;
        int possible = mst - lca(f, t, e[i].weight) + e[i].weight;

        if (possible == mst) {
            continue;
        }
        else if (possible < second_mst && possible > 0){
            second_mst = possible;
        }
    }
    printf("%d", second_mst == (1<<31)-1 ? -1 : second_mst);















  return 0;
}
