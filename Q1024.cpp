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

int main() {
    long long n, l;
    scanf("%lld %lld", &n, &l);
    long long sum ;
    if (l > 100) {
        printf("-1");
        return 0;
    }
    for (int i = l ; i <= 100 ; i++) {
        int start = n / i - i-i;
        sum = 0LL;
        for (int k = start; k < start + i+i+i ; k++) {
            sum = 0LL;
            if (k < 0)
                continue;
            for (int j = k; j < k+i; j++) {
                sum += (long long)j;
            }
            if (sum == n) {
                for (int j = k ; j < k+i ; j++) {
                    printf("%d ", j);
                }
                return 0;
            }
                if (sum > n)
                    break;
        }

    }
    printf("-1");















  return 0;
}
