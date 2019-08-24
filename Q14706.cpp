#include <bits/stdc++.h>
#define small 1e18

using namespace std;
long long dp[2000001];
int n, m;
int main() {
	scanf("%d %d", &n, &m);
	long long f = small;
	vector<pair<int, int>> v;
	for (int i = 0 ; i< m ;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a, b));
		f = min(f, (long long)b);
	}

	printf("%d\n", f);
	dp[1] = (long long)f;
	for (int i = 2 ; i <= n ; i++) {
		dp[i] = small;
		for (int k = 0 ; k < m ; k++) {
			
			if (v[k].first >= i && v[k].second < dp[i]) {
				dp[i] = v[k].second;
				//printf("here :  %d %d %d\n",i,  v[k].first, v[k].second);
			}
			else if (v[k].first < i) {
				if (dp[i - v[k].first] + dp[v[k].first] < dp[i] )
					dp[i] = dp[i - v[k].first] + dp[v[k].first];
			}
		}
		printf("%lld\n", dp[i]);
	}

	return 0;
}