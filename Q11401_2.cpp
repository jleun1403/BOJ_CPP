#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
int n, k;
long long fact[4000001];

long long mypow(long long a, long long b) {
	if (b == 0) return 1LL;
	if (b == 1) return a;
	if (b%2) {
		long long temp = mypow(a, b-1) % mod;
		return (temp * a) % mod;
	}
	else {
		long long temp = mypow(a, b/2) % mod;
		return (temp * temp) % mod;
	}
}


int main() {
	fact[0] = 1LL;
	for (int i = 1 ; i <= 4000000 ; i++) {
		fact[i] = fact[i-1]*i;
		fact[i] %= mod;
	}

	cin >> n >> k;
	long long up = fact[n];
	long long down = (fact[k] * fact[n-k]) % mod;
	cout << (up * mypow(down, mod-2)) % mod << '\n';

	return 0;
}