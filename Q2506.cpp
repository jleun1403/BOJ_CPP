#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int a[101];
int score[101];

int main() {
    int n;
    scanf("%d", &n);

    int ans = 0;
    for (int i = 1 ;i <= n ;i++ ) {
        scanf("%d", &a[i]);
        if (a[i] == 0) {
            score[i] = 0;
        }
        else {
            score[i] = score[i-1] + 1;
            ans += score[i];
        }

    }
    printf("%d\n", ans);















  return 0;
}
