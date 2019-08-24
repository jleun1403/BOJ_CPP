#include <bits/stdc++.h>
#define mod 1000000000

using namespace std;
long long a[1000];
long long b[1000];
bool over1 = false;
bool over2 = false;

long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
	int n, m;
	cin >> n;
	for (int i = 0 ;i < n ; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0 ; i < m ; i++) 
		cin >> b[i];
	long long max_gcd_for_n = 1;

	for (int i = 0 ; i < n ; i++) {
		long long target = a[i];
		long long max_gcd = 1LL;
		for (int j = 0 ; j < m ; j++) {
			long long temp = gcd(target, b[j]);
			max_gcd *= temp;
			target /= temp;
			b[j] /= temp;
			if (target == 1)
				break;
		}
		max_gcd_for_n *= max_gcd;
		if (max_gcd_for_n >= mod) {
			over1 = true;
			max_gcd_for_n %= mod;
		}
	}
	max_gcd_for_n %= mod;
	if(over1) {
		string temp = to_string(max_gcd_for_n);
		for (int i = 0 ; i < 9 - temp.length() ; i++)
			printf("0");
	}
	printf("%lld\n", max_gcd_for_n);
	return 0;
}