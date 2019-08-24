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
long long a[1000001];

int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        cout << 0;
        return 0;
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }
    if ( n == 2) {
        cout << 1;
        return 0;
    }
    a[1] = 1LL;
    a[2] = 1LL;
    for (long long i = 3 ; i<= 1,000,000,000,000,000,000; i++) {
        a[i] = (a[i-1] + a[i-2]) % 1000000LL;
    }
    cout << a[n]%1000000LL;







  return 0;
}
