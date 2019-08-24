#include <bits/stdc++.h>

using namespace std;
int a[1000];
int dp[1000][1000][2];

int go(int left, int right, int turn) {
	if (left == right) {
		if (turn == 0)
			return a[left];
		else return 0;
	}
	int &ret = dp[left][right][turn];
	if (ret != -1)
		return ret;
	if (turn == 0) {
		ret = max(a[left] + go(left+1, right, 1), a[right] + go(left, right-1, 1));
	}
	else ret = min(go(left+1, right, 0), go(left, right-1, 0));
	return ret;
}

int main() {
	int testcase;
	cin >> testcase;
	while(testcase--) {
		int n;
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(dp, -1, sizeof(dp));
		for (int i = 0 ; i < n ; i++) {
			cin >> a[i];
		}
		printf("%d\n", go(0, n-1, 0));
	}

	return 0;
}