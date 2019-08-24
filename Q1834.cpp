#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i < n ; i++) {
        int a = (long long)n*i + i;
        ans += (long long)a;
    }
    printf("%lld", ans);
}
