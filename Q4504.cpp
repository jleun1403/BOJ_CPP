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
int n;
vector<int> v;
int main() {
    scanf("%d", &n);
    int x;
    scanf("%d", &x);
    if (x == 0)
        return 0;
    while (x != 0) {
        if (x % n == 0) {
            printf("%d is a multiple of %d.\n", x, n);
        }
        else
            printf("%d is NOT a multiple of %d.\n", x, n);
        scanf("%d", &x);
    }

















  return 0;
}
