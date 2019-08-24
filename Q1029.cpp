#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[(1 << 15)][16][10]; // dp[state][last person][price]
int a[16][16];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	memset(dp, 0, sizeof(dp));
	dp[1][1][0] = 1;
	for (int s = 1; s < (1 << n); s++) {
		for (int i = 1; i <= n; i++) {
			if (s & (1 << (i-1))) {
				for (int j = 1; j <= n; j++) {
					if (i == j)
						continue;
					if (!(s &(1 << (j-1)))) {
						for (int k = 0; k <= 9; k++) {
							if (a[i][j] >= k && dp[s][i][k]) {
								dp[s | (1 << (j-1))][j][a[i][j]] = dp[s][i][k] + 1;
							}
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int s = 1; s <= (1 << n); s++) {
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k < 10; k++) {
				ans = max(ans, dp[s][i][k]);
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}