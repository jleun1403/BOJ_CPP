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
#define inf 1000000000

using namespace std;
int n, m;
int dist[101][101];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = inf;
        }
    }
    for (int i = 0 ; i < m ; i++)  {
        int a, b;
        scanf("%d %d", &a, &b);
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for (int k = 1; k <= n ; k++) {
        for (int i = 1 ; i<= n ;i++) {
            for (int j = 1 ; j <= n ; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    int ans = inf;
    int real;
    for (int i = 1 ; i <= n ;i++) {
        int temp = 0;
        for (int j = 1 ; j <= n ; j++) {
            temp = temp + dist[i][j];
        }
        if (ans > temp) {
            ans = temp;
            real = i;
        }
    }

    printf("%d", real);





















  return 0;
}
