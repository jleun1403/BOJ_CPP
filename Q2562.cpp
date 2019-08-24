#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int main() {
    int ans, index;
    ans = 0;
    for (int i = 1 ; i <= 9 ; i++) {
        int a;
        scanf("%d", &a);
        if (a > ans) {
            ans = a;
            index = i;
        }
    }
    printf("%d\n%d", ans, index);
















  return 0;
}
