#include <bits/stdc++.h>
#define inf 1e17

using namespace std;

long long pos[101];
long long dp[101][101][2];
int n, start;


long long go(int left, int right, int isRight) {
	if (left == 1 && right == n) return 0;
	long long&ret = dp[left][right][isRight];
	if (ret != -1)
		return ret;

	ret = inf;
	long long remain = n - (right - left + 1);
	if (left > 1) {
		if (isRight) {
			ret = min(ret, go(left-1, right, 0) + remain*(pos[right] - pos[left-1]));
		}
		else {
			ret = min(ret, go(left - 1, right, 0) + remain*(pos[left] - pos[left-1]));
		}
	}
	if (right < n) {
		if (isRight) {
			ret = min(ret, go(left, right+1, 1) + remain*(pos[right+1] - pos[right]));
		}
		else {
			ret = min(ret, go(left, right+1, 1) + remain*(pos[right+1] - pos[left]));
		}
	}
	return ret;

}


int main() {
	int testcase;
	//printf("파이팅!!");
	cin >> testcase;
	while(testcase--) {
		cin >> n >> start;
		memset(dp, -1, sizeof(dp));
		memset(pos, 0, sizeof(pos));
		for (int i = 2 ; i <= n ; i++) {
			long long a;
			cin >> a;
			pos[i] = pos[i-1] + a;
		}
		printf("%lld\n", go(start, start, 0));

	}
	return 0;
}