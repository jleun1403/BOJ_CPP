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

bool isPrime[300001];

void seize() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for (int i = 2; i*i <= 300000 ; i++) {
        if (isPrime[i] == false)
            continue;

            for (long long j = (long long)i*i ; j < 300000LL ; j += i)
                isPrime[j] = false;
    }
}

int main() {
    seize();
    while(true) {
        int n;
        int ans = 0;
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = n+1 ; i<= 2*n ; i++) {
            if (isPrime[i])
                ans++;
        }
        printf("%d\n", ans);
    }

















  return 0;
}
