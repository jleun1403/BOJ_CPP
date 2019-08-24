#include <bits/stdc++.h>

using namespace std;
// dp[left][right][stage];
int dp[21][21][20];
int a[20];
int n, m;

int go(int left, int right, int cur) {
	if (cur == m)
		return 0;
	if (dp[left][right][cur] != -1)
		return dp[left][right][cur];
	int &ret = dp[left][right][cur];
	int target = a[cur];
	if (left == target || right == target) {
		ret = go(left, right, cur + 1);
	}
	else {
		if (target > right) {
			ret = go(left, target, cur + 1) + target - right;
		}
		else if (target < left) {
			ret = go(target, right, cur + 1) + left - target;
		}
		else {
			ret = min(go(left, target, cur+1) + right - target, go(target, right, cur+1) + target - left);
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	int x, y;
	scanf("%d %d", &x, &y);
	if (x > y)
		swap(x, y);
	scanf("%d" ,&m);
	for (int i = 0 ; i < m ; i++) {
		scanf("%d", &a[i]);
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(x, y, 0));

	return 0;
}