#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int l, n, m;
int a[3001];
int b[3001];
int asum[3001];
int bsum[3001];
vector<int> same;
long long dp[6001][6001];



int main() {
	dp[0][0] = 1LL;
	for (int i = 1 ; i <= 6000 ; i++) {
		dp[i][0] = 1LL;
		dp[i][i] = 1LL;
		for (int j = 1 ; j < i ; j++) {
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
		}
	}

	cin >> l;
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}

	for (int i = 1 ; i <= n ; i++) {
		asum[i] = asum[i-1] + a[i];
	}
	cin >> m;
	for (int i = 1 ; i <= m ; i++) {
		cin >> b[i];
	}

	for (int i = 1 ; i <= m ; i++) {
		bsum[i] = bsum[i-1] + b[i];
	}
	//same.push_back(0);
	for (int i = 0 ; i <= l ; i++) {
		if (binary_search(asum, asum+n+1, i) && binary_search(bsum, bsum+m+1, i)) {
			same.push_back(i);
		}
	}
	int split = 0;
	int merge = 0;
	for (int i = 1 ; i < same.size() ; i++) {
		int start = same[i-1];
		int fin = same[i];
		int diff = fin - start;

		auto p = lower_bound(asum, asum+n+1, start);
		auto q = lower_bound(asum, asum+n+1 , fin);

		split += diff - (q - p);
		p = lower_bound(bsum, bsum+m + 1, start);
		q = lower_bound(bsum, bsum+m + 1, fin);
		merge += diff - (q - p);
		//printf("%d %d\n", split, merge);
	}

	printf("%d %lld\n", split+merge, dp[split+merge][merge]);
	return 0;
}