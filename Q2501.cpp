#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n ; i++) {
        if (n % i == 0) {
            k--;
            if (k == 0) {
                printf("%d", i);
                return 0;
            }
        }
    }
    printf("0");
















  return 0;
}
