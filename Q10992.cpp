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
    for (int i = 1 ; i <= n ; i++) {
        if ( i == n ) {
            for (int j = 0 ; j < 2*i-1 ; j++)
                printf("*");
        }
        else {
            for (int j = 0 ; j < (n - i) ; j++)
                printf(" ");
            printf("*");
            if (i == 1) {
                printf("\n");
                continue;
            }
            for (int j = 0 ; j < 2*i - 3 ; j++)
                printf(" ");
            if ( i != 1)
                printf("*\n");
        }
    }

















  return 0;
}
