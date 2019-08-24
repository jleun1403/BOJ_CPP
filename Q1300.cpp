#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int n, k;
map<int , int> m;
bool isprime(int p) {
    if (p == 0) return false;
    if (p == 1) return false;
    for (int i = 2; i <= sqrt(p) ; i++) {
        if (p % i == 0)
            return false;
    }
    return true;
}

int kth(int p) {
    if (m[p] != 0)
        return m[p];
    int sum = 0;
    for (int i = 1 ; i <= n ; i++) {
        sum += min(p / i, n);
    }
    return m[p] = sum;
}

int main() {
    scanf("%d %d", &n, &k);
    int left = 1LL;
    int right = (int)min((long long)n*n, 1000000000LL);

    while(left < right) {
        int mid = (left + right) / 2;
        if (kth(mid) < k) {
            left = mid;
        }
        else {
            right = mid;
        }
        if (right == left +1)
            break;
    }
    if (kth(left) < k)
        printf("%d", right);
    else
        printf("%d", left);















  return 0;
}
