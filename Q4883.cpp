#include <bits/stdc++.h>
#define inf 987654321

using namespace std;
int a[100000][3];
int dp[100000][3];

int main() {
	int testcase = 0;
	while(true) {
		testcase++;
		memset(dp , 0, sizeof(dp));
		int n;
		scanf("%d" , &n);
		if (n == 0)
			break;
		for (int i = 0 ; i < n ; i++) {
			scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
		}
		dp[0][0] = inf;
		dp[0][1] = a[0][1];
		dp[0][2] = a[0][1] + a[0][2];
		for (int i = 1 ; i < n ; i++) {
			dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i][0];
			dp[i][1] = min(min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]), dp[i][0]) + a[i][1];
			dp[i][2] = min( min(dp[i-1][1], dp[i-1][2]), dp[i][1]) + a[i][2];
		}
		printf("%d. %d\n", testcase, dp[n-1][1]);
	}

	return 0;
}