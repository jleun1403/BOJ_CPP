#include <bits/stdc++.h>

using namespace std;

long long dp[501][501];
vector<pair<int, int>> v(501);

long long go(int left, int right) {
	if (left == right) {
		return 0;
	}
	if (dp[left][right] != -1) {
		return dp[left][right];
	}
	long long ret = 1e18;
	for (int i = left ; i < right ; i++) {
		ret = min(ret, go(left, i) + go(i+1, right) + v[left].first * v[i].second * v[right].second);
	}
	return dp[left][right] = ret;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		int a, b;
		cin >> a >> b;
		v[i].first = a;
		v[i].second = b;
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(1, n));
	return 0;
}