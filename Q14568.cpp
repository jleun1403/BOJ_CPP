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

int a,b,c,n, ans;

int main() {
    ans = 0;
    scanf("%d", &n);
    for (int a = 2 ; a < n ; a+=2) {
        for (int b = 1 ; b < n ; b++) {
            for (int c = b+2; c < n ; c++) {
                if (a+b+c == n)
                    ans++;
            }
        }
    }
    printf("%d", ans);















  return 0;
}
