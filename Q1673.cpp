#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, k;
	while(scanf("%lld %lld", &n, &k) == 2)	 {
        long long answer = n;
        long long stamp = n;
        while(stamp / k > 0) {
            answer += stamp / k;
            stamp = stamp / k + stamp % k;

        }
        printf("%lld\n", answer);
    }
    return 0;
}