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
int gen[20000];

void d(int n) {
    int ans = n;
    while( n > 0 ) {
        ans += n % 10;
        n = n / 10;
    }
    gen[ans] = 1;
}

int main() {
    for (int i = 1; i <= 10000 ; i++) {
        d(i);
    }
    for (int i = 1 ; i <= 10000 ; i++) {
        if (gen[i] == 0)
            printf("%d\n", i);
    }


















  return 0;
}
