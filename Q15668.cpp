#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int c[10];

bool check(int x) {
    while(x > 0) {
        if (c[x%10]) return false;
        c[x%10] = 1;
        x /= 10;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1 ; i <=n ; i++) {
        int x = n - i;
        if (i > x || i > 1000000) {
            printf("-1");
            return 0;
        }
        if (check(i) && check(x)){
            printf("%d + %d", i, x);
            return 0;
        }
        memset(c, 0, sizeof(c));
    }
















  return 0;
}
