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
#define mod 1000000007

using namespace std;
long long fact[4000000];

int main() {
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= 4000000 ; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", (fact[n] / (fact[n-k] *fact[k])) % mod);








  return 0;
}
