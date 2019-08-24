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

int main() {
    int n;
    scanf("%d", &n);
    bitset<31> b;
    b.reset();
    int l;
    for (int i = 30; i >= 0 ; i--) {
        if ((1<<i) & n) {
            l = i;
            break;
        }
    }
    for (int i = 0 ; i <= l ; i++) {
        if (n&(1<<i)) {
            b.set(l-i);
        }
    }
    printf("%d", (int)b.to_ulong());















  return 0;
}
