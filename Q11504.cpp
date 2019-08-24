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
    if (b == 0 )
        return 1;
    else if (b == 1)
        return a;
    if (b % 2 == 0) {
        int temp = mypow(a, b/2);
        return temp * temp;
    }
    else {
        int temp = mypow(a, b-1);
        return temp * a;
    }
}

int testcase, a[101], n, m;
int main() {
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d", &n, &m);
        int x = 0; int y = 0;
        for (int i = 0 ; i < m ; i++) {
            int temp;
            scanf("%d", &temp);
            x += temp * mypow(10, m-1-i);
        }
        for (int i = 0 ; i < m ; i++){
            int temp;
            scanf("%d", &temp);
            y += temp * mypow(10, m-1-i);
        }
        for (int i = 0 ; i < n ; i++) {
            scanf("%d", &a[i]);
        }
        int f = 0;
        int ans = 0;
        for (int i = 0 ; i < m ; i++) {
            f += a[i] * mypow(10, m - 1 - i);
        }
        if (x <= f && f <= y) {
            ans += 1;
        }
        for (int i = 1; i < n ; i++) {
            int next = (i + m - 1) % n;
            f = (f % mypow(10, m-1)) * 10;
            f = f + a[next];
            if (x <= f && f <= y)
                ans++;
        }
        printf("%d\n", ans);
    }

















  return 0;
}
