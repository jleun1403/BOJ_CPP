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

using namespace std;
int n;
vector<vector<int>> v;
int in[10001];
int a[10001];
int d[10001];

void topsort(){
    queue<int> q;
    for (int i = 1 ; i <= n ; i++) {
        if (in[i] == 0) {
            q.push(i);
            d[i] = a[i];
        }
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0 ; i < v[x].size(); i++) {
            in[v[x][i]] -= 1;
            if (d[v[x][i]] < d[x] + a[v[x][i]])
                d[v[x][i]] = d[x] + a[v[x][i]];
            if (in[v[x][i]] == 0) {
                q.push(v[x][i]);
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    v.resize(n+1);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
        int next;
        scanf("%d", &next);
        in[i] = next;
        for (int j = 0 ; j < next ; j++) {
            int k;
            scanf("%d", &k);
            v[k].push_back(i);
        }
    }
    topsort();
    int ans = d[1];
    for (int i = 1 ; i <= n ; i++) {
        if (d[i] > ans)
            ans = d[i];
    }
    cout << ans;








  return 0;
}
