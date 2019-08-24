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
int dd[101][101];

int main() {
    int a, b, c, d;
    for (int i = 0 ; i < 4; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int k = a ; k < c; k++) {
            for (int l = b ; l < d; l++) {
                dd[k][l] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0 ; i <= 100 ; i++) {
        for (int j = 0 ; j <= 100 ; j++) {
            if (dd[i][j] == 1)
                ans++;
        }
    }
    printf("%d", ans);















  return 0;
}
