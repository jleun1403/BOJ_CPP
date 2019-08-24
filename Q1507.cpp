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
int dist[21][21];
int unuse[21][21];

int main() {
    scanf("%d", &n);
    for (int i = 1; i<= n ; i++) {
        for (int j = 1; j <= n ; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int k = 1; k <= n ; k++) {
        for (int i = 1; i <= n ; i++) {
            for (int j = 1 ; j <=n ; j++) {
                if (i == k || k == j || j == i)
                    continue;
                if (dist[i][j] == dist[i][k] + dist[k][j])
                    unuse[i][j] = 1;
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    int sum = 0;
    for (int i =1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (unuse[i][j] == 0)
                sum += dist[i][j];
        }
    }
    cout << sum / 2;
















  return 0;
}
