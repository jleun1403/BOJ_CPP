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
long long n, m;
long long dist[101][101];


int main() {
    scanf("%lld %lld", &n, &m);
    for (long long i = 1 ; i<= n ;i++) {
        for (long long j = 1 ; j <= n ; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = inf;
        }
    }
    for (long long i = 0 ; i < m ; i++) {
        long long from, to, weight;
        scanf("%lld %lld %lld", &from, &to, &weight);
        dist[from][to] = min(dist[from][to], weight);
    }
    for (long long k = 1 ; k <= n ; k++) {
        for (long long i = 1 ; i <= n ; i++) {
            for (long long j = 1 ; j<= n ; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }


    for (long long i = 1 ; i<= n ; i++) {
        for (long long j = 1 ; j <= n ; j++) {
            printf("%lld ", dist[i][j] == inf ? 0 : dist[i][j]);
        }
        printf("\n");
    }























  return 0;
}
