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

int gen(int n) {
    int ans = n;
    while ( n > 0) {
        ans += n % 10;
        n = n / 10;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1 ; i < n ; i++) {
        if (gen(i) == n) {
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
















  return 0;
}
