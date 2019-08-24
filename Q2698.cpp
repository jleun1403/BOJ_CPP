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

int d[101][100][2];

int main() {
    int testcase, n, k;
    scanf("%d", &testcase);

    d[2][1][1] = 1;
    d[2][0][0] = 2;
    d[2][0][1] = 1;
    for (int i = 3; i <= 100 ; i++) {
        for (int j = 0 ; j < i ; j++) {
            d[i][j][0] = d[i-1][j][0] + d[i-1][j][1];
            d[i][j][1] = d[i-1][j][0] + d[i-1][j-1][1];
        }
    }


    while(testcase--){
        scanf("%d %d", &n, &k);
        printf("%d\n", d[n][k][0] + d[n][k][1]);
    }

















  return 0;
}
