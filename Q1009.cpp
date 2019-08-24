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

int mypow(int a, int b) {
    if (b == 0)
        return 1;
    else if (b == 1)
        return a % 10;
    if (b % 2 == 0) {
        int temp = mypow(a, b/2) % 10;
        return (temp * temp) % 10;
    }
    else {
        int temp = mypow(a, b-1) % 10;
        return (temp * a) %10;
    }
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int x = mypow(a, b);
        if (x == 0)
            printf("10\n");
        else
            printf("%d\n", x);
    }

















  return 0;
}
