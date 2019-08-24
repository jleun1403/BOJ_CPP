#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int dp[2001][2001];
int n;

//[first][second]로 시작하는 등차수열의 최대 개수;
int solve(int first, int second) {
	if (first >= n || second >= n)
		return 0;
	int &ret = dp[first][second];
	if (ret != -1)
		return ret;
	ret = 2;
	int diff = a[second] - a[first];
	auto p = lower_bound(a.begin()+second + 1, a.end(), a[second] + diff);
	if (p != a.end() && (*p) == a[second]+diff) {
		ret = solve(second, p - a.begin()) + 1;
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0 , p; i < n ; i++) {
		cin >> p;
		a.push_back(p);
	}
	sort(a.begin(), a.end());
	memset(dp, -1, sizeof(dp));
	int ans = 1;
	for (int i = 0 ; i < n ; i++) {
		for (int j = i+1 ; j < n ; j++) {
			ans = max(ans, solve(i, j));
		}
	}
	cout << ans << '\n';
	return 0;
}