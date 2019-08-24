#include <bits/stdc++.h>

using namespace std;
int testcase, n;
double dp[512][512];
vector<pair<int, int>> v;

double dist(int a, int b) {
	auto p = v[a];
	auto q = v[b];
	return sqrt((p.first - q.first)*(p.first - q.first)  + (p.second - q.second)*(p.second - q.second));
}

double go(int a, int b) {
	if (a == n-1) {
		return dist(b, n-1);
	}
	else if (b == n-1) {
		return dist(a, n-1);
	}
	if (dp[a][b] != -1)
		return dp[a][b];
	double &ret = dp[a][b];
	int next = max(a, b) + 1;
	ret = min(go(next, b) + dist(a, next), go(a, next) + dist(b, next));
	return ret;
}

int main() {
	cin >> testcase;
	while(testcase--) {
		cin >> n;
		for (int i = 0 ; i < n ; i++) {
			int a, b;
			cin >> a>> b;
			v.push_back(make_pair(a, b));
		}
		for (int i = 0 ; i < 512 ; i++) {
			for (int j = 0 ; j < 512 ; j++) {
				dp[i][j] = -1;
			}
		}
		cout << go(0, 0) << '\n';
		v.clear();
	}
	return 0;
}