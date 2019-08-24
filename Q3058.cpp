#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int main() {
    int testcase;
    scanf("%d", &testcase);
    for (int i = 0 ; i < testcase; i++) {
        int ans = inf ;
        int sum = 0;
        for (int j = 0 ; j < 7 ; j++) {
            int a;
            scanf("%d", &a);
            if (a % 2 == 0) {
                ans = min(ans, a);
                sum += a;
            }
        }
        printf("%d %d\n", sum, ans);
    }
















  return 0;
}
