#include <bits/stdc++.h>

using namespace std;
long long dp[1001];

long long get_answer(int k) {
	if (k == 0)
		return 1;
	if (dp[k] != -1) return dp[k];
	long long ret = 0;
	for (int i = 0 ; i <= k/2 ; i++) {
		ret += get_answer(i);
	}
	//ret += 1;
	return dp[k] = ret;
}

int main() {
	int testcase;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &testcase);
	for (int i = 0 ; i < testcase ; i++) {
		int k;
		cin >> k;
		printf("%lld\n", get_answer(k));
	}
	return 0;
}