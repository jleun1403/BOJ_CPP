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
int n, m;
int in[32001];
vector<vector<int>> v;

void topsort(){
    queue<int> q;
    for (int i = 1 ; i <= n ; i++) {
        if (in[i] == 0)
            q.push(i);
    }
    while(!q.empty()) {
        int x = q.front();
        printf("%d ", x);
        q.pop();
        for (int i = 0 ; i < v[x].size() ; i++) {
            in[v[x][i]] -= 1;
            if (in[v[x][i]] == 0)
                q.push(v[x][i]);
        }
    }

}

int main() {
    scanf("%d %d", &n, &m);
    v.resize(n+1);
    for (int i = 0 ; i < m ; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        v[from].push_back(to);
        in[to]++;
    }
    topsort();








  return 0;
}
