#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <bitset>
#include <cstring>
#define inf 987654321

using namespace std;

long long mypow(int a, int b) {
    if (b == 0)
        return 1LL;
    if (b == 1)
        return (long long)a;
    if (b % 2 == 0) {
        long long temp = mypow(a, b/2);
        return temp * temp;
    }
    else {
        long long temp = mypow(a, b-1);
        return temp*a;
    }
}

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    string s = to_string(n);
    long long length = 0;
    for (int i = 1 ; i < s.length() ; i++) {
        length += mypow(10, i-1) * 9 * i;
    }
    for (int i = mypow(10, s.length()-1) ; i <= n ; i++) {
        length += s.length();
    }
    if (length < k) {
        printf("-1");
        return 0;
    }

    int digit = 0;
    while(true) {
        k -= mypow(10, digit) * 9LL*(long long)(digit +1);
        if (k < 0) {
            k += mypow(10, digit) * 9LL * (long long)(digit+1);
            break;
        }
        digit++;
    }
    digit += 1;
    int start = mypow(10, digit-1);
    while(true) {
        k -= digit;
        if (k <= 0) {
            k += digit;
            break;
        }
        start++;
    }
    printf("%c", to_string(start)[k-1]);















  return 0;
}
