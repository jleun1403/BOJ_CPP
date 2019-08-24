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

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 5 ; i <= n ; i = i*5) {
        ans += (n / i);
    }
    printf("%d", ans);

















  return 0;
}
