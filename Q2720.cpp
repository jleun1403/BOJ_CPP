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
        int n;
        scanf("%d", &n);
        int a, b, c, d;
        a = b = c = d = 0;
        while(n >= 25) {
            n -= 25;
            a++;
        }
        while (n >= 10) {
            n -= 10;
            b++;
        }
        while (n >= 5) {
            n -= 5;
            c++;
        }
        while (n >= 1) {
            n -= 1;
            d++;
        }
        printf("%d %d %d %d\n", a, b, c, d);
    }
















  return 0;
}
