#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int dp[301][(1<<18)];
int n, m;

int go(int current, int state) {
	if (current >= n * m)
		return 1;
	state %= (1 << (m+1));
	int &ret = dp[current][state];
	if (ret != -1)
		return ret;
	ret = 0;
	int row = current / m;
	int col = current % m;
	if (row == 0) {
		ret = go(current + 1, (state << 1)) + go(current + 1, (state << 1) | 1);
	}
	else {
		if (col == 0) {
			ret = go(current + 1, (state << 1)) + go(current + 1, (state << 1) | 1);
		}
		else {
			if ((state & (1<<m)) && (state & (1<<(m-1)))  && (state & (1))) {
				ret = go(current + 1, state << 1);
			}
			else ret = go(current + 1, (state << 1)) + go(current + 1, (state << 1) | 1);
		}
	}
	return ret %= mod;
}

int main() {
	cin >> n >> m;
	if (m > n)
		swap(n, m);
	 /*if (m == 1) {
		printf("%d\n", (1<<n));
		return 0;
	}
	*/
	memset(dp , - 1, sizeof(dp));
	printf("%d\n", go(0, 0));

	return 0;
}