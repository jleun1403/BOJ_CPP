#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int a[100000];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }
    int ans = -inf;
    for (int i = 0 ; i < n ; i++) {
        for (int j = i+1 ; j < n ; j++) {
            ans = max(ans, a[i]^a[j]);
        }
    }
    printf("%d", ans);















  return 0;
}
