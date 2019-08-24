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


int n, k, m;
bool prime[4000005];
vector<int> isprime;

void get_prime() {
    for (int i = 2 ; i <= n ; i++)
        prime[i] = true;
    for (long long i = 2LL ; i <= n ; i++) {
        if (prime[i]) {
            isprime.push_back(i);
            for (long long j = (long long)i*i ; j <= (long long)n ; j += i)
                prime[j] = false;
        }
    }
}

long long mypow(long long a, long long b) {
    if ( b == 0LL ) {
        return 1LL;
    }
    else if ( b == 1LL)
        return (long long)a;
    else {
        if (b % 2LL == 0LL) {
            long long temp = mypow(a, b/2);
            return (temp * temp % k);
        }
        else {
            long long temp = mypow(a, b-1);
            return (long long)a * temp%k;
        }
    }
}

int main() {
    cin >> n >> m >> k;
    get_prime();
    long long ans = 1LL;
    int s = isprime.size();
    for (int i = 0 ; i < s; i++) {
        long long p = (long long)isprime[i];
        int inn = 0;
        int inm = 0;
        int innm = 0;
        for (long long j = (long long)p ; j <= n ; j = j*p) {
            inn += n / j;
        }
        for (long long j = (long long)p ; j <= m ; j = j*p) {
            inm += m / j;
        }
        for (long long j = (long long)p ; j <= n - m ; j = j*p) {
            innm += ((n-m) / j);
        }
        int temp = inn - inm - innm;
        if (temp < 0) {
            temp = 0;
        }
        ans = ans * (mypow(p, temp)) %k ;
    }
    printf("%lld", ans);

















  return 0;
}
