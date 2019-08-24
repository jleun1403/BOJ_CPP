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
int n;
int c[100001];
int sum;

bool possible(long long x) {
    long long add = 0;
    for (int i = 1; i <= n ; i++) {
        if (c[i] <= x)
            add += c[i];
        else
            add += x;
    }
    return (add <= sum);
}

int main() {
    scanf("%d", &n);
    int maxc = 0;
    int tempsum = 0;
    for (int i = 1 ; i <= n ; i++) {
        scanf("%d", &c[i]);
        tempsum += c[i];
        if (c[i] > maxc)
            maxc = c[i];
    }
    scanf("%d", &sum);
    if (tempsum <= sum) {
        printf("%d", maxc);
        return 0;
    }
    long long left = 0;
    long long right = 1000000000;
    long long ans;
    while(left <= right) {
        long long mid = (left +right) / 2;
        if(possible(mid)) {
            left = mid +1;
            ans = mid;
        }
        else
            right = mid - 1;
    }

    printf("%lld", ans);



  return 0;
}
