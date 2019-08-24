#include <bits/stdc++.h>

using namespace std;
long long dp[31][31];

int main() {

	for (int i = 1 ;  i <= 30 ; i++) {
		dp[i][0] = 1LL;
		dp[i][i] = 1LL;
		for (int j = 1 ; j < i ; j++) {
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}

	int n, m, k;
	scanf("%d %d %d",&n, &m, &k);
	if (k == 0 ) {
		printf("%lld\n", dp[n+m-2][m-1]);
		return 0;
	}
	k--;
	int row = k / m;
	int col = k % m;


	printf("%lld\n", dp[row+col][col] * dp[m+n-2-col-row][m-col-1]);

	return 0;
}