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

int main() {
    int n;
    scanf("%d", &n);
    n = 1000 - n;
    int a[6] = {500, 100, 50, 10, 5, 1};
    int ans = 0;
    while (n > 0) {
        for (int i = 0 ; i < 6 ; i++) {
            if (n >= a[i]) {
                n = n - a[i];
                ans++;
                break;
            }
        }
    }
    printf("%d", ans);

















  return 0;
}
