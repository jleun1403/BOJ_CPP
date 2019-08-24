#include <bits/stdc++.h>
#define inf 987654321

using namespace std;

int main() {
    long long a, b, r;
    scanf("%lld %lld %lld", &a, &b, &r);
    if (a == 0LL || b == 0LL) {
        printf("0");
        return 0;
    }
    if (a < 0LL  || to_string(a).length() > 19 || b < 0LL || to_string(b) .length() > 19) {
        printf("overflow");
        return 0;
    }
    if (a * b < 0LL || to_string(a).length()+ to_string(b).length() > 19)
        printf("overflow");
    else {
        if (a * b > r) {
            printf("%lld", a*b);
            printf("3overflow");
        }
        else printf("%lld", a*b);
    }














  return 0;
}
