#include <bits/stdc++.h>
#define inf 1500000000
using namespace std;
long long dp[201][201];

void print_answer(int a, int z, int k) {
	if (a == 0) {
		for (int i = 0 ; i < z ; i++)
			printf("z");
		return;
	}
	else if (z == 0) {
		for (int i = 0 ; i < a ; i++) {
			printf("a");
		}
		return;
	}
	if (dp[a+z-1][a-1] >= k) {
		printf("a");
		print_answer(a-1, z, k);
	}
	else {
		printf("z");
		print_answer(a, z-1, k - dp[a+z-1][a-1]);
	}
}

int main() {
	for (int i = 1 ; i <= 200 ; i++) {
		dp[i][0] = 1LL;
		dp[i][i] = 1LL;
		for (int j = 1 ; j < i ; j++) {
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			if (dp[i][j] > inf)
				dp[i][j] = inf;
		}
	}
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	if (dp[n+m][n] < k) {
		printf("-1");
		return 0;
	}
	print_answer(n, m, k);
	return 0;
}