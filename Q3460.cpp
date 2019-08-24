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
int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            printf("0\n");
            continue;
        }
        int i = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                printf("%d ", i);
            }
            n = n >> 1;
            i++;
        }
        printf("\n");
    }
















  return 0;
}
