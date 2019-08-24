#include <bits/stdc++.h>
#define inf 1e15

using namespace std;
long long dp[500][500];
vector<pair<long long, long long >> v;

long long go(long long left, long long right) {
	if (left == right) return 0;
	if (dp[left][right] != -1)
		return dp[left][right];

	long long answer = inf;
	for (int mid = left ; mid < right;  mid++) {
		answer = min(answer, go(left, mid) + go(mid+1, right) + 
			v[left].first * v[mid].second * v[right].second);
	}
	return dp[left][right] = answer;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0 ; i < n ;i++) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		v.push_back(make_pair(a, b));
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(0, n-1));
	return 0;
}