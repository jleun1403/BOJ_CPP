#include <bits/stdc++.h>

using namespace std;

long long fib[46];

int main() {
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2 ; i <= 45 ; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}
	int k;
	scanf("%d", &k);
	printf("%lld %lld\n", fib[k-1], fib[k]);
	return 0;
}