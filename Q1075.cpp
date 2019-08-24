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
int n, f;
int main() {
    scanf("%d %d", &n, &f);
    int temp = n;
    n = (temp / 100) * 100;
    for (int i = 0 ; i < 100 ; i++) {
        if ((n +i) % f == 0) {
            if ( i < 10) {
                printf("0%d", i);
                return 0;
            }
            printf("%d", i);
            return 0;
        }
    }
















  return 0;
}
