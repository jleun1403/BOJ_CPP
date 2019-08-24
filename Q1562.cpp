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
long long d[101][10][1<<10];

int main() {

    for (int i = 1 ; i < 10 ; i++) {
        d[1][i][1<<i] = 1LL;
    }
    for (int i = 1; i < 100 ; i++) {
        for (int s = 1 ; s < 1024 ; s++) {
            for (int j = 0 ; j < 10 ; j++) {
                if (d[i][j][s] != 0) {
                    if (j == 0) {
                        d[i+1][1][s|1] += d[i][j][s];
                        d[i+1][1][s|1] %= 1000000000LL;
                    }
                    else if (j == 9) {
                        d[i+1][8][s|(1<<8)] += d[i][j][s];
                        d[i+1][8][s|(1<<8)] %= 1000000000LL;
                    }
                    else {
                        d[i+1][j+1][s|(1<<(j+1))] += d[i][j][s];
                        d[i+1][j-1][s|(1<<(j-1))] += d[i][j][s];
                        d[i+1][j+1][s|(1<<(j+1))] %= 1000000000LL;
                        d[i+1][j-1][s|(1<<(j-1))] %= 1000000000LL;
                    }
                }
            }
        }
    }
    int n;
    scanf("%d", &n);
    long long ans = 0LL;
    for (int i = 0 ; i < 10 ; i++) {
        ans += d[n][i][1023] % 1000000000LL;
    }
    ans %= 1000000000LL;
    printf("%d", ans);


















  return 0;
}
