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
int main() {
    scanf("%d", &n);
    if (n < 100) {
        printf("%d", n);
        return 0;
    }
    int cnt = 0;
    for (int i = 100 ; i <= n ; i++) {
        int a = i / 100;
        int b = (i - (a*100)) / 10;
        int c = i % 10;
        if (a +c == b * 2)
            cnt++;
    }

    printf("%d", 99 + cnt);
















  return 0;
}
