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
long long d[65][10];
int main() {
    for (int i = 0 ; i < 10 ; i++) {
        d[1][i] = 1LL;
    }
    for (int i = 2; i < 65 ; i++) {
        for (int j = 0 ; j < 10 ; j++) {
            long long sum = 0LL;
            for (int k = 0 ; k <= j ; k++) {
                sum += d[i-1][k];
            }
            d[i][j] = sum;
        }
    }
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        int n;
        scanf("%d", &n);
        long long ans = 0;
        for (int i = 0 ; i < 10 ; i++) {
            ans += d[n][i];
        }
        printf("%lld\n", ans);
    }
















  return 0;
}
