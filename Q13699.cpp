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
long long d[36];
int main() {
    int n;
    scanf("%d", &n);
    d[0] = 1LL;
    d[1] = 1LL;
    for (int i = 2; i <= 35 ; i++) {
        long long sum = 0;
        for (int j = 0 ; j <= i-1 ; j++) {
            sum += d[j]*d[i-1-j];
        }
        d[i] = sum;
    }
    printf("%lld", d[n]);
















  return 0;
}
