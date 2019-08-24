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
int a[101];
int d[10001][2];


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1 ; i <= 10000 ; i++)
        d[i][1] = 987654321;

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1; j <= k ; j++) {
            if (j - a[i] >= 0){
                d[j][0] += d[j-a[i]][0];
                if (d[j-a[i]][1] + 1 < d[j][1])
                    d[j][1] = d[j-a[i]][1] + 1;
            }
        }
    }
    if (d[k][1] == 987654321)
        cout << "-1";
    else
        cout << d[k][1];







  return 0;
}
