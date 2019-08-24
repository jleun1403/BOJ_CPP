#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, k;
vector<string> v(15);
int remainders[15];

int mypow(int x, int y) {
	if (y == 0) return 1;
	if (y == 1) return x % k;
	if (y%2) {
		int temp = mypow(x, y-1) % k;
		return (temp * x) % k;
	}
	else {
		int temp = mypow(x, y/2) % k;
		return (temp * temp) % k;
	}
}

int bit_count(int x) {
	int ret = 0;
	for (int i = 0 ; i < 25; i++) {
		if (x & (1<<i))
			ret++;
	}
	return ret;
}

long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int remainder(string &s1) {
	//string s = to_string(current) + s1;
	int ret = 0;
	for (int i = 0 ; i < s1.length() ; i++) {
		ret = (ret * 10 + s1[i] - '0') % k;
	}
	return ret;
}

long long dp[100][(1<<15)];

long long go(int rem, int state) {
	if (bit_count(state) == n)
		return rem == 0;

	long long ret = dp[rem][state];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0 ; i < n ; i++) {
		if (!(state & (1<<i))) {
			int newrem = (rem * mypow(10, v[i].length())) % k;
			newrem += remainders[i];
			newrem %= k;
			ret += go(newrem, state | (1<<i));
		}
	}
	return dp[rem][state] = ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		string s;
		cin >> s;
		v[i] = s;
	}
	long long every = 1;
	for (int i = 1 ; i<= n ; i++) {
		every *= (long long)i;
	}
	cin >> k;

	for (int i = 0 ; i < n ;i ++) {
		remainders[i] = remainder(v[i]);
	}

	memset(dp, -1, sizeof(dp));
	long long ans = go(0, 0);
	long long g = gcd(ans, every);
	printf("%lld/%lld\n", ans / g, every / g);

	return 0;
}