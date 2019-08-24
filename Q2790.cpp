#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int a[300000];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int one = 0;
    for (int i = 0 ; i < n ; i++) {
        int p = a[i] +(n - i);
        one = max(one, p);
    }
    int ans = 0 ;
    for (int i = 0 ; i < n ; i++) {
        if (a[i] + n >= one)
            ans++;
    }
    printf("%d", ans);
















  return 0;
}
