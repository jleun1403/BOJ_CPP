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
long long a[31];
int n;

int main() {
    scanf("%d", &n);
    a[1] = 1LL;
    a[2] = 3LL;
    if ( n == 1)
    {
        cout << 1;
        return 0;
    }
    else if (n == 2) {
        cout << 3;
        return 0;
    }
    for (int i = 3 ; i<= n ;i++)
        a[i] = a[i-1] + a[i-2] * 2LL;
    long long b;
    if (n % 2 == 1)
        b = a[(n-1) / 2];
    else
        b = a[(n-2) / 2] + a[(n-2) / 2] + a[n / 2];
    printf("%lld", (a[n] + b) / 2);






  return 0;
}
