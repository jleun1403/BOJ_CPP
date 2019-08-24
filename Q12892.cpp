#include <bits/stdc++.h>

using namespace std;
vector<pair<long long, long long>> v;
long long sum[100001];

int main() {
	long long n, m;
	cin >> n >> m;
	for (int i = 0 ;i < n ;i++) {
		long long a, b;
		cin >> a>> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	for (int i = 0 ; i < n ; i++) {
		sum[i+1] = sum[i] + v[i].second;
	}
	long long ans = 0;
	for (int i = 0 ; i < n ; i++) {
		//long long current = v[i].second;
		auto p = lower_bound(v.begin(), v.end(), make_pair(v[i].first + m, (long long)-1));
		p--;
		int index_ = p - v.begin();
		ans = max(ans, sum[index_ + 1] - sum[i]);
	}
	cout << ans << '\n';
	return 0;
}