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
int num[101][101];
int from[101][101];



int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i<= n ;i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else
                dist[i][j] = inf;
            from[i][j] = j;
        }
    }
    memset(num, 0, sizeof(num));
    for (int i = 0 ; i < m ; i++) {
        int ffrom, to, weight;
        scanf("%d %d %d", &ffrom, &to, &weight);
        dist[ffrom][to] = min(dist[ffrom][to], weight);
        num[ffrom][to] = 1;
        from[ffrom][to] = to;
    }
    for (int k = 1 ; k <= n ; k++) {
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j<= n ; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    num[i][j] = num[i][k] + num[k][j];
                    from[i][j] = from[i][k];
                }
            }
        }
    }


    for (int i = 1 ; i<= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (dist[i][j] >= inf) {
                printf("0 ");
                num[i][j] = 0;
            }
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= n ; j++) {
            if (num[i][j] == 0) {
                printf("0\n");
            }
            else {
                printf("%d ", num[i][j] +1);
                vector<int> v;
                int k = i;
                v.push_back(i);
                while(k != j) {
                    k = from[k][j];
                    v.push_back(k);
                }
                for (int i = 0 ; i < v.size() ; i++) {
                    printf("%d ", v[i]);
                }
                cout << '\n';
            }
        }
    }
























  return 0;
}
