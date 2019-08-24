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
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        int a, b, x, c, d, y;
        scanf("%d %d %d %d %d %d", &a, &b, &x, &c, &d, &y);
        if (a == c && b == d ) {
            if (x == y)
                printf("-1\n");
            else
                printf("0\n");
        }
        else {
            int dist = (c-a)*(c-a) + (b-d)*(b-d);
            int q = (x+y)*(x+y);
            int q2= (x-y)*(x-y);
            if (dist < q && dist > q2)
                printf("2\n");
            else if (dist == q || dist == q2)
                printf("1\n");
            else
                printf("0\n");
        }
    }
















  return 0;
}
