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
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int round;
    for (round = 1 ; round <= n ; round++) {
        int die;
        if (m % (n - round +1) == 0)
            die = n - round + 1;
        else
            die = m % (n - round + 1);
        if (k == die || n == round) {
            break;
        }
        if (k > die) {
            k = k - die;
        }
        else {
            k = n - round + 1 + k - die;
        }
    }
    printf("%d", round);















  return 0;
}
