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

double dist[50][51];
bool inque[50][51];
int a[50][50];
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++) {
            scanf("%1d", &a[i][j]);
        }
    }

    for (int i = 0 ; i < 50 ; i++) {
        for (int j = 0 ; j < 51 ; j++) {
            dist[i][j] = inf;
        }
    }
    memset(inque, 0, sizeof(inque));
    dist[0][0] = 0;
    inque[0][0] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(0 ,0));
    while(!q.empty()) {
        auto p = q.front();
        int cur = p.first;
        int chance = p.second;
        q.pop();
        inque[p.first][p.second] = false;
        for (int i = 0 ; i < n ; i++) {
            if (cur == i)
                continue;
            if (dist[i][chance] > dist[cur][chance] + a[cur][i]) {
                dist[i][chance] = dist[cur][chance] + a[cur][i];
                if (inque[i][chance] == false) {
                    inque[i][chance] = true;
                    q.push(make_pair(i, chance));
                }
            }
            if (chance < k) {
                if (dist[i][chance + 1] > dist[cur][chance] + (double)a[cur][i] / 2.0) {
                    dist[i][chance + 1] = dist[cur][chance] + (double)a[cur][i] / 2.0;
                    if (inque[i][chance+1] == false) {
                        inque[i][chance+1] = true;
                        q.push(make_pair(i, chance+1));
                    }
                }
            }
        }
    }
    double ans = 9.0;
    for (int i = 0 ; i < 51 ; i++) {
        ans = min(dist[1][i], ans);
    }
    printf("%lf", ans);
















  return 0;
}
